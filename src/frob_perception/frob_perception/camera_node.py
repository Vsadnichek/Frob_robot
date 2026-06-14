import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge
import cv2
import time


class CameraNode(Node):
    def __init__(self):
        super().__init__('camera_node')

        self.declare_parameter('device', 0)
        self.declare_parameter('width', 640)
        self.declare_parameter('height', 480)
        self.declare_parameter('fps', 30.0)
        self.declare_parameter('publish_compressed', True)
        self.declare_parameter('jpeg_quality', 80)
        self.declare_parameter('fourcc', 'MJPG')

        device = self.get_parameter('device').value
        width = self.get_parameter('width').value
        height = self.get_parameter('height').value
        fps = self.get_parameter('fps').value
        self.publish_compressed = self.get_parameter('publish_compressed').value
        self.jpeg_quality = self.get_parameter('jpeg_quality').value
        fourcc_str = self.get_parameter('fourcc').value

        self.bridge = CvBridge()
        self.publisher = self.create_publisher(Image, '/camera/image_raw', 10)

        if self.publish_compressed:
            self.compressed_publisher = self.create_publisher(
                CompressedImage, '/camera/image_raw/compressed', 10
            )
        else:
            self.compressed_publisher = None

        self.cap = cv2.VideoCapture(device, cv2.CAP_V4L2)
        if not self.cap.isOpened():
            self.get_logger().warn(
                f'V4L2 backend failed for device {device}, trying default'
            )
            self.cap = cv2.VideoCapture(device)
        if not self.cap.isOpened():
            self.get_logger().fatal(f'Cannot open camera device {device}')
            raise RuntimeError(f'Cannot open camera device {device}')

        if fourcc_str:
            fourcc = cv2.VideoWriter_fourcc(*fourcc_str)
            self.cap.set(cv2.CAP_PROP_FOURCC, fourcc)

        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, width)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
        self.cap.set(cv2.CAP_PROP_FPS, fps)

        actual_w = self.cap.get(cv2.CAP_PROP_FRAME_WIDTH)
        actual_h = self.cap.get(cv2.CAP_PROP_FRAME_HEIGHT)
        actual_fps = self.cap.get(cv2.CAP_PROP_FPS)
        self.get_logger().info(
            f'Camera opened: {actual_w}x{actual_h} @ {actual_fps}fps'
        )

        time.sleep(0.2)
        for _ in range(3):
            self.cap.read()

        period = 1.0 / fps
        self.timer = self.create_timer(period, self.timer_callback)
        self.get_logger().info('Camera node started')

    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().warn('Failed to capture frame',
                                   throttle_duration_sec=2.0)
            return

        stamp = self.get_clock().now().to_msg()

        msg = self.bridge.cv2_to_imgmsg(frame, encoding='bgr8')
        msg.header.stamp = stamp
        msg.header.frame_id = 'camera'
        self.publisher.publish(msg)

        if self.compressed_publisher is not None:
            ok, encoded = cv2.imencode(
                '.jpg', frame,
                [cv2.IMWRITE_JPEG_QUALITY, self.jpeg_quality]
            )
            if ok:
                comp_msg = CompressedImage()
                comp_msg.header.stamp = stamp
                comp_msg.header.frame_id = 'camera'
                comp_msg.format = 'jpeg'
                comp_msg.data = encoded.tobytes()
                self.compressed_publisher.publish(comp_msg)

    def destroy_node(self):
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
