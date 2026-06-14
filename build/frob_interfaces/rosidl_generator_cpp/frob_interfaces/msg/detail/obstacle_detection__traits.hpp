// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from frob_interfaces:msg/ObstacleDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/obstacle_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__TRAITS_HPP_
#define FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "frob_interfaces/msg/detail/obstacle_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace frob_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObstacleDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: blocked
  {
    out << "blocked: ";
    rosidl_generator_traits::value_to_yaml(msg.blocked, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: zone_width
  {
    out << "zone_width: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_width, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObstacleDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: blocked
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blocked: ";
    rosidl_generator_traits::value_to_yaml(msg.blocked, out);
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

  // member: zone_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_width: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_width, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObstacleDetection & msg, bool use_flow_style = false)
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
  const frob_interfaces::msg::ObstacleDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  frob_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use frob_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const frob_interfaces::msg::ObstacleDetection & msg)
{
  return frob_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<frob_interfaces::msg::ObstacleDetection>()
{
  return "frob_interfaces::msg::ObstacleDetection";
}

template<>
inline const char * name<frob_interfaces::msg::ObstacleDetection>()
{
  return "frob_interfaces/msg/ObstacleDetection";
}

template<>
struct has_fixed_size<frob_interfaces::msg::ObstacleDetection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<frob_interfaces::msg::ObstacleDetection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<frob_interfaces::msg::ObstacleDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__TRAITS_HPP_
