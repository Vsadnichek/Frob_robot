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


class MotionExecutor(Node):
    def __init__(self):
        super().__init__('motion_executor')

        self.declare_parameter('forward_speed', 0.15)
        self.declare_parameter('rotate_speed', 1.0)
        self.declare_parameter('forward_tolerance', 0.02)
        self.declare_parameter('rotate_tolerance', 0.05)
        self.declare_parameter('kp_angular', 2.0)
        self.declare_parameter('settle_time', 0.3)

        self.forward_speed = self.get_parameter('forward_speed').value
        self.rotate_speed = self.get_parameter('rotate_speed').value
        self.forward_tolerance = self.get_parameter('forward_tolerance').value
        self.rotate_tolerance = self.get_parameter('rotate_tolerance').value
        self.kp_angular = self.get_parameter('kp_angular').value
        self.settle_time = self.get_parameter('settle_time').value

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
        self._target_heading = None

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
        commands = goal_handle.request.commands
        values = goal_handle.request.values
        total = len(commands)

        if total != len(values):
            goal_handle.abort()
            result = ExecuteMotion.Result()
            result.success = False
            result.message = 'commands and values length mismatch'
            result.completed_steps = 0
            return result

        self.get_logger().info(
            f'Executing mission: {total} commands'
        )

        feedback_msg = ExecuteMotion.Feedback()

        for i, (cmd, val) in enumerate(zip(commands, values)):
            feedback_msg.current_step = i
            feedback_msg.current_command = cmd
            feedback_msg.progress = 0.0
            goal_handle.publish_feedback(feedback_msg)

            self.get_logger().info(
                f'Step {i + 1}/{total}: {cmd}({val:.3f})'
            )

            if cmd == 'forward':
                ok = self._execute_forward(
                    val, goal_handle, feedback_msg)
            elif cmd == 'right_turn':
                ok = self._execute_arc(
                    -math.pi / 2, val, goal_handle, feedback_msg)
            elif cmd == 'left_turn':
                ok = self._execute_arc(
                    math.pi / 2, val, goal_handle, feedback_msg)
            elif cmd == 'u_turn':
                ok = self._execute_arc(
                    math.pi, val, goal_handle, feedback_msg)
            else:
                self.get_logger().error(f'Unknown command: {cmd}')
                goal_handle.abort()
                result = ExecuteMotion.Result()
                result.success = False
                result.message = f'Unknown command: {cmd}'
                result.completed_steps = i
                return result

            if not ok:
                goal_handle.abort()
                result = ExecuteMotion.Result()
                result.success = False
                result.message = f'Failed at step {i}: {cmd}({val:.3f})'
                result.completed_steps = i
                return result

            if not self._settle():
                goal_handle.abort()
                result = ExecuteMotion.Result()
                result.success = False
                result.message = 'ROS shutdown during settle'
                result.completed_steps = i
                return result

        goal_handle.succeed()
        result = ExecuteMotion.Result()
        result.success = True
        result.message = 'All commands completed'
        result.completed_steps = total
        self.get_logger().info('Mission complete')
        return result

    def _execute_forward(self, distance, goal_handle, feedback_msg):
        rate = self.create_rate(50)

        waited = 0
        while self.odom is None and rclpy.ok():
            self.get_logger().info('Waiting for odometry...', throttle_duration_sec=1.0)
            rate.sleep()
            waited += 0.02
            if waited > 10.0:
                self.get_logger().error('Timeout waiting for odometry')
                return False

        if not rclpy.ok():
            return False

        if not self._ensure_yaw(rate):
            return False

        if self._target_heading is None:
            self._target_heading = self.yaw

        start_x = self.odom.pose.pose.position.x
        start_y = self.odom.pose.pose.position.y

        rate = self.create_rate(50)
        while rclpy.ok():
            if goal_handle.is_cancel_requested:
                self._stop()
                goal_handle.canceled()
                return False

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

            yaw_error = self._normalize(self._target_heading - self.yaw)
            angular_correction = self.kp_angular * yaw_error

            twist = Twist()
            twist.linear.x = speed
            twist.angular.z = angular_correction
            self.cmd_vel_pub.publish(twist)
            rate.sleep()

        self._stop()
        actual_yaw = self.yaw
        self.get_logger().info(
            f'Forward complete (target heading: '
            f'{math.degrees(self._target_heading):.1f}°, '
            f'actual: {math.degrees(actual_yaw):.1f}°)')
        return True

    def _ensure_yaw(self, rate):
        waited = 0
        while not self.yaw_initialized and rclpy.ok():
            if self.odom is not None:
                self.yaw = self._quat_to_yaw(self.odom.pose.pose.orientation)
                self.yaw_initialized = True
                self.get_logger().info('Using odometry for yaw (IMU not available)')
                break
            self.get_logger().info('Waiting for odometry/IMU...', throttle_duration_sec=1.0)
            rate.sleep()
            waited += 0.02
            if waited > 10.0:
                self.get_logger().error('Timeout waiting for yaw source')
                return False
        return rclpy.ok() and self.yaw_initialized

    def _execute_arc(self, angle, radius, goal_handle, feedback_msg):
        rate = self.create_rate(50)

        if not self._ensure_yaw(rate):
            return False

        start_yaw = self.yaw
        target_yaw = self._normalize(start_yaw + angle)

        if self._target_heading is None:
            self._target_heading = start_yaw
        ideal_target = self._normalize(self._target_heading + angle)

        angular_vel = self.forward_speed / radius
        if angle < 0:
            angular_vel = -angular_vel

        rate = self.create_rate(50)
        while rclpy.ok():
            if goal_handle.is_cancel_requested:
                self._stop()
                goal_handle.canceled()
                return False

            error = self._normalize(target_yaw - self.yaw)
            abs_angle = abs(angle)
            progress = 1.0 - abs(error / angle) if abs(angle) > 0.01 else 1.0
            feedback_msg.progress = min(1.0, max(0.0, progress))
            goal_handle.publish_feedback(feedback_msg)

            if abs(error) < self.rotate_tolerance:
                break

            twist = Twist()
            twist.linear.x = self.forward_speed
            twist.angular.z = angular_vel
            self.cmd_vel_pub.publish(twist)
            rate.sleep()

        self._target_heading = ideal_target

        self._stop()
        self.get_logger().info(
            f'Arc complete (target heading: '
            f'{math.degrees(ideal_target):.1f}°, '
            f'actual: {math.degrees(self.yaw):.1f}°)')
        return True

    def _stop(self):
        self.cmd_vel_pub.publish(Twist())

    def _settle(self):
        duration = self.settle_time
        if duration <= 0.0:
            return True
        self._stop()
        rate = self.create_rate(50)
        elapsed = 0.0
        while elapsed < duration and rclpy.ok():
            rate.sleep()
            elapsed += 0.02
        return rclpy.ok()

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