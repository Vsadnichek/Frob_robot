// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from frob_interfaces:msg/IntersectionDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/intersection_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__BUILDER_HPP_
#define FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "frob_interfaces/msg/detail/intersection_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace frob_interfaces
{

namespace msg
{

namespace builder
{

class Init_IntersectionDetection_detected
{
public:
  explicit Init_IntersectionDetection_detected(::frob_interfaces::msg::IntersectionDetection & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::msg::IntersectionDetection detected(::frob_interfaces::msg::IntersectionDetection::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::msg::IntersectionDetection msg_;
};

class Init_IntersectionDetection_distance
{
public:
  explicit Init_IntersectionDetection_distance(::frob_interfaces::msg::IntersectionDetection & msg)
  : msg_(msg)
  {}
  Init_IntersectionDetection_detected distance(::frob_interfaces::msg::IntersectionDetection::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_IntersectionDetection_detected(msg_);
  }

private:
  ::frob_interfaces::msg::IntersectionDetection msg_;
};

class Init_IntersectionDetection_junction_type
{
public:
  Init_IntersectionDetection_junction_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IntersectionDetection_distance junction_type(::frob_interfaces::msg::IntersectionDetection::_junction_type_type arg)
  {
    msg_.junction_type = std::move(arg);
    return Init_IntersectionDetection_distance(msg_);
  }

private:
  ::frob_interfaces::msg::IntersectionDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::msg::IntersectionDetection>()
{
  return frob_interfaces::msg::builder::Init_IntersectionDetection_junction_type();
}

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__BUILDER_HPP_
