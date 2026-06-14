from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_dir = get_package_share_directory('frob_perception')
    config_file = os.path.join(pkg_dir, 'config', 'perception_params.yaml')

    camera_device = LaunchConfiguration('camera_device', default='0')

    camera_arg = DeclareLaunchArgument(
        'camera_device',
        default_value='0',
        description='Camera device index (e.g. 0 for /dev/video0)'
    )

    camera_node = Node(
        package='frob_perception',
        executable='camera_node',
        name='camera_node',
        output='screen',
        parameters=[config_file, {'device': camera_device}],
    )

    return LaunchDescription([
        camera_arg,
        camera_node,
    ])
