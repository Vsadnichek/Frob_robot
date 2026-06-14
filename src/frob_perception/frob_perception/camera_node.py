import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np


class CameraNode(Node):
    def __init__(self):
        super().__init__('camera_node')

        self.declare_parameter('device', 0)
        self.declare_parameter('width', 640)
        self.declare_parameter('height', 480)
        self.declare_parameter('fps', 30.0)

        self.device = self.get_parameter('device').value
        width = self.get_parameter('width').value
        height = self.get_parameter('height').value
        fps = self.get_parameter('fps').value

        self.bridge = CvBridge()
        self.publisher = self.create_publisher(Image, '/camera/image_raw', 10)

        self.use_test_pattern = (self.device < 0)
        self.cap = None

        if self.use_test_pattern:
            self.get_logger().info('Using synthetic test pattern (device < 0)')
            self.frame_idx = 0
        else:
            self.cap = cv2.VideoCapture(self.device)
            if not self.cap.isOpened():
                self.get_logger().fatal(f'Cannot open camera device {self.device}')
                raise RuntimeError(f'Cannot open camera device {self.device}')

            self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, width)
            self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
            self.cap.set(cv2.CAP_PROP_FPS, fps)

            actual_w = self.cap.get(cv2.CAP_PROP_FRAME_WIDTH)
            actual_h = self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
            actual_fps = self.cap.get(cv2.CAP_PROP_FPS)
            self.get_logger().info(
                f'Camera opened: {actual_w}x{actual_h} @ {actual_fps}fps'
            )

        self.w = width
        self.h = height
        period = 1.0 / fps
        self.timer = self.create_timer(period, self.timer_callback)
        self.get_logger().info('Camera node started')

    def _generate_test_pattern(self):
        frame = np.full((self.h, self.w, 3), 70, dtype=np.uint8)

        cx = self.w // 2 + int(60 * np.sin(self.frame_idx * 0.03))
        pts = np.array([
            [cx - 4, self.h],
            [cx + 4, self.h],
            [cx + 4, self.h // 3],
            [cx - 4, self.h // 3],
        ], np.int32)
        cv2.fillPoly(frame, [pts], (255, 255, 255))

        cv2.rectangle(frame, (0, self.h // 3), (self.w, self.h // 3 + 1),
                      (160, 160, 160), -1)

        sign_types = [
            (1, (255, 100, 100)),   # GO_STRAIGHT
            (4, (100, 100, 255)),   # NO_LEFT_TURN
            (7, (200, 50, 50)),     # PARKING
            (6, (50, 150, 50)),     # BUS_STOP
        ]
        sign_idx = (self.frame_idx // 90) % len(sign_types)
        sign_type, sign_color = sign_types[sign_idx]

        sign_x = self.w * 3 // 5
        sign_y = self.h // 3
        sign_r = 35
        cv2.circle(frame, (sign_x, sign_y), sign_r, sign_color, -1)
        cv2.circle(frame, (sign_x, sign_y), sign_r, (40, 40, 40), 2)
        label = {
            1: '^',
            4: 'X',
            7: 'P',
            6: 'O',
        }.get(sign_type, '?')
        cv2.putText(frame, label, (sign_x - 10, sign_y + 10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (255, 255, 255), 2)

        self.frame_idx += 1
        return frame

    def timer_callback(self):
        if self.use_test_pattern:
            frame = self._generate_test_pattern()
        else:
            ret, frame = self.cap.read()
            if not ret:
                self.get_logger().warn('Failed to capture frame',
                                       throttle_duration_sec=2.0)
                return

        msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'camera'
        self.publisher.publish(msg)

    def destroy_node(self):
        if self.cap is not None:
            self.cap.release()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = CameraNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
