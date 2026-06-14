// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from frob_interfaces:msg/ObstacleDetection.idl
// generated code does not contain a copyright notice
#include "frob_interfaces/msg/detail/obstacle_detection__rosidl_typesupport_fastrtps_cpp.hpp"
#include "frob_interfaces/msg/detail/obstacle_detection__functions.h"
#include "frob_interfaces/msg/detail/obstacle_detection__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace frob_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
cdr_serialize(
  const frob_interfaces::msg::ObstacleDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: blocked
  cdr << (ros_message.blocked ? true : false);

  // Member: distance
  cdr << ros_message.distance;

  // Member: zone_width
  cdr << ros_message.zone_width;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  frob_interfaces::msg::ObstacleDetection & ros_message)
{
  // Member: blocked
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.blocked = tmp ? true : false;
  }

  // Member: distance
  cdr >> ros_message.distance;

  // Member: zone_width
  cdr >> ros_message.zone_width;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
get_serialized_size(
  const frob_interfaces::msg::ObstacleDetection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: blocked
  {
    size_t item_size = sizeof(ros_message.blocked);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: distance
  {
    size_t item_size = sizeof(ros_message.distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: zone_width
  {
    size_t item_size = sizeof(ros_message.zone_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
max_serialized_size_ObstacleDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: blocked
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: distance
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: zone_width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = frob_interfaces::msg::ObstacleDetection;
    is_plain =
      (
      offsetof(DataType, zone_width) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
cdr_serialize_key(
  const frob_interfaces::msg::ObstacleDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: blocked
  cdr << (ros_message.blocked ? true : false);

  // Member: distance
  cdr << ros_message.distance;

  // Member: zone_width
  cdr << ros_message.zone_width;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
get_serialized_size_key(
  const frob_interfaces::msg::ObstacleDetection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: blocked
  {
    size_t item_size = sizeof(ros_message.blocked);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: distance
  {
    size_t item_size = sizeof(ros_message.distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: zone_width
  {
    size_t item_size = sizeof(ros_message.zone_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
max_serialized_size_key_ObstacleDetection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: blocked
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: distance
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: zone_width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = frob_interfaces::msg::ObstacleDetection;
    is_plain =
      (
      offsetof(DataType, zone_width) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _ObstacleDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const frob_interfaces::msg::ObstacleDetection *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ObstacleDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<frob_interfaces::msg::ObstacleDetection *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ObstacleDetection__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const frob_interfaces::msg::ObstacleDetection *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ObstacleDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ObstacleDetection(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ObstacleDetection__callbacks = {
  "frob_interfaces::msg",
  "ObstacleDetection",
  _ObstacleDetection__cdr_serialize,
  _ObstacleDetection__cdr_deserialize,
  _ObstacleDetection__get_serialized_size,
  _ObstacleDetection__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _ObstacleDetection__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ObstacleDetection__callbacks,
  get_message_typesupport_handle_function,
  &frob_interfaces__msg__ObstacleDetection__get_type_hash,
  &frob_interfaces__msg__ObstacleDetection__get_type_description,
  &frob_interfaces__msg__ObstacleDetection__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace frob_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_frob_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<frob_interfaces::msg::ObstacleDetection>()
{
  return &frob_interfaces::msg::typesupport_fastrtps_cpp::_ObstacleDetection__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, frob_interfaces, msg, ObstacleDetection)() {
  return &frob_interfaces::msg::typesupport_fastrtps_cpp::_ObstacleDetection__handle;
}

#ifdef __cplusplus
}
#endif
