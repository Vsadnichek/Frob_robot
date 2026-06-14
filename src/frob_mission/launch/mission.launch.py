from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_dir = get_package_share_directory('frob_mission')
    config_file = os.path.join(pkg_dir, 'config', 'mission_params.yaml')

    start_node = LaunchConfiguration('start_node', default='13')
    target_node = LaunchConfiguration('target_node', default='108')
    initial_heading = LaunchConfiguration('initial_heading', default='0.0')

    start_arg = DeclareLaunchArgument('start_node', default_value='13')
    target_arg = DeclareLaunchArgument('target_node', default_value='108')
    heading_arg = DeclareLaunchArgument('initial_heading', default_value='0.0')

    motion_executor = Node(
        package='frob_mission',
        executable='motion_executor',
        name='motion_executor',
        output='screen',
        parameters=[config_file],
    )

    graph_navigator = Node(
        package='frob_mission',
        executable='graph_navigator',
        name='graph_navigator',
        output='screen',
        parameters=[config_file, {
            'start_node': start_node,
            'target_node': target_node,
            'initial_heading': initial_heading,
        }],
    )

    return LaunchDescription([
        start_arg,
        target_arg,
        heading_arg,
        motion_executor,
        graph_navigator,
    ])
