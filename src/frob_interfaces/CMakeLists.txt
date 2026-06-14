cmake_minimum_required(VERSION 3.5)
project(frob_interfaces)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/Turn.srv"
  "srv/Forward.srv"
  "msg/LineDetection.msg"
  "msg/SignDetection.msg"
  "msg/IntersectionDetection.msg"
  "msg/ObstacleDetection.msg"
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
