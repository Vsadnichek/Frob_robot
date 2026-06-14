import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/vsadnik/ros2_ws/frob_robot/install/frob_mission'
