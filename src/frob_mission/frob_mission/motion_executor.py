import math
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import MutuallyExclusiveCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu
from frob_interfaces.action import ExecuteMotion
import numpy as np


class MotionExecutor(Node):
    def __init__(self):
        super().__init__('motion_executor')

        self.declare_parameter('forward_speed', 0.15)
        self.declare_parameter('rotate_speed', 1.0)
        self.declare_parameter('forward_tolerance', 0.02)
        self.declare_parameter('rotate_tolerance', 0.05)
        self.declare_parameter('kp_angular', 2.0)

        self.forward_speed = self.get_parameter('forward_speed').value
        self.rotate_speed = self.get_parameter('rotate_speed').value
        self.forward_tolerance = self.get_parameter('forward_tolerance').value
        self.rotate_tolerance = self.get_parameter('rotate_tolerance').value
        self.kp_angular = self.get_parameter('kp_angular').value

        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel', 10)

        action_cb_group = MutuallyExclusiveCallbackGroup()
        self._action_server = ActionServer(
            self, ExecuteMotion, 'execute_motion',
            execute_callback=self.execute_callback,
            callback_group=action_cb_group,
        )

        self.odom = None
        self.yaw = 0.0
        self.imu_available = False
        self.yaw_initialized = False

        self.odom_sub = self.create_subscription(
            Odometry, '/odometry/filtered', self.odom_callback, 10)
        self.imu_sub = self.create_subscription(
            Imu, '/imu/mpu6050', self.imu_callback, 10)

        self.get_logger().info('Motion executor ready')

    def _quat_to_yaw(self, q):
        siny = 2.0 * (q.w * q.z + q.x * q.y)
        cosy = 1.0 - 2.0 * (q.y * q.y + q.z * q.z)
        return math.atan2(siny, cosy)

    def odom_callback(self, msg):
        self.odom = msg
        if not self.imu_available:
            self.yaw = self._quat_to_yaw(msg.pose.pose.orientation)

    def imu_callback(self, msg):
        self.yaw = self._quat_to_yaw(msg.orientation)
        self.imu_available = True
        if not self.yaw_initialized:
            self.yaw_initialized = True
            self.get_logger().info('IMU yaw source active')

    def execute_callback(self, goal_handle):
        command = goal_handle.request.command
        value = goal_handle.request.value

        self.get_logger().info(f'Executing: {command} {value:.3f}')

        feedback_msg = ExecuteMotion.Feedback()

        if command == 'forward':
            result = self._execute_forward(value, goal_handle, feedback_msg)
        elif command == 'rotate':
            result = self._execute_rotate(value, goal_handle, feedback_msg)
        else:
            self.get_logger().error(f'Unknown command: {command}')
            goal_handle.abort()
            result = ExecuteMotion.Result()
            result.success = False
            return result

        return result

    def _execute_forward(self, distance, goal_handle, feedback_msg):
        rate = self.create_rate(50)

        while self.odom is None and rclpy.ok():
            self.get_logger().info('Waiting for odometry...', throttle_duration_sec=1.0)
            rate.sleep()

        if not rclpy.ok():
            goal_handle.abort()
            result = ExecuteMotion.Result()
            result.success = False
            return result

        start_x = self.odom.pose.pose.position.x
        start_y = self.odom.pose.pose.position.y

        rate = self.create_rate(50)
        while rclpy.ok():
            if goal_handle.is_cancel_requested:
                self._stop()
                goal_handle.canceled()
                result = ExecuteMotion.Result()
                result.success = False
                return result

            dx = self.odom.pose.pose.position.x - start_x
            dy = self.odom.pose.pose.position.y - start_y
            traveled = math.sqrt(dx * dx + dy * dy)
            remaining = distance - traveled
            feedback_msg.progress = min(1.0, traveled / distance)
            goal_handle.publish_feedback(feedback_msg)

            if traveled >= distance - self.forward_tolerance:
                break

            speed = self.forward_speed
            if remaining < 0.1:
                speed = max(0.05, self.forward_speed * remaining / 0.1)

            twist = Twist()
            twist.linear.x = speed
            self.cmd_vel_pub.publish(twist)
            rate.sleep()

        self._stop()
        goal_handle.succeed()
        result = ExecuteMotion.Result()
        result.success = True
        self.get_logger().info('Forward complete')
        return result

    def _execute_rotate(self, angle, goal_handle, feedback_msg):
        rate = self.create_rate(50)

        while not self.yaw_initialized and rclpy.ok():
            if self.odom is not None:
                self.yaw_initialized = True
                self.get_logger().info('Using odometry for yaw (IMU not available)')
                break
            self.get_logger().info('Waiting for odometry/IMU...', throttle_duration_sec=1.0)
            rate.sleep()

        if not rclpy.ok():
            goal_handle.abort()
            result = ExecuteMotion.Result()
            result.success = False
            return result

        target_yaw = self._normalize(self.yaw + angle)
        rate = self.create_rate(50)

        while rclpy.ok():
            if goal_handle.is_cancel_requested:
                self._stop()
                goal_handle.canceled()
                result = ExecuteMotion.Result()
                result.success = False
                return result

            error = self._normalize(target_yaw - self.yaw)
            progress = 1.0 - abs(error / angle) if abs(angle) > 0.01 else 1.0
            feedback_msg.progress = min(1.0, max(0.0, progress))
            goal_handle.publish_feedback(feedback_msg)

            if abs(error) < self.rotate_tolerance:
                break

            angular = np.clip(self.kp_angular * error,
                              -self.rotate_speed, self.rotate_speed)
            if abs(angular) < 0.1:
                angular = 0.1 * (1 if error > 0 else -1)

            twist = Twist()
            twist.angular.z = angular
            self.cmd_vel_pub.publish(twist)
            rate.sleep()

        self._stop()
        goal_handle.succeed()
        result = ExecuteMotion.Result()
        result.success = True
        self.get_logger().info('Rotate complete')
        return result

    def _stop(self):
        self.cmd_vel_pub.publish(Twist())

    @staticmethod
    def _normalize(angle):
        while angle > math.pi:
            angle -= 2.0 * math.pi
        while angle < -math.pi:
            angle += 2.0 * math.pi
        return angle


def main(args=None):
    rclpy.init(args=args)
    node = MotionExecutor()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
