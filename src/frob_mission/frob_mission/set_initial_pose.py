import math
import os
import subprocess
import time

import yaml
import rclpy
from rclpy.node import Node
from ament_index_python.packages import get_package_share_directory


class SetInitialPose(Node):
    def __init__(self):
        super().__init__('set_initial_pose')

        self.declare_parameter('start_node', 23)
        start_node = self.get_parameter('start_node').value

        pkg_dir = get_package_share_directory('frob_mission')
        graph_file = os.path.join(pkg_dir, 'config', 'graph.yaml')

        with open(graph_file) as f:
            config = yaml.safe_load(f)

        node_data = config['nodes'].get(start_node)
        if node_data is None:
            self.get_logger().error(f'Node {start_node} not found in graph')
            return

        self._x = node_data['x']
        self._y = node_data['y']
        self._heading = node_data.get('suggested_heading', 0.0)
        self._retry_count = 0
        self._max_retries = 30
        self._timer = None

        self.get_logger().info(
            f'Will teleport to node {start_node}: '
            f'({self._x:.3f}, {self._y:.3f}), '
            f'heading={math.degrees(self._heading):.1f}°'
        )

        self._try_teleport()

    def _try_teleport(self):
        self._retry_count += 1
        if self._retry_count > self._max_retries:
            self.get_logger().error(f'Failed after {self._max_retries} retries')
            return

        cy = math.cos(self._heading / 2)
        sy = math.sin(self._heading / 2)

        req = (
            f'name: "turtlebot4", '
            f'position: {{x: {self._x}, y: {self._y}, z: 0.01}}, '
            f'orientation: {{x: 0.0, y: 0.0, z: {sy}, w: {cy}}}'
        )

        try:
            result = subprocess.run(
                ['gz', 'service', '-s', '/world/city_polygon/set_pose',
                 '--reqtype', 'gz.msgs.Pose',
                 '--reptype', 'gz.msgs.Boolean',
                 '--timeout', '3000',
                 '--req', req],
                capture_output=True, text=True, timeout=10,
            )
            if result.returncode == 0 and 'data: true' in result.stdout:
                self.get_logger().info(
                    f'Robot teleported to ({self._x:.3f}, {self._y:.3f}), '
                    f'heading={math.degrees(self._heading):.1f}°'
                )
                return
            else:
                err = result.stderr.strip() or result.stdout.strip()
                self.get_logger().warn(
                    f'Attempt {self._retry_count}/{self._max_retries}: '
                    f'{err}')
        except subprocess.TimeoutExpired:
            self.get_logger().warn(
                f'Attempt {self._retry_count}/{self._max_retries}: timeout')
        except Exception as e:
            self.get_logger().warn(
                f'Attempt {self._retry_count}/{self._max_retries}: {e}')

        self._timer = self.create_timer(2.0, self._on_retry)

    def _on_retry(self):
        self._timer.cancel()
        self._timer = None
        self._try_teleport()


def main(args=None):
    rclpy.init(args=args)
    node = SetInitialPose()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
