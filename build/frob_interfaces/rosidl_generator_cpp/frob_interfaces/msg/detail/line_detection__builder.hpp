// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from frob_interfaces:msg/LineDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/line_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__BUILDER_HPP_
#define FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "frob_interfaces/msg/detail/line_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace frob_interfaces
{

namespace msg
{

namespace builder
{

class Init_LineDetection_line_center_y
{
public:
  explicit Init_LineDetection_line_center_y(::frob_interfaces::msg::LineDetection & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::msg::LineDetection line_center_y(::frob_interfaces::msg::LineDetection::_line_center_y_type arg)
  {
    msg_.line_center_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::msg::LineDetection msg_;
};

class Init_LineDetection_line_center_x
{
public:
  explicit Init_LineDetection_line_center_x(::frob_interfaces::msg::LineDetection & msg)
  : msg_(msg)
  {}
  Init_LineDetection_line_center_y line_center_x(::frob_interfaces::msg::LineDetection::_line_center_x_type arg)
  {
    msg_.line_center_x = std::move(arg);
    return Init_LineDetection_line_center_y(msg_);
  }

private:
  ::frob_interfaces::msg::LineDetection msg_;
};

class Init_LineDetection_confidence
{
public:
  explicit Init_LineDetection_confidence(::frob_interfaces::msg::LineDetection & msg)
  : msg_(msg)
  {}
  Init_LineDetection_line_center_x confidence(::frob_interfaces::msg::LineDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_LineDetection_line_center_x(msg_);
  }

private:
  ::frob_interfaces::msg::LineDetection msg_;
};

class Init_LineDetection_angle_error
{
public:
  explicit Init_LineDetection_angle_error(::frob_interfaces::msg::LineDetection & msg)
  : msg_(msg)
  {}
  Init_LineDetection_confidence angle_error(::frob_interfaces::msg::LineDetection::_angle_error_type arg)
  {
    msg_.angle_error = std::move(arg);
    return Init_LineDetection_confidence(msg_);
  }

private:
  ::frob_interfaces::msg::LineDetection msg_;
};

class Init_LineDetection_lateral_error
{
public:
  explicit Init_LineDetection_lateral_error(::frob_interfaces::msg::LineDetection & msg)
  : msg_(msg)
  {}
  Init_LineDetection_angle_error lateral_error(::frob_interfaces::msg::LineDetection::_lateral_error_type arg)
  {
    msg_.lateral_error = std::move(arg);
    return Init_LineDetection_angle_error(msg_);
  }

private:
  ::frob_interfaces::msg::LineDetection msg_;
};

class Init_LineDetection_detected
{
public:
  Init_LineDetection_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LineDetection_lateral_error detected(::frob_interfaces::msg::LineDetection::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_LineDetection_lateral_error(msg_);
  }

private:
  ::frob_interfaces::msg::LineDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::msg::LineDetection>()
{
  return frob_interfaces::msg::builder::Init_LineDetection_detected();
}

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__BUILDER_HPP_
