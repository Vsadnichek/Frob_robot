import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from control_msgs.action import FollowJointTrajectory
from trajectory_msgs.msg import JointTrajectoryPoint
import time

class MoveItPatrol(Node):
    def __init__(self):
        super().__init__('moveit_patrol')
        self._action_client = ActionClient(self, FollowJointTrajectory, '/arm_controller/follow_joint_trajectory')

        # ВАШ СЛОВАРЬ ПОЗИЦИЙ (вставьте свои значения из Шага 2)
        self.positions = {
            "HOME": [0.0, -1.047, 0.524, 1.309, 0.0],
            "PICK_UP": [0.5, -0.8, 0.3, 1.0, 0.2],
            "DROP_OFF": [-0.5, -0.8, 0.3, 1.0, -0.2]
        }

        self.joint_names = ['shoulder_pan', 'shoulder_lift', 'elbow_flex', 'wrist_flex', 'wrist_roll']

    def send_goal(self, pose_name):
        goal_msg = FollowJointTrajectory.Goal()
        point = JointTrajectoryPoint()
        point.positions = self.positions[pose_name]
        point.time_from_start.sec = 3  # Время на перемещение (3 секунды)

        goal_msg.trajectory.joint_names = self.joint_names
        goal_msg.trajectory.points = [point]

        self.get_logger().info(f'Еду в позицию: {pose_name}')
        self._action_client.wait_for_server()
        return self._action_client.send_goal_async(goal_msg)

def main():
    rclpy.init()
    node = MoveItPatrol()

    try:
        while rclpy.ok():
            for pose in node.positions:
                future = node.send_goal(pose)
                # Ждем 5 секунд перед следующей точкой (время в пути + пауза)
                time.sleep(5.0) 
    except KeyboardInterrupt:
        node.get_logger().info('Патрулирование остановлено')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
