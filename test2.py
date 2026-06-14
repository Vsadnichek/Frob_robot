import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import Constraints, JointConstraint, PlanningOptions

class SmoothMoveItPatrol(Node):
    def __init__(self):
        super().__init__('smooth_moveit_patrol')
        
        # Создаем клиент для MoveGroup (основной интерфейс MoveIt)
        self._action_client = ActionClient(self, MoveGroup, 'move_action')
        
        # ВАШ СЛОВАРЬ (те же точки, что были раньше)
        self.positions = {
            "HOME": [0.0, -1.047, 0.524, 1.309, 0.0],
            "PICK_UP": [0.5, -0.8, 0.3, 1.0, 0.2],
            "DROP_OFF": [-0.5, -0.8, 0.3, 1.0, -0.2]
        }

        # Имена суставов из вашего лога (важно соблюдать порядок!)
        self.joint_names = [
            'shoulder_pan', 
            'shoulder_lift', 
            'elbow_flex', 
            'wrist_flex', 
            'wrist_roll'
        ]
        
        self.get_logger().info('Скрипт запущен. Ожидание MoveIt...')

    def move_to_pose(self, pose_name):
        if not self._action_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error('MoveGroup Action Server не найден!')
            return

        joint_values = self.positions[pose_name]
        self.get_logger().info(f'Планирование пути в позицию: {pose_name}')

        # Формируем цель для MoveIt
        goal_msg = MoveGroup.Goal()
        goal_msg.request.group_name = "arm"
        
        # Установка ограничений (целевая позиция суставов)
        joint_constraints = Constraints()
        for name, value in zip(self.joint_names, joint_values):
            jc = JointConstraint()
            jc.joint_name = name
            jc.position = value
            jc.tolerance_above = 0.01
            jc.tolerance_below = 0.01
            jc.weight = 1.0
            joint_constraints.joint_constraints.append(jc)
        
        goal_msg.request.goal_constraints.append(joint_constraints)

        # Настройки плавности (аналогично RViz)
        goal_msg.request.allowed_planning_time = 5.0
        goal_msg.request.max_velocity_scaling_factor = 0.2  # Скорость 20%
        goal_msg.request.max_acceleration_scaling_factor = 0.1 # Ускорение 10% (очень плавно)

        # Отправляем задачу
        send_goal_future = self._action_client.send_goal_async(goal_msg)
        send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('MoveIt отклонил задачу')
            return
        
        self.get_logger().info('Задача принята, движение начато...')
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        self.get_logger().info('Движение завершено успешно!')

def main():
    rclpy.init()
    node = SmoothMoveItPatrol()

    try:
        while rclpy.ok():
            for pose in node.positions:
                node.move_to_pose(pose)
                # Ждем завершения движения + небольшая пауза перед следующей точкой
                # В этом упрощенном примере мы просто спим 7 секунд
                import time
                time.sleep(7.0) 
    except KeyboardInterrupt:
        node.get_logger().info('Патрулирование остановлено пользователем')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
