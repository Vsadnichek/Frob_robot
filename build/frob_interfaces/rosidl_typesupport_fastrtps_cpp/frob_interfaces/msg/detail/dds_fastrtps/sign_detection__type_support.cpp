// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from frob_interfaces:msg/SignDetection.idl
// generated code does not contain a copyright notice
#include "frob_interfaces/msg/detail/sign_detection__rosidl_typesupport_fastrtps_cpp.hpp"
#include "frob_interfaces/msg/detail/sign_detection__functions.h"
#include "frob_interfaces/msg/detail/sign_detection__struct.hpp"

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
  const frob_interfaces::msg::SignDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: sign_type
  cdr << ros_message.sign_type;

  // Member: distance
  cdr << ros_message.distance;

  // Member: confidence
  cdr << ros_message.confidence;

  // Member: detected
  cdr << (ros_message.detected ? true : false);

  // Member: bbox_center_x
  cdr << ros_message.bbox_center_x;

  // Member: bbox_center_y
  cdr << ros_message.bbox_center_y;

  // Member: bbox_width
  cdr << ros_message.bbox_width;

  // Member: bbox_height
  cdr << ros_message.bbox_height;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  frob_interfaces::msg::SignDetection & ros_message)
{
  // Member: sign_type
  cdr >> ros_message.sign_type;

  // Member: distance
  cdr >> ros_message.distance;

  // Member: confidence
  cdr >> ros_message.confidence;

  // Member: detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.detected = tmp ? true : false;
  }

  // Member: bbox_center_x
  cdr >> ros_message.bbox_center_x;

  // Member: bbox_center_y
  cdr >> ros_message.bbox_center_y;

  // Member: bbox_width
  cdr >> ros_message.bbox_width;

  // Member: bbox_height
  cdr >> ros_message.bbox_height;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
get_serialized_size(
  const frob_interfaces::msg::SignDetection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: sign_type
  {
    size_t item_size = sizeof(ros_message.sign_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: distance
  {
    size_t item_size = sizeof(ros_message.distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: confidence
  {
    size_t item_size = sizeof(ros_message.confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: detected
  {
    size_t item_size = sizeof(ros_message.detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: bbox_center_x
  {
    size_t item_size = sizeof(ros_message.bbox_center_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: bbox_center_y
  {
    size_t item_size = sizeof(ros_message.bbox_center_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: bbox_width
  {
    size_t item_size = sizeof(ros_message.bbox_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: bbox_height
  {
    size_t item_size = sizeof(ros_message.bbox_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
max_serialized_size_SignDetection(
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

  // Member: sign_type
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
  // Member: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: bbox_center_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: bbox_center_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: bbox_width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: bbox_height
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
    using DataType = frob_interfaces::msg::SignDetection;
    is_plain =
      (
      offsetof(DataType, bbox_height) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
cdr_serialize_key(
  const frob_interfaces::msg::SignDetection & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: sign_type
  cdr << ros_message.sign_type;

  // Member: distance
  cdr << ros_message.distance;

  // Member: confidence
  cdr << ros_message.confidence;

  // Member: detected
  cdr << (ros_message.detected ? true : false);

  // Member: bbox_center_x
  cdr << ros_message.bbox_center_x;

  // Member: bbox_center_y
  cdr << ros_message.bbox_center_y;

  // Member: bbox_width
  cdr << ros_message.bbox_width;

  // Member: bbox_height
  cdr << ros_message.bbox_height;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
get_serialized_size_key(
  const frob_interfaces::msg::SignDetection & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: sign_type
  {
    size_t item_size = sizeof(ros_message.sign_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: distance
  {
    size_t item_size = sizeof(ros_message.distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: confidence
  {
    size_t item_size = sizeof(ros_message.confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: detected
  {
    size_t item_size = sizeof(ros_message.detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: bbox_center_x
  {
    size_t item_size = sizeof(ros_message.bbox_center_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: bbox_center_y
  {
    size_t item_size = sizeof(ros_message.bbox_center_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: bbox_width
  {
    size_t item_size = sizeof(ros_message.bbox_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: bbox_height
  {
    size_t item_size = sizeof(ros_message.bbox_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_frob_interfaces
max_serialized_size_key_SignDetection(
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

  // Member: sign_type
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

  // Member: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: bbox_center_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: bbox_center_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: bbox_width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: bbox_height
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
    using DataType = frob_interfaces::msg::SignDetection;
    is_plain =
      (
      offsetof(DataType, bbox_height) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _SignDetection__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const frob_interfaces::msg::SignDetection *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SignDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<frob_interfaces::msg::SignDetection *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SignDetection__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const frob_interfaces::msg::SignDetection *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SignDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SignDetection(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SignDetection__callbacks = {
  "frob_interfaces::msg",
  "SignDetection",
  _SignDetection__cdr_serialize,
  _SignDetection__cdr_deserialize,
  _SignDetection__get_serialized_size,
  _SignDetection__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SignDetection__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SignDetection__callbacks,
  get_message_typesupport_handle_function,
  &frob_interfaces__msg__SignDetection__get_type_hash,
  &frob_interfaces__msg__SignDetection__get_type_description,
  &frob_interfaces__msg__SignDetection__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace frob_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_frob_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<frob_interfaces::msg::SignDetection>()
{
  return &frob_interfaces::msg::typesupport_fastrtps_cpp::_SignDetection__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, frob_interfaces, msg, SignDetection)() {
  return &frob_interfaces::msg::typesupport_fastrtps_cpp::_SignDetection__handle;
}

#ifdef __cplusplus
}
#endif
