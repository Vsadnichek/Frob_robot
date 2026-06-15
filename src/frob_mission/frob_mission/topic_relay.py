import sys
import rclpy
from rclpy.node import Node


class TopicRelay(Node):
    def __init__(self, in_topic, out_topic, msg_type):
        super().__init__(f'relay_{in_topic.replace("/", "_")}_to_{out_topic.replace("/", "_")}')
        self.pub = self.create_publisher(msg_type, out_topic, 10)
        self.sub = self.create_subscription(msg_type, in_topic, self.callback, 10)

    def callback(self, msg):
        self.pub.publish(msg)


def main():
    rclpy.init()
    args = rclpy.utilities.remove_ros_args(sys.argv)
    if len(args) != 4:
        print('Usage: topic_relay <from_topic> <to_topic> <msg_type>')
        print('Example: topic_relay /odom /odometry/filtered nav_msgs.msg.Odometry')
        sys.exit(1)
    from_topic, to_topic, msg_type_str = args[1], args[2], args[3]
    module, attr = msg_type_str.rsplit('.', 1)
    mod = __import__(module, fromlist=[attr])
    msg_type = getattr(mod, attr)
    node = TopicRelay(from_topic, to_topic, msg_type)
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
