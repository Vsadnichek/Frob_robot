// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from frob_interfaces:msg/ObstacleDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/obstacle_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__BUILDER_HPP_
#define FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "frob_interfaces/msg/detail/obstacle_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace frob_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObstacleDetection_zone_width
{
public:
  explicit Init_ObstacleDetection_zone_width(::frob_interfaces::msg::ObstacleDetection & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::msg::ObstacleDetection zone_width(::frob_interfaces::msg::ObstacleDetection::_zone_width_type arg)
  {
    msg_.zone_width = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::msg::ObstacleDetection msg_;
};

class Init_ObstacleDetection_distance
{
public:
  explicit Init_ObstacleDetection_distance(::frob_interfaces::msg::ObstacleDetection & msg)
  : msg_(msg)
  {}
  Init_ObstacleDetection_zone_width distance(::frob_interfaces::msg::ObstacleDetection::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_ObstacleDetection_zone_width(msg_);
  }

private:
  ::frob_interfaces::msg::ObstacleDetection msg_;
};

class Init_ObstacleDetection_blocked
{
public:
  Init_ObstacleDetection_blocked()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObstacleDetection_distance blocked(::frob_interfaces::msg::ObstacleDetection::_blocked_type arg)
  {
    msg_.blocked = std::move(arg);
    return Init_ObstacleDetection_distance(msg_);
  }

private:
  ::frob_interfaces::msg::ObstacleDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::msg::ObstacleDetection>()
{
  return frob_interfaces::msg::builder::Init_ObstacleDetection_blocked();
}

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__BUILDER_HPP_
