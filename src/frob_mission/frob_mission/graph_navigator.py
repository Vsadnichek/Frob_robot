import math
import os
import heapq
import yaml

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from frob_interfaces.action import ExecuteMotion
from std_msgs.msg import Int32MultiArray
from ament_index_python.packages import get_package_share_directory


class GraphNavigator(Node):
    def __init__(self):
        super().__init__('graph_navigator')

        self.declare_parameter('graph_file', '')
        self.declare_parameter('start_node', -1)
        self.declare_parameter('target_node', -1)
        self.declare_parameter('initial_heading', 0.0)
        self.declare_parameter('turn_threshold', 0.08)
        self.declare_parameter('execute', True)

        graph_file = self.get_parameter('graph_file').value
        if not graph_file:
            pkg_dir = get_package_share_directory('frob_mission')
            graph_file = os.path.join(pkg_dir, 'config', 'graph.yaml')

        start_node = self.get_parameter('start_node').value
        target_node = self.get_parameter('target_node').value
        self.initial_heading = self.get_parameter('initial_heading').value
        self.turn_threshold = self.get_parameter('turn_threshold').value
        self.execute = self.get_parameter('execute').value

        with open(graph_file) as f:
            config = yaml.safe_load(f)

        self.nodes = {}
        for node_id, coords in config['nodes'].items():
            self.nodes[int(node_id)] = (coords['x'], coords['y'])

        self.edges = {}
        for src, dst in config['edges']:
            s, d = int(src), int(dst)
            if s not in self.edges:
                self.edges[s] = []
            self.edges[s].append(d)

        if start_node < 0:
            start_node = config.get('start_node', 13)
        if target_node < 0:
            target_node = config.get('target_node', 108)

        self.start_node = start_node
        self.target_node = target_node

        self.get_logger().info(
            f'Graph loaded: {len(self.nodes)} nodes, '
            f'{sum(len(v) for v in self.edges.values())} edges'
        )
        self.get_logger().info(
            f'Start: {self.start_node}, Target: {self.target_node}, '
            f'Execute: {self.execute}'
        )

        self.path_pub = self.create_publisher(Int32MultiArray, '/path', 10)

        self._planned_path = None
        self._planned_commands = None

        self._plan_and_publish()

        if not self._planned_path:
            self.get_logger().error('No path found — aborting')
            return

        if not self.execute:
            self.get_logger().info('Planning-only mode: path published. Spinning...')
            return

        self._action_client = ActionClient(
            self, ExecuteMotion, 'execute_motion',
            callback_group=MutuallyExclusiveCallbackGroup()
        )

        self.get_logger().info('Waiting for motion_executor action server...')
        while not self._action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info('Still waiting for motion_executor...')
        self.get_logger().info('Action server connected')

        self._execute_mission()

    def _plan_and_publish(self):
        blocked_edges = set()
        path = self.dijkstra(self.start_node, self.target_node, blocked_edges)

        if not path:
            self.get_logger().error(
                f'No path from {self.start_node} to {self.target_node}'
            )
            return

        path_str = ' -> '.join(str(n) for n in path)
        self.get_logger().info(f'Path ({len(path)} nodes): {path_str}')

        msg = Int32MultiArray()
        msg.data = [int(n) for n in path]
        self.path_pub.publish(msg)

        if len(path) >= 2:
            ax, ay = self.nodes[path[0]]
            bx, by = self.nodes[path[1]]
            self.initial_heading = math.atan2(by - ay, bx - ax)
            self.get_logger().info(
                f'Auto initial_heading={self.initial_heading:.3f} rad '
                f'(from first edge {path[0]}->{path[1]})'
            )

        commands = self._plan_motion(path)
        cmd_str = ', '.join(
            f'{c}({round(v, 3)})' for c, v in commands
        )
        self.get_logger().info(f'Commands ({len(commands)}): {cmd_str}')

        self._planned_path = path
        self._planned_commands = commands

    def dijkstra(self, start, target, blocked_edges=None):
        if blocked_edges is None:
            blocked_edges = set()

        dist = {start: 0.0}
        prev = {}
        pq = [(0.0, start)]

        while pq:
            d, u = heapq.heappop(pq)
            if d > dist.get(u, float('inf')):
                continue
            if u == target:
                break

            for v in self.edges.get(u, []):
                if (u, v) in blocked_edges:
                    continue
                ux, uy = self.nodes[u]
                vx, vy = self.nodes[v]
                w = math.sqrt((vx - ux) ** 2 + (vy - uy) ** 2)
                nd = d + w
                if nd < dist.get(v, float('inf')):
                    dist[v] = nd
                    prev[v] = u
                    heapq.heappush(pq, (nd, v))

        if target not in prev and start != target:
            return None

        path = []
        node = target
        while node != start:
            path.append(node)
            node = prev[node]
        path.append(start)
        path.reverse()
        return path

    def _plan_motion(self, path):
        commands = []
        heading = self.initial_heading

        for i in range(len(path) - 1):
            a = path[i]
            b = path[i + 1]
            ax, ay = self.nodes[a]
            bx, by = self.nodes[b]

            dx = bx - ax
            dy = by - ay
            edge_angle = math.atan2(dy, dx)

            cos_h = math.cos(heading)
            sin_h = math.sin(heading)
            dx_local = dx * sin_h - dy * cos_h
            dy_local = dx * cos_h + dy * sin_h

            rel = self._normalize(heading - edge_angle)

            cmd, val = self._classify_command(rel, dx_local, dy_local, dx, dy)
            commands.append((cmd, val))

            if cmd == 'forward':
                pass
            elif cmd == 'right_turn':
                heading = self._normalize(heading - math.pi / 2)
            elif cmd == 'left_turn':
                heading = self._normalize(heading + math.pi / 2)
            elif cmd == 'u_turn':
                heading = self._normalize(heading + math.pi)

        return commands

    def _classify_command(self, rel, dx_local, dy_local, dx, dy):
        rel_deg = math.degrees(rel)

        if -30.0 <= rel_deg <= 30.0:
            dist = math.sqrt(dx * dx + dy * dy)
            return ('forward', dist)

        if -105.0 <= rel_deg <= -75.0 and abs(dy_local) < 1e-6:
            r = abs(dx_local)
            return ('u_turn', r)

        if 30.0 <= rel_deg <= 150.0:
            r = abs(dx_local)
            return ('right_turn', r)

        if -150.0 <= rel_deg <= -30.0:
            r = abs(dx_local)
            return ('left_turn', r)

        dist = math.sqrt(dx * dx + dy * dy)
        return ('forward', dist)

    def _execute_mission(self):
        if not self._planned_commands:
            self.get_logger().error('No planned commands to execute')
            return

        for i, (cmd, val) in enumerate(self._planned_commands):
            self.get_logger().info(
                f'Step {i + 1}/{len(self._planned_commands)}: {cmd}({round(val, 3)})'
            )
            success = self._send_action(cmd, val)
            if not success:
                self.get_logger().error('Motion execution failed')
                return

        self.get_logger().info('MISSION COMPLETE')

    def _send_action(self, command, value):
        goal_msg = ExecuteMotion.Goal()
        goal_msg.command = command
        goal_msg.value = float(value)

        future = self._action_client.send_goal_async(goal_msg)
        rclpy.spin_until_future_complete(self, future)
        goal_handle = future.result()

        if not goal_handle.accepted:
            self.get_logger().error('Goal rejected')
            return False

        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        result = result_future.result()

        if result.result.success:
            self.get_logger().info(f'  {command} completed')
            return True
        else:
            self.get_logger().error(f'  {command} failed')
            return False

    @staticmethod
    def _normalize(angle):
        while angle > math.pi:
            angle -= 2.0 * math.pi
        while angle < -math.pi:
            angle += 2.0 * math.pi
        return angle


def main(args=None):
    rclpy.init(args=args)
    node = GraphNavigator()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
