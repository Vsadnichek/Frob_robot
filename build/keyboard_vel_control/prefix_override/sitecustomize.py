import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/pi/Frob_robot/ros2/src/ros2_ws/install/keyboard_vel_control'
