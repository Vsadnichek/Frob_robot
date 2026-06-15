from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, TimerAction
from launch.substitutions import LaunchConfiguration
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_dir = get_package_share_directory('frob_mission')
    config_file = os.path.join(pkg_dir, 'config', 'mission_params.yaml')
    rviz_config = os.path.join(pkg_dir, 'config', 'planning.rviz')

    start_node = LaunchConfiguration('start_node', default='13')
    target_node = LaunchConfiguration('target_node', default='108')

    start_arg = DeclareLaunchArgument('start_node', default_value='13')
    target_arg = DeclareLaunchArgument('target_node', default_value='108')

    graph_navigator = Node(
        package='frob_mission',
        executable='graph_navigator',
        name='graph_navigator',
        output='screen',
        parameters=[config_file, {
            'start_node': start_node,
            'target_node': target_node,
            'execute': False,
        }],
    )

    graph_visualizer = Node(
        package='frob_mission',
        executable='graph_visualizer',
        name='graph_visualizer',
        output='screen',
    )

    rviz = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config],
    )

    return LaunchDescription([
        start_arg,
        target_arg,
        graph_navigator,
        graph_visualizer,
        rviz,
    ])