// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from frob_interfaces:msg/IntersectionDetection.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "frob_interfaces/msg/detail/intersection_detection__functions.h"
#include "frob_interfaces/msg/detail/intersection_detection__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace frob_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void IntersectionDetection_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) frob_interfaces::msg::IntersectionDetection(_init);
}

void IntersectionDetection_fini_function(void * message_memory)
{
  auto typed_message = static_cast<frob_interfaces::msg::IntersectionDetection *>(message_memory);
  typed_message->~IntersectionDetection();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember IntersectionDetection_message_member_array[3] = {
  {
    "junction_type",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frob_interfaces::msg::IntersectionDetection, junction_type),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "distance",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frob_interfaces::msg::IntersectionDetection, distance),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "detected",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(frob_interfaces::msg::IntersectionDetection, detected),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers IntersectionDetection_message_members = {
  "frob_interfaces::msg",  // message namespace
  "IntersectionDetection",  // message name
  3,  // number of fields
  sizeof(frob_interfaces::msg::IntersectionDetection),
  false,  // has_any_key_member_
  IntersectionDetection_message_member_array,  // message members
  IntersectionDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  IntersectionDetection_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t IntersectionDetection_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &IntersectionDetection_message_members,
  get_message_typesupport_handle_function,
  &frob_interfaces__msg__IntersectionDetection__get_type_hash,
  &frob_interfaces__msg__IntersectionDetection__get_type_description,
  &frob_interfaces__msg__IntersectionDetection__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace frob_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<frob_interfaces::msg::IntersectionDetection>()
{
  return &::frob_interfaces::msg::rosidl_typesupport_introspection_cpp::IntersectionDetection_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, frob_interfaces, msg, IntersectionDetection)() {
  return &::frob_interfaces::msg::rosidl_typesupport_introspection_cpp::IntersectionDetection_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
