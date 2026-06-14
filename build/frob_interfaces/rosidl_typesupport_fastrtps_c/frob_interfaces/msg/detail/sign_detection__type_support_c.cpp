// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from frob_interfaces:msg/SignDetection.idl
// generated code does not contain a copyright notice
#include "frob_interfaces/msg/detail/sign_detection__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "frob_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "frob_interfaces/msg/detail/sign_detection__struct.h"
#include "frob_interfaces/msg/detail/sign_detection__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SignDetection__ros_msg_type = frob_interfaces__msg__SignDetection;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
bool cdr_serialize_frob_interfaces__msg__SignDetection(
  const frob_interfaces__msg__SignDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: sign_type
  {
    cdr << ros_message->sign_type;
  }

  // Field name: distance
  {
    cdr << ros_message->distance;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: detected
  {
    cdr << (ros_message->detected ? true : false);
  }

  // Field name: bbox_center_x
  {
    cdr << ros_message->bbox_center_x;
  }

  // Field name: bbox_center_y
  {
    cdr << ros_message->bbox_center_y;
  }

  // Field name: bbox_width
  {
    cdr << ros_message->bbox_width;
  }

  // Field name: bbox_height
  {
    cdr << ros_message->bbox_height;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
bool cdr_deserialize_frob_interfaces__msg__SignDetection(
  eprosima::fastcdr::Cdr & cdr,
  frob_interfaces__msg__SignDetection * ros_message)
{
  // Field name: sign_type
  {
    cdr >> ros_message->sign_type;
  }

  // Field name: distance
  {
    cdr >> ros_message->distance;
  }

  // Field name: confidence
  {
    cdr >> ros_message->confidence;
  }

  // Field name: detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->detected = tmp ? true : false;
  }

  // Field name: bbox_center_x
  {
    cdr >> ros_message->bbox_center_x;
  }

  // Field name: bbox_center_y
  {
    cdr >> ros_message->bbox_center_y;
  }

  // Field name: bbox_width
  {
    cdr >> ros_message->bbox_width;
  }

  // Field name: bbox_height
  {
    cdr >> ros_message->bbox_height;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
size_t get_serialized_size_frob_interfaces__msg__SignDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SignDetection__ros_msg_type * ros_message = static_cast<const _SignDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: sign_type
  {
    size_t item_size = sizeof(ros_message->sign_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: distance
  {
    size_t item_size = sizeof(ros_message->distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: detected
  {
    size_t item_size = sizeof(ros_message->detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bbox_center_x
  {
    size_t item_size = sizeof(ros_message->bbox_center_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bbox_center_y
  {
    size_t item_size = sizeof(ros_message->bbox_center_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bbox_width
  {
    size_t item_size = sizeof(ros_message->bbox_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bbox_height
  {
    size_t item_size = sizeof(ros_message->bbox_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
size_t max_serialized_size_frob_interfaces__msg__SignDetection(
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

  // Field name: sign_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: distance
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: bbox_center_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: bbox_center_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: bbox_width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: bbox_height
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
    using DataType = frob_interfaces__msg__SignDetection;
    is_plain =
      (
      offsetof(DataType, bbox_height) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
bool cdr_serialize_key_frob_interfaces__msg__SignDetection(
  const frob_interfaces__msg__SignDetection * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: sign_type
  {
    cdr << ros_message->sign_type;
  }

  // Field name: distance
  {
    cdr << ros_message->distance;
  }

  // Field name: confidence
  {
    cdr << ros_message->confidence;
  }

  // Field name: detected
  {
    cdr << (ros_message->detected ? true : false);
  }

  // Field name: bbox_center_x
  {
    cdr << ros_message->bbox_center_x;
  }

  // Field name: bbox_center_y
  {
    cdr << ros_message->bbox_center_y;
  }

  // Field name: bbox_width
  {
    cdr << ros_message->bbox_width;
  }

  // Field name: bbox_height
  {
    cdr << ros_message->bbox_height;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
size_t get_serialized_size_key_frob_interfaces__msg__SignDetection(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SignDetection__ros_msg_type * ros_message = static_cast<const _SignDetection__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: sign_type
  {
    size_t item_size = sizeof(ros_message->sign_type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: distance
  {
    size_t item_size = sizeof(ros_message->distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: confidence
  {
    size_t item_size = sizeof(ros_message->confidence);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: detected
  {
    size_t item_size = sizeof(ros_message->detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bbox_center_x
  {
    size_t item_size = sizeof(ros_message->bbox_center_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bbox_center_y
  {
    size_t item_size = sizeof(ros_message->bbox_center_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bbox_width
  {
    size_t item_size = sizeof(ros_message->bbox_width);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: bbox_height
  {
    size_t item_size = sizeof(ros_message->bbox_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_frob_interfaces
size_t max_serialized_size_key_frob_interfaces__msg__SignDetection(
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
  // Field name: sign_type
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: distance
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: confidence
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: detected
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: bbox_center_x
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: bbox_center_y
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: bbox_width
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: bbox_height
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
    using DataType = frob_interfaces__msg__SignDetection;
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
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const frob_interfaces__msg__SignDetection * ros_message = static_cast<const frob_interfaces__msg__SignDetection *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_frob_interfaces__msg__SignDetection(ros_message, cdr);
}

static bool _SignDetection__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  frob_interfaces__msg__SignDetection * ros_message = static_cast<frob_interfaces__msg__SignDetection *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_frob_interfaces__msg__SignDetection(cdr, ros_message);
}

static uint32_t _SignDetection__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_frob_interfaces__msg__SignDetection(
      untyped_ros_message, 0));
}

static size_t _SignDetection__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_frob_interfaces__msg__SignDetection(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SignDetection = {
  "frob_interfaces::msg",
  "SignDetection",
  _SignDetection__cdr_serialize,
  _SignDetection__cdr_deserialize,
  _SignDetection__get_serialized_size,
  _SignDetection__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SignDetection__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SignDetection,
  get_message_typesupport_handle_function,
  &frob_interfaces__msg__SignDetection__get_type_hash,
  &frob_interfaces__msg__SignDetection__get_type_description,
  &frob_interfaces__msg__SignDetection__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, frob_interfaces, msg, SignDetection)() {
  return &_SignDetection__type_support;
}

#if defined(__cplusplus)
}
#endif
