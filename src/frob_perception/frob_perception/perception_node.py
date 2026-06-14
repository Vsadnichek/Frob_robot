import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from frob_interfaces.msg import LineDetection, SignDetection
import cv2
import numpy as np


class PerceptionNode(Node):
    def __init__(self):
        super().__init__('perception_node')

        self.declare_parameter('publish_debug_image', True)
        self.declare_parameter('debug_image_topic', '/perception/debug_image')

        self.bridge = CvBridge()

        self.subscription = self.create_subscription(
            Image, '/camera/image_raw', self.image_callback, 10
        )

        self.line_pub = self.create_publisher(LineDetection, '/perception/line', 10)
        self.sign_pub = self.create_publisher(SignDetection, '/perception/sign', 10)

        publish_debug = self.get_parameter('publish_debug_image').value
        self.debug_pub = None
        if publish_debug:
            debug_topic = self.get_parameter('debug_image_topic').value
            self.debug_pub = self.create_publisher(Image, debug_topic, 10)

        self.get_logger().info('Perception node started')

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
        debug_frame = frame.copy()

        line_msg = self.detect_line(frame, debug_frame)
        self.line_pub.publish(line_msg)

        sign_msg = self.detect_signs(frame, debug_frame)
        self.sign_pub.publish(sign_msg)

        if self.debug_pub is not None:
            debug_msg = self.bridge.cv2_to_imgmsg(debug_frame, encoding='bgr8')
            debug_msg.header = msg.header
            self.debug_pub.publish(debug_msg)

    def detect_line(self, frame, debug_frame):
        msg = LineDetection()

        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        lower_white = np.array([0, 0, 180])
        upper_white = np.array([180, 30, 255])
        mask = cv2.inRange(hsv, lower_white, upper_white)

        kernel = np.ones((3, 3), np.uint8)
        mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)
        mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)

        h, w = mask.shape

        roi_top = int(h * 0.4)
        roi_bottom = int(h * 0.85)
        mask_roi = mask[roi_top:roi_bottom, :]

        moments = cv2.moments(mask_roi, binaryImage=True)
        if moments['m00'] > 100:
            cx = moments['m10'] / moments['m00']
            cy = moments['m01'] / moments['m00']

            image_center_x = w / 2.0
            msg.lateral_error = (cx - image_center_x) / image_center_x

            msg.line_center_x = cx
            msg.line_center_y = cy + roi_top

            msg.detected = True
            msg.confidence = min(1.0, moments['m00'] / 5000.0)

            contour_mask = np.zeros_like(mask_roi)
            contours, _ = cv2.findContours(mask_roi, cv2.RETR_EXTERNAL,
                                           cv2.CHAIN_APPROX_SIMPLE)
            if contours:
                largest = max(contours, key=cv2.contourArea)
                rect = cv2.minAreaRect(largest)
                angle = rect[2]
                if rect[1][0] < rect[1][1]:
                    angle = angle + 90
                msg.angle_error = np.deg2rad(np.clip(angle, -45, 45))
        else:
            msg.detected = False
            msg.lateral_error = 0.0
            msg.angle_error = 0.0
            msg.confidence = 0.0
            msg.line_center_x = -1.0
            msg.line_center_y = -1.0

        if self.debug_pub is not None:
            mask_color = cv2.cvtColor(mask, cv2.COLOR_GRAY2BGR)
            mask_color[mask > 0] = (0, 255, 0)
            cv2.rectangle(debug_frame, (0, roi_top), (w, roi_bottom),
                          (255, 255, 0), 1)

            overlay = cv2.addWeighted(debug_frame, 1.0, mask_color, 0.3, 0)
            np.copyto(debug_frame, overlay)

            center_x_img = int(w / 2)
            cv2.line(debug_frame, (center_x_img, 0), (center_x_img, h),
                     (0, 0, 255), 1)

            if msg.detected:
                cx_img = int(msg.line_center_x)
                cy_img = int(msg.line_center_y)
                cv2.circle(debug_frame, (cx_img, cy_img), 8, (0, 255, 255), -1)
                cv2.putText(debug_frame, f'err={msg.lateral_error:.2f}',
                            (cx_img + 10, cy_img), cv2.FONT_HERSHEY_SIMPLEX,
                            0.5, (0, 255, 255), 1)
            else:
                cv2.putText(debug_frame, 'LINE LOST', (10, 30),
                            cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

        return msg

    def detect_signs(self, frame, debug_frame):
        msg = SignDetection()
        msg.detected = False
        msg.sign_type = SignDetection.UNKNOWN
        msg.distance = -1.0
        msg.confidence = 0.0
        msg.bbox_center_x = -1.0
        msg.bbox_center_y = -1.0
        msg.bbox_width = 0.0
        msg.bbox_height = 0.0

        h, w = frame.shape[:2]
        roi_top = int(h * 0.1)
        roi_bottom = int(h * 0.7)
        roi_frame = frame[roi_top:roi_bottom, :]

        gray = cv2.cvtColor(roi_frame, cv2.COLOR_BGR2GRAY)
        gray = cv2.GaussianBlur(gray, (5, 5), 0)

        min_radius = int(w * 0.03)
        max_radius = int(w * 0.12)

        circles = cv2.HoughCircles(
            gray, cv2.HOUGH_GRADIENT, dp=1.2, minDist=min_radius * 3,
            param1=80, param2=35, minRadius=min_radius, maxRadius=max_radius
        )

        if circles is not None:
            circles = np.uint16(np.around(circles))
            best_circle = None
            best_score = float(w)

            for circle in circles[0, :]:
                c_x, c_y, c_r = circle
                score = abs(c_x - w * 0.55) + abs(c_y - roi_frame.shape[0] * 0.5)
                if score < best_score and c_y < roi_frame.shape[0] * 0.85:
                    best_score = score
                    best_circle = circle

            if best_circle is not None:
                c_x, c_y, c_r = best_circle

                margin = int(c_r * 0.15)
                y1 = max(0, c_y - c_r - margin)
                y2 = min(roi_frame.shape[0], c_y + c_r + margin)
                x1 = max(0, c_x - c_r - margin)
                x2 = min(roi_frame.shape[1], c_x + c_r + margin)
                roi = roi_frame[y1:y2, x1:x2]

                if roi.size > 0:
                    sign_type = self.classify_sign(roi)
                    if sign_type != SignDetection.UNKNOWN:
                        msg.detected = True
                        msg.sign_type = sign_type
                        msg.confidence = 0.7
                        msg.bbox_center_x = float(c_x)
                        msg.bbox_center_y = float(c_y + roi_top)
                        msg.bbox_width = float(c_r * 2)
                        msg.bbox_height = float(c_r * 2)

                        known_radius_mm = 50.0
                        focal_pixels = 500.0
                        if c_r > 0:
                            msg.distance = (known_radius_mm * focal_pixels) / (c_r * 10.0)

        if self.debug_pub is not None and circles is not None:
            for circle in circles[0, :]:
                c_x, c_y, c_r = circle
                cy_global = c_y + roi_top
                color = (255, 0, 0)
                if (msg.detected and
                        abs(c_x - msg.bbox_center_x) < 5 and
                        abs(cy_global - msg.bbox_center_y) < 5):
                    color = (0, 255, 0)
                cv2.circle(debug_frame, (c_x, cy_global), c_r, color, 2)
                cv2.circle(debug_frame, (c_x, cy_global), 2, color, 3)

            if msg.detected:
                names = {
                    SignDetection.GO_STRAIGHT: 'GO STRAIGHT',
                    SignDetection.GO_LEFT: 'GO LEFT',
                    SignDetection.GO_RIGHT: 'GO RIGHT',
                    SignDetection.NO_LEFT_TURN: 'NO LEFT',
                    SignDetection.NO_RIGHT_TURN: 'NO RIGHT',
                    SignDetection.BUS_STOP: 'BUS STOP',
                    SignDetection.PARKING: 'PARKING',
                    SignDetection.DANGER: 'DANGER',
                }
                label = names.get(msg.sign_type, 'SIGN')
                bx = int(msg.bbox_center_x)
                by = int(msg.bbox_center_y)
                cv2.putText(debug_frame, f'{label} d={msg.distance:.2f}m',
                            (bx + 20, by), cv2.FONT_HERSHEY_SIMPLEX,
                            0.5, (0, 255, 0), 2)

        if self.debug_pub is not None:
            cv2.rectangle(debug_frame, (0, roi_top), (w, roi_bottom),
                          (0, 255, 255), 1)

        return msg

    def classify_sign(self, roi):
        if roi.size == 0:
            return SignDetection.UNKNOWN

        hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)

        center_y = roi.shape[0] // 2
        center_x = roi.shape[1] // 2
        r = min(roi.shape[0], roi.shape[1]) // 3
        y1 = max(0, center_y - r)
        y2 = min(roi.shape[0], center_y + r)
        x1 = max(0, center_x - r)
        x2 = min(roi.shape[1], center_x + r)

        inner = hsv[y1:y2, x1:x2]
        if inner.size == 0:
            return SignDetection.UNKNOWN

        red_mask1 = cv2.inRange(hsv, np.array([0, 50, 50]),
                                np.array([10, 255, 255]))
        red_mask2 = cv2.inRange(hsv, np.array([170, 50, 50]),
                                np.array([180, 255, 255]))
        red_mask = cv2.bitwise_or(red_mask1, red_mask2)
        red_ratio = np.count_nonzero(red_mask) / (roi.shape[0] * roi.shape[1])

        blue_mask = cv2.inRange(hsv, np.array([100, 50, 50]),
                                np.array([130, 255, 255]))
        blue_ratio = np.count_nonzero(blue_mask) / (roi.shape[0] * roi.shape[1])

        if red_ratio > 0.08:
            inner_red1 = cv2.inRange(inner, np.array([0, 50, 50]),
                                     np.array([10, 255, 255]))
            inner_red2 = cv2.inRange(inner, np.array([170, 50, 50]),
                                     np.array([180, 255, 255]))
            inner_red = cv2.bitwise_or(inner_red1, inner_red2)
            inner_ratio = np.count_nonzero(inner_red) / (inner.size / 3)

            if inner_ratio < 0.05:
                return SignDetection.NO_RIGHT_TURN
            else:
                return SignDetection.NO_LEFT_TURN

        if blue_ratio > 0.04:
            inner_blue = cv2.inRange(inner, np.array([100, 50, 50]),
                                     np.array([130, 255, 255]))
            inner_ratio = np.count_nonzero(inner_blue) / (inner.size / 3)
            if inner_ratio > 0.1:
                return SignDetection.PARKING
            else:
                return SignDetection.GO_STRAIGHT

        return SignDetection.UNKNOWN


def main(args=None):
    rclpy.init(args=args)
    node = PerceptionNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()
