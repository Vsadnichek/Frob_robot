// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from frob_interfaces:msg/IntersectionDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "frob_interfaces/msg/detail/intersection_detection__rosidl_typesupport_introspection_c.h"
#include "frob_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "frob_interfaces/msg/detail/intersection_detection__functions.h"
#include "frob_interfaces/msg/detail/intersection_detection__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  frob_interfaces__msg__IntersectionDetection__init(message_memory);
}

void frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_fini_function(void * message_memory)
{
  frob_interfaces__msg__IntersectionDetection__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_message_member_array[3] = {
  {
    "junction_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frob_interfaces__msg__IntersectionDetection, junction_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frob_interfaces__msg__IntersectionDetection, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "detected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frob_interfaces__msg__IntersectionDetection, detected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_message_members = {
  "frob_interfaces__msg",  // message namespace
  "IntersectionDetection",  // message name
  3,  // number of fields
  sizeof(frob_interfaces__msg__IntersectionDetection),
  false,  // has_any_key_member_
  frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_message_member_array,  // message members
  frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_message_type_support_handle = {
  0,
  &frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_message_members,
  get_message_typesupport_handle_function,
  &frob_interfaces__msg__IntersectionDetection__get_type_hash,
  &frob_interfaces__msg__IntersectionDetection__get_type_description,
  &frob_interfaces__msg__IntersectionDetection__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_frob_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, frob_interfaces, msg, IntersectionDetection)() {
  if (!frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_message_type_support_handle.typesupport_identifier) {
    frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &frob_interfaces__msg__IntersectionDetection__rosidl_typesupport_introspection_c__IntersectionDetection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
