import math
import os
import yaml

import rclpy
from rclpy.node import Node
from frob_interfaces.msg import SignDetection
from nav_msgs.msg import Odometry
from std_msgs.msg import Int32MultiArray
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Point
from std_msgs.msg import ColorRGBA
from ament_index_python.packages import get_package_share_directory


COLOR = {
    'start':       ColorRGBA(r=0.0, g=0.0, b=1.0, a=1.0),
    'target':      ColorRGBA(r=1.0, g=0.0, b=0.0, a=1.0),
    'path_node':   ColorRGBA(r=1.0, g=0.8, b=0.0, a=0.9),
    'regular_node':ColorRGBA(r=0.0, g=1.0, b=0.0, a=0.4),
    'path_edge':   ColorRGBA(r=1.0, g=0.8, b=0.0, a=0.9),
    'regular_edge':ColorRGBA(r=0.5, g=0.5, b=0.5, a=0.3),
    'robot':       ColorRGBA(r=1.0, g=0.0, b=1.0, a=0.8),
    'blocked_edge':ColorRGBA(r=1.0, g=0.0, b=0.0, a=0.7),
}


class GraphVisualizer(Node):
    def __init__(self):
        super().__init__('graph_visualizer')

        self.declare_parameter('graph_file', '')
        self.declare_parameter('publish_rate', 1.0)
        self.declare_parameter('frame_id', 'odom')

        graph_file = self.get_parameter('graph_file').value
        if not graph_file:
            pkg_dir = get_package_share_directory('frob_mission')
            graph_file = os.path.join(pkg_dir, 'config', 'graph.yaml')

        with open(graph_file) as f:
            config = yaml.safe_load(f)

        self.nodes = {}
        self.edges = {}

        for node_id, entry in config['nodes'].items():
            nid = int(node_id)
            self.nodes[nid] = (entry['x'], entry['y'])
            self.edges[nid] = []
            for cmd in ('forward', 'right_turn', 'left_turn', 'u_turn'):
                targets = entry.get(cmd, [])
                if targets is None:
                    targets = []
                for t in targets:
                    tid = t['node'] if isinstance(t, dict) else int(t)
                    self.edges[nid].append(tid)

        self.publish_rate = self.get_parameter('publish_rate').value
        self.frame_id = self.get_parameter('frame_id').value

        self.path = None
        self.current_odom = None
        self.blocked_edges = set()

        self.marker_pub = self.create_publisher(MarkerArray, '/graph_markers', 10)

        self.path_sub = self.create_subscription(
            Int32MultiArray, '/path', self.path_callback, 10)

        self.sign_sub = self.create_subscription(
            SignDetection, '/sign_detected', self.sign_callback, 10)

        self.odom_sub = self.create_subscription(
            Odometry, '/odometry/filtered', self.odom_callback, 10)

        self.timer = self.create_timer(1.0 / self.publish_rate, self.publish_markers)

        edge_count = sum(len(v) for v in self.edges.values())
        self.get_logger().info(
            f'Loaded {len(self.nodes)} nodes, {edge_count} edges'
        )

    def path_callback(self, msg):
        new_path = list(msg.data)
        if new_path != self.path:
            self.path = new_path
            self.get_logger().info(
                f'Path received: {" -> ".join(str(n) for n in self.path)}'
            )

    def odom_callback(self, msg):
        self.current_odom = msg

    def sign_callback(self, msg):
        if not msg.detected:
            return
        self.get_logger().info(f'Sign detected: type={msg.sign_type}')

    def publish_markers(self):
        path_set = set(self.path) if self.path else set()
        path_edges = set()
        if self.path:
            for i in range(len(self.path) - 1):
                path_edges.add((self.path[i], self.path[i + 1]))

        start_id = self.path[0] if self.path else None
        target_id = self.path[-1] if self.path else None

        marker_array = MarkerArray()
        stamp = self.get_clock().now().to_msg()

        self._add_node_markers(marker_array, stamp, path_set, start_id, target_id)
        self._add_label_markers(marker_array, stamp, path_set, start_id, target_id)
        self._add_edge_markers(marker_array, stamp, path_edges)
        self._add_robot_marker(marker_array, stamp)

        self.marker_pub.publish(marker_array)

    def _add_node_markers(self, array, stamp, path_set, start_id, target_id):
        for node_id, (x, y) in self.nodes.items():
            marker = Marker()
            marker.header.frame_id = self.frame_id
            marker.header.stamp = stamp
            marker.ns = 'nodes'
            marker.id = node_id
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD

            marker.pose.position.x = x
            marker.pose.position.y = y
            marker.pose.position.z = 0.02

            s = 0.06
            marker.scale.x = s
            marker.scale.y = s
            marker.scale.z = s

            if node_id == start_id:
                marker.color = COLOR['start']
            elif node_id == target_id:
                marker.color = COLOR['target']
            elif node_id in path_set:
                marker.color = COLOR['path_node']
            else:
                marker.color = COLOR['regular_node']

            array.markers.append(marker)

    def _add_label_markers(self, array, stamp, path_set, start_id, target_id):
        for node_id, (x, y) in self.nodes.items():
            marker = Marker()
            marker.header.frame_id = self.frame_id
            marker.header.stamp = stamp
            marker.ns = 'labels'
            marker.id = node_id
            marker.type = Marker.TEXT_VIEW_FACING
            marker.action = Marker.ADD

            marker.pose.position.x = x
            marker.pose.position.y = y
            marker.pose.position.z = 0.09
            marker.scale.z = 0.07

            marker.text = str(node_id)

            if node_id == start_id:
                marker.color = COLOR['start']
            elif node_id == target_id:
                marker.color = COLOR['target']
            elif node_id in path_set:
                marker.color = COLOR['path_node']
            else:
                marker.color = ColorRGBA(r=1.0, g=1.0, b=1.0, a=0.5)

            array.markers.append(marker)

    def _add_edge_markers(self, array, stamp, path_edges):
        next_id = 1000
        for src, dsts in self.edges.items():
            for dst in dsts:
                sx, sy = self.nodes[src]
                dx, dy = self.nodes[dst]

                marker = Marker()
                marker.header.frame_id = self.frame_id
                marker.header.stamp = stamp
                marker.ns = 'edges'
                marker.id = next_id
                next_id += 1
                marker.type = Marker.ARROW
                marker.action = Marker.ADD

                marker.points = [
                    Point(x=sx, y=sy, z=0.01),
                    Point(x=dx, y=dy, z=0.01),
                ]

                marker.scale.x = 0.01
                marker.scale.y = 0.02
                marker.scale.z = 0.03

                if (src, dst) in self.blocked_edges:
                    marker.color = COLOR['blocked_edge']
                elif (src, dst) in path_edges:
                    marker.color = COLOR['path_edge']
                else:
                    marker.color = COLOR['regular_edge']

                array.markers.append(marker)

    def _add_robot_marker(self, array, stamp):
        if self.current_odom is None:
            return

        marker = Marker()
        marker.header.frame_id = self.frame_id
        marker.header.stamp = stamp
        marker.ns = 'robot'
        marker.id = 0
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD

        pos = self.current_odom.pose.pose.position
        marker.pose.position.x = pos.x
        marker.pose.position.y = pos.y
        marker.pose.position.z = 0.03

        s = 0.08
        marker.scale.x = s
        marker.scale.y = s
        marker.scale.z = s

        marker.color = COLOR['robot']
        array.markers.append(marker)


def main(args=None):
    rclpy.init(args=args)
    node = GraphVisualizer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
