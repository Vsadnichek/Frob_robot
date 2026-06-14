// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from frob_interfaces:msg/SignDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/sign_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__TRAITS_HPP_
#define FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "frob_interfaces/msg/detail/sign_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace frob_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SignDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: sign_type
  {
    out << "sign_type: ";
    rosidl_generator_traits::value_to_yaml(msg.sign_type, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: detected
  {
    out << "detected: ";
    rosidl_generator_traits::value_to_yaml(msg.detected, out);
    out << ", ";
  }

  // member: bbox_center_x
  {
    out << "bbox_center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_center_x, out);
    out << ", ";
  }

  // member: bbox_center_y
  {
    out << "bbox_center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_center_y, out);
    out << ", ";
  }

  // member: bbox_width
  {
    out << "bbox_width: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_width, out);
    out << ", ";
  }

  // member: bbox_height
  {
    out << "bbox_height: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_height, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SignDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sign_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sign_type: ";
    rosidl_generator_traits::value_to_yaml(msg.sign_type, out);
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

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
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

  // member: bbox_center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_center_x, out);
    out << "\n";
  }

  // member: bbox_center_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_center_y, out);
    out << "\n";
  }

  // member: bbox_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_width: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_width, out);
    out << "\n";
  }

  // member: bbox_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_height: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_height, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SignDetection & msg, bool use_flow_style = false)
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
  const frob_interfaces::msg::SignDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  frob_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use frob_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const frob_interfaces::msg::SignDetection & msg)
{
  return frob_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<frob_interfaces::msg::SignDetection>()
{
  return "frob_interfaces::msg::SignDetection";
}

template<>
inline const char * name<frob_interfaces::msg::SignDetection>()
{
  return "frob_interfaces/msg/SignDetection";
}

template<>
struct has_fixed_size<frob_interfaces::msg::SignDetection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<frob_interfaces::msg::SignDetection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<frob_interfaces::msg::SignDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__TRAITS_HPP_
