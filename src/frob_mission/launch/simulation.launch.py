import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import (
    AppendEnvironmentVariable,
    DeclareLaunchArgument,
    IncludeLaunchDescription,
)
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PythonExpression

from launch_ros.actions import Node


def generate_launch_description():
    pkg_frob_mission = get_package_share_directory('frob_mission')
    pkg_ros_gz_sim = get_package_share_directory('ros_gz_sim')
    pkg_tb4_sim = get_package_share_directory('nav2_minimal_tb4_sim')

    # ---- Arguments ----
    mode = LaunchConfiguration('mode')
    world_override = LaunchConfiguration('world')
    headless = LaunchConfiguration('headless')
    start_node = LaunchConfiguration('start_node')
    target_node = LaunchConfiguration('target_node')
    initial_heading = LaunchConfiguration('initial_heading')

    # Auto-select world file by mode (can be overridden via world:= arg)
    world_city = os.path.join(pkg_frob_mission, 'worlds', 'city_polygon.sdf')
    world_tb4 = os.path.join(pkg_frob_mission, 'worlds', 'city_polygon_tb4.sdf')
    world_path = PythonExpression([
        "'", world_tb4, "' if '", mode, "' != 'city' and '", world_override, "' == '' else '",
        world_city, "' if '", world_override, "' == '' else '",
        world_override, "'"])

    declare_mode = DeclareLaunchArgument(
        'mode', default_value='mission',
        choices=['city', 'tb4', 'mission'],
        description='city=polygon only, tb4=+robot, mission=+robot+mission')

    declare_world = DeclareLaunchArgument(
        'world',
        default_value='',
        description='Override SDF world path (auto-selected by mode if empty)')

    declare_headless = DeclareLaunchArgument(
        'headless', default_value='false', choices=['true', 'false'],
        description='Run Gazebo without GUI')

    declare_start_node = DeclareLaunchArgument(
        'start_node', default_value='23',
        description='Start graph node ID')

    declare_target_node = DeclareLaunchArgument(
        'target_node', default_value='108',
        description='Target graph node ID')

    declare_heading = DeclareLaunchArgument(
        'initial_heading', default_value='0.0',
        description='Initial robot heading in radians (0=east)')

    # ---- Conditions ----
    with_robot = IfCondition(PythonExpression([
        "'", mode, "' != 'city'"]))
    with_mission = IfCondition(PythonExpression([
        "'", mode, "' == 'mission'"]))

    # ---- Gazebo with world (robot is embedded in SDF) ----
    set_gz_resource = AppendEnvironmentVariable(
        'GZ_SIM_RESOURCE_PATH',
        os.path.join(pkg_frob_mission, 'worlds'))

    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_ros_gz_sim, 'launch', 'gz_sim.launch.py')),
        launch_arguments={
            'gz_args': ['-r ', world_path]}.items())

    # ---- Clock bridge ----
    clock_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='clock_bridge',
        output='screen',
        parameters=[{'use_sim_time': True}],
        arguments=['/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock'])

    # ---- TB4 bridge: Gazebo <-> ROS ----
    tb4_bridge = Node(
        condition=with_robot,
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='bridge_ros_gz',
        output='screen',
        parameters=[{
            'config_file': os.path.join(
                pkg_tb4_sim, 'configs', 'tb4_bridge.yaml'),
            'use_sim_time': True,
        }])

    # ---- Topic relays: TB4 -> frob_robot expected names ----
    relay_odom = Node(
        condition=with_robot,
        package='frob_mission',
        executable='topic_relay',
        name='relay_odom_to_odometry_filtered',
        output='screen',
        arguments=['/odom', '/odometry/filtered', 'nav_msgs.msg.Odometry'],
        parameters=[{'use_sim_time': True}])

    relay_imu = Node(
        condition=with_robot,
        package='frob_mission',
        executable='topic_relay',
        name='relay_imu_to_imu_mpu6050',
        output='screen',
        arguments=['/imu', '/imu/mpu6050', 'sensor_msgs.msg.Imu'],
        parameters=[{'use_sim_time': True}])

    # ---- Teleport robot to start_node ----
    set_pose = Node(
        condition=with_robot,
        package='frob_mission',
        executable='set_initial_pose',
        name='set_initial_pose',
        output='screen',
        parameters=[{
            'use_sim_time': True,
            'start_node': start_node,
        }])

    # ---- Mission nodes (mode=mission only) ----
    mission_config = os.path.join(
        pkg_frob_mission, 'config', 'mission_params.yaml')

    motion_executor_node = Node(
        condition=with_mission,
        package='frob_mission',
        executable='motion_executor',
        name='motion_executor',
        output='screen',
        parameters=[mission_config, {'use_sim_time': True}])

    graph_navigator_node = Node(
        condition=with_mission,
        package='frob_mission',
        executable='graph_navigator',
        name='graph_navigator',
        output='screen',
        parameters=[mission_config, {
            'use_sim_time': True,
            'start_node': start_node,
            'target_node': target_node,
            'initial_heading': initial_heading,
        }])

    graph_visualizer_node = Node(
        condition=with_mission,
        package='frob_mission',
        executable='graph_visualizer',
        name='graph_visualizer',
        output='screen',
        parameters=[{
            'use_sim_time': True,
            'start_node': start_node,
        }])

    # ---- RViz2 (mission mode only) ----
    rviz_config = os.path.join(pkg_frob_mission, 'config', 'planning.rviz')
    rviz_node = Node(
        condition=with_mission,
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config])

    return LaunchDescription([
        declare_mode,
        declare_world,
        declare_headless,
        declare_start_node,
        declare_target_node,
        declare_heading,
        set_gz_resource,
        gz_sim,
        clock_bridge,
        tb4_bridge,
        relay_odom,
        relay_imu,
        set_pose,
        motion_executor_node,
        graph_navigator_node,
        graph_visualizer_node,
        rviz_node,
    ])
