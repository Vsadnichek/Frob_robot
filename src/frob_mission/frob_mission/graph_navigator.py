import math
import os
import heapq
import yaml

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from frob_interfaces.action import ExecuteMotion
from ament_index_python.packages import get_package_share_directory


class GraphNavigator(Node):
    def __init__(self):
        super().__init__('graph_navigator')

        self.declare_parameter('graph_file', '')
        self.declare_parameter('start_node', -1)
        self.declare_parameter('target_node', -1)
        self.declare_parameter('initial_heading', 0.0)
        self.declare_parameter('turn_threshold', 0.08)

        graph_file = self.get_parameter('graph_file').value
        if not graph_file:
            pkg_dir = get_package_share_directory('frob_mission')
            graph_file = os.path.join(pkg_dir, 'config', 'graph.yaml')

        start_node = self.get_parameter('start_node').value
        target_node = self.get_parameter('target_node').value
        self.initial_heading = self.get_parameter('initial_heading').value
        self.turn_threshold = self.get_parameter('turn_threshold').value

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
        if self.initial_heading == 0.0:
            self.initial_heading = config.get('initial_heading', 0.0)

        self.start_node = start_node
        self.target_node = target_node

        self.get_logger().info(
            f'Graph loaded: {len(self.nodes)} nodes, {sum(len(v) for v in self.edges.values())} edges'
        )
        self.get_logger().info(
            f'Start: {self.start_node}, Target: {self.target_node}, '
            f'Heading: {self.initial_heading:.2f} rad'
        )

        self._action_client = ActionClient(
            self, ExecuteMotion, 'execute_motion',
            callback_group=MutuallyExclusiveCallbackGroup()
        )

        self.get_logger().info('Graph navigator ready. Waiting for action server...')
        while not self._action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().info('Waiting for motion_executor...')
        self.get_logger().info('Action server connected')

        self._execute_mission()

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

    def _execute_mission(self):
        blocked_edges = set()
        path = self.dijkstra(self.start_node, self.target_node, blocked_edges)

        if not path:
            self.get_logger().error('No path found!')
            return

        path_str = ' -> '.join(str(n) for n in path)
        self.get_logger().info(f'Path: {path_str}')

        commands = self._plan_motion(path)
        self.get_logger().info(f'Commands: {[(c, round(v, 3)) for c, v in commands]}')

        current_heading = self.initial_heading
        for i, (cmd, val) in enumerate(commands):
            self.get_logger().info(
                f'Step {i+1}/{len(commands)}: {cmd} {val:.3f}'
            )
            success = self._send_action(cmd, val)
            if not success:
                self.get_logger().error('Motion execution failed')
                return

            if cmd == 'rotate':
                current_heading = self._normalize(current_heading + val)
            elif cmd == 'forward':
                pass

        self.get_logger().info('MISSION COMPLETE')

    def _plan_motion(self, path):
        commands = []
        heading = self.initial_heading

        for i in range(len(path) - 1):
            a = path[i]
            b = path[i + 1]
            ax, ay = self.nodes[a]
            bx, by = self.nodes[b]

            target_angle = math.atan2(by - ay, bx - ax)
            diff = self._normalize(target_angle - heading)

            if abs(diff) > self.turn_threshold:
                commands.append(('rotate', diff))
                heading = target_angle

            distance = math.sqrt((bx - ax) ** 2 + (by - ay) ** 2)
            commands.append(('forward', distance))

        return commands

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
