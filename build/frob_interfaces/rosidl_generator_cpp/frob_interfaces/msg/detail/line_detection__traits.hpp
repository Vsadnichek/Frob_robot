// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from frob_interfaces:msg/LineDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/line_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__TRAITS_HPP_
#define FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "frob_interfaces/msg/detail/line_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace frob_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const LineDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << ", ";
  }

  // member: lateral_error
  {
    out << "lateral_error: ";
    rosidl_generator_traits::value_to_yaml(msg.lateral_error, out);
    out << ", ";
  }

  // member: angle_error
  {
    out << "angle_error: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_error, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: line_center_x
  {
    out << "line_center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.line_center_x, out);
    out << ", ";
  }

  // member: line_center_y
  {
    out << "line_center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.line_center_y, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LineDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << "\n";
  }

  // member: lateral_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lateral_error: ";
    rosidl_generator_traits::value_to_yaml(msg.lateral_error, out);
    out << "\n";
  }

  // member: angle_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_error: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_error, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: line_center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "line_center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.line_center_x, out);
    out << "\n";
  }

  // member: line_center_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "line_center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.line_center_y, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LineDetection & msg, bool use_flow_style = false)
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
  const frob_interfaces::msg::LineDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  frob_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use frob_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const frob_interfaces::msg::LineDetection & msg)
{
  return frob_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<frob_interfaces::msg::LineDetection>()
{
  return "frob_interfaces::msg::LineDetection";
}

template<>
inline const char * name<frob_interfaces::msg::LineDetection>()
{
  return "frob_interfaces/msg/LineDetection";
}

template<>
struct has_fixed_size<frob_interfaces::msg::LineDetection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<frob_interfaces::msg::LineDetection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<frob_interfaces::msg::LineDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__TRAITS_HPP_
