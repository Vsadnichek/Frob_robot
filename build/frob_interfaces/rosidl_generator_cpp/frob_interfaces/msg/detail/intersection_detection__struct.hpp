// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from frob_interfaces:msg/IntersectionDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/intersection_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__STRUCT_HPP_
#define FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__frob_interfaces__msg__IntersectionDetection __attribute__((deprecated))
#else
# define DEPRECATED__frob_interfaces__msg__IntersectionDetection __declspec(deprecated)
#endif

namespace frob_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IntersectionDetection_
{
  using Type = IntersectionDetection_<ContainerAllocator>;

  explicit IntersectionDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->junction_type = 0;
      this->distance = 0.0f;
      this->detected = false;
    }
  }

  explicit IntersectionDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->junction_type = 0;
      this->distance = 0.0f;
      this->detected = false;
    }
  }

  // field types and members
  using _junction_type_type =
    uint8_t;
  _junction_type_type junction_type;
  using _distance_type =
    float;
  _distance_type distance;
  using _detected_type =
    bool;
  _detected_type detected;

  // setters for named parameter idiom
  Type & set__junction_type(
    const uint8_t & _arg)
  {
    this->junction_type = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__detected(
    const bool & _arg)
  {
    this->detected = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t NONE =
    0u;
  static constexpr uint8_t T_LEFT =
    1u;
  static constexpr uint8_t T_RIGHT =
    2u;
  static constexpr uint8_t T_FORWARD =
    3u;
  static constexpr uint8_t CORNER_LEFT =
    4u;
  static constexpr uint8_t CORNER_RIGHT =
    5u;
  static constexpr uint8_t CROSSROAD =
    6u;

  // pointer types
  using RawPtr =
    frob_interfaces::msg::IntersectionDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const frob_interfaces::msg::IntersectionDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<frob_interfaces::msg::IntersectionDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<frob_interfaces::msg::IntersectionDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      frob_interfaces::msg::IntersectionDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<frob_interfaces::msg::IntersectionDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      frob_interfaces::msg::IntersectionDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<frob_interfaces::msg::IntersectionDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<frob_interfaces::msg::IntersectionDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<frob_interfaces::msg::IntersectionDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__frob_interfaces__msg__IntersectionDetection
    std::shared_ptr<frob_interfaces::msg::IntersectionDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__frob_interfaces__msg__IntersectionDetection
    std::shared_ptr<frob_interfaces::msg::IntersectionDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IntersectionDetection_ & other) const
  {
    if (this->junction_type != other.junction_type) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->detected != other.detected) {
      return false;
    }
    return true;
  }
  bool operator!=(const IntersectionDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IntersectionDetection_

// alias to use template instance with default allocator
using IntersectionDetection =
  frob_interfaces::msg::IntersectionDetection_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t IntersectionDetection_<ContainerAllocator>::NONE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t IntersectionDetection_<ContainerAllocator>::T_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t IntersectionDetection_<ContainerAllocator>::T_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t IntersectionDetection_<ContainerAllocator>::T_FORWARD;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t IntersectionDetection_<ContainerAllocator>::CORNER_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t IntersectionDetection_<ContainerAllocator>::CORNER_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t IntersectionDetection_<ContainerAllocator>::CROSSROAD;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__MSG__DETAIL__INTERSECTION_DETECTION__STRUCT_HPP_
