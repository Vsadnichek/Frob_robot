// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from frob_interfaces:msg/SignDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/sign_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__BUILDER_HPP_
#define FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "frob_interfaces/msg/detail/sign_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace frob_interfaces
{

namespace msg
{

namespace builder
{

class Init_SignDetection_bbox_height
{
public:
  explicit Init_SignDetection_bbox_height(::frob_interfaces::msg::SignDetection & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::msg::SignDetection bbox_height(::frob_interfaces::msg::SignDetection::_bbox_height_type arg)
  {
    msg_.bbox_height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::msg::SignDetection msg_;
};

class Init_SignDetection_bbox_width
{
public:
  explicit Init_SignDetection_bbox_width(::frob_interfaces::msg::SignDetection & msg)
  : msg_(msg)
  {}
  Init_SignDetection_bbox_height bbox_width(::frob_interfaces::msg::SignDetection::_bbox_width_type arg)
  {
    msg_.bbox_width = std::move(arg);
    return Init_SignDetection_bbox_height(msg_);
  }

private:
  ::frob_interfaces::msg::SignDetection msg_;
};

class Init_SignDetection_bbox_center_y
{
public:
  explicit Init_SignDetection_bbox_center_y(::frob_interfaces::msg::SignDetection & msg)
  : msg_(msg)
  {}
  Init_SignDetection_bbox_width bbox_center_y(::frob_interfaces::msg::SignDetection::_bbox_center_y_type arg)
  {
    msg_.bbox_center_y = std::move(arg);
    return Init_SignDetection_bbox_width(msg_);
  }

private:
  ::frob_interfaces::msg::SignDetection msg_;
};

class Init_SignDetection_bbox_center_x
{
public:
  explicit Init_SignDetection_bbox_center_x(::frob_interfaces::msg::SignDetection & msg)
  : msg_(msg)
  {}
  Init_SignDetection_bbox_center_y bbox_center_x(::frob_interfaces::msg::SignDetection::_bbox_center_x_type arg)
  {
    msg_.bbox_center_x = std::move(arg);
    return Init_SignDetection_bbox_center_y(msg_);
  }

private:
  ::frob_interfaces::msg::SignDetection msg_;
};

class Init_SignDetection_detected
{
public:
  explicit Init_SignDetection_detected(::frob_interfaces::msg::SignDetection & msg)
  : msg_(msg)
  {}
  Init_SignDetection_bbox_center_x detected(::frob_interfaces::msg::SignDetection::_detected_type arg)
  {
    msg_.detected = std::move(arg);
    return Init_SignDetection_bbox_center_x(msg_);
  }

private:
  ::frob_interfaces::msg::SignDetection msg_;
};

class Init_SignDetection_confidence
{
public:
  explicit Init_SignDetection_confidence(::frob_interfaces::msg::SignDetection & msg)
  : msg_(msg)
  {}
  Init_SignDetection_detected confidence(::frob_interfaces::msg::SignDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_SignDetection_detected(msg_);
  }

private:
  ::frob_interfaces::msg::SignDetection msg_;
};

class Init_SignDetection_distance
{
public:
  explicit Init_SignDetection_distance(::frob_interfaces::msg::SignDetection & msg)
  : msg_(msg)
  {}
  Init_SignDetection_confidence distance(::frob_interfaces::msg::SignDetection::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_SignDetection_confidence(msg_);
  }

private:
  ::frob_interfaces::msg::SignDetection msg_;
};

class Init_SignDetection_sign_type
{
public:
  Init_SignDetection_sign_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SignDetection_distance sign_type(::frob_interfaces::msg::SignDetection::_sign_type_type arg)
  {
    msg_.sign_type = std::move(arg);
    return Init_SignDetection_distance(msg_);
  }

private:
  ::frob_interfaces::msg::SignDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::msg::SignDetection>()
{
  return frob_interfaces::msg::builder::Init_SignDetection_sign_type();
}

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__MSG__DETAIL__SIGN_DETECTION__BUILDER_HPP_
