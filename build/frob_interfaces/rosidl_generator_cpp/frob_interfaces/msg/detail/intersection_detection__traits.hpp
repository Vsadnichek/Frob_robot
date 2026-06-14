// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from frob_interfaces:msg/IntersectionDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/intersection_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__TRAITS_HPP_
#define FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "frob_interfaces/msg/detail/intersection_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace frob_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const IntersectionDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: junction_type
  {
    out << "junction_type: ";
    rosidl_generator_traits::value_to_yaml(msg.junction_type, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IntersectionDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: junction_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "junction_type: ";
    rosidl_generator_traits::value_to_yaml(msg.junction_type, out);
    out << "\n";
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IntersectionDetection & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace frob_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use frob_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const frob_interfaces::msg::IntersectionDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  frob_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use frob_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const frob_interfaces::msg::IntersectionDetection & msg)
{
  return frob_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<frob_interfaces::msg::IntersectionDetection>()
{
  return "frob_interfaces::msg::IntersectionDetection";
}

template<>
inline const char * name<frob_interfaces::msg::IntersectionDetection>()
{
  return "frob_interfaces/msg/IntersectionDetection";
}

template<>
struct has_fixed_size<frob_interfaces::msg::IntersectionDetection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<frob_interfaces::msg::IntersectionDetection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<frob_interfaces::msg::IntersectionDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__TRAITS_HPP_
