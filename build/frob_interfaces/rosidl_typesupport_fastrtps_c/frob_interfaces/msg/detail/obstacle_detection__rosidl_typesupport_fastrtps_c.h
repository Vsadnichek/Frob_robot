// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from frob_interfaces:msg/ObstacleDetection.idl
// generated code does not contain a copyright notice
#ifndef FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "frob_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "frob_interfaces/msg/detail/obstacle_detection__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
bool cdr_serialize_frob_interfaces__msg__ObstacleDetection(
  const frob_interfaces__msg__ObstacleDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
bool cdr_deserialize_frob_interfaces__msg__ObstacleDetection(
  eprosima::fastcdr::Cdr &,
  frob_interfaces__msg__ObstacleDetection * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
size_t get_serialized_size_frob_interfaces__msg__ObstacleDetection(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
size_t max_serialized_size_frob_interfaces__msg__ObstacleDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
bool cdr_serialize_key_frob_interfaces__msg__ObstacleDetection(
  const frob_interfaces__msg__ObstacleDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
size_t get_serialized_size_key_frob_interfaces__msg__ObstacleDetection(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
size_t max_serialized_size_key_frob_interfaces__msg__ObstacleDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, frob_interfaces, msg, ObstacleDetection)();

#ifdef __cplusplus
}
#endif

#endif  // FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
