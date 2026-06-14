// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from frob_interfaces:msg/LineDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/line_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__STRUCT_HPP_
#define FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__frob_interfaces__msg__LineDetection __attribute__((deprecated))
#else
# define DEPRECATED__frob_interfaces__msg__LineDetection __declspec(deprecated)
#endif

namespace frob_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LineDetection_
{
  using Type = LineDetection_<ContainerAllocator>;

  explicit LineDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->lateral_error = 0.0f;
      this->angle_error = 0.0f;
      this->confidence = 0.0f;
      this->line_center_x = 0.0f;
      this->line_center_y = 0.0f;
    }
  }

  explicit LineDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->detected = false;
      this->lateral_error = 0.0f;
      this->angle_error = 0.0f;
      this->confidence = 0.0f;
      this->line_center_x = 0.0f;
      this->line_center_y = 0.0f;
    }
  }

  // field types and members
  using _detected_type =
    bool;
  _detected_type detected;
  using _lateral_error_type =
    float;
  _lateral_error_type lateral_error;
  using _angle_error_type =
    float;
  _angle_error_type angle_error;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _line_center_x_type =
    float;
  _line_center_x_type line_center_x;
  using _line_center_y_type =
    float;
  _line_center_y_type line_center_y;

  // setters for named parameter idiom
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }
  Type & set__lateral_error(
    const float & _arg)
  {
    this->lateral_error = _arg;
    return *this;
  }
  Type & set__angle_error(
    const float & _arg)
  {
    this->angle_error = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__line_center_x(
    const float & _arg)
  {
    this->line_center_x = _arg;
    return *this;
  }
  Type & set__line_center_y(
    const float & _arg)
  {
    this->line_center_y = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    frob_interfaces::msg::LineDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const frob_interfaces::msg::LineDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<frob_interfaces::msg::LineDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<frob_interfaces::msg::LineDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      frob_interfaces::msg::LineDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<frob_interfaces::msg::LineDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      frob_interfaces::msg::LineDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<frob_interfaces::msg::LineDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<frob_interfaces::msg::LineDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<frob_interfaces::msg::LineDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__frob_interfaces__msg__LineDetection
    std::shared_ptr<frob_interfaces::msg::LineDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__frob_interfaces__msg__LineDetection
    std::shared_ptr<frob_interfaces::msg::LineDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LineDetection_ & other) const
  {
    if (this->detected != other.detected) {
      return false;
    }
    if (this->lateral_error != other.lateral_error) {
      return false;
    }
    if (this->angle_error != other.angle_error) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->line_center_x != other.line_center_x) {
      return false;
    }
    if (this->line_center_y != other.line_center_y) {
      return false;
    }
    return true;
  }
  bool operator!=(const LineDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LineDetection_

// alias to use template instance with default allocator
using LineDetection =
  frob_interfaces::msg::LineDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__MSG__DETAIL__LINE_DETECTION__STRUCT_HPP_
