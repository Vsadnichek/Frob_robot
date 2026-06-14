// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from frob_interfaces:msg/ObstacleDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/msg/obstacle_detection.hpp"


#ifndef FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__STRUCT_HPP_
#define FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__frob_interfaces__msg__ObstacleDetection __attribute__((deprecated))
#else
# define DEPRECATED__frob_interfaces__msg__ObstacleDetection __declspec(deprecated)
#endif

namespace frob_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObstacleDetection_
{
  using Type = ObstacleDetection_<ContainerAllocator>;

  explicit ObstacleDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->blocked = false;
      this->distance = 0.0f;
      this->zone_width = 0.0f;
    }
  }

  explicit ObstacleDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->blocked = false;
      this->distance = 0.0f;
      this->zone_width = 0.0f;
    }
  }

  // field types and members
  using _blocked_type =
    bool;
  _blocked_type blocked;
  using _distance_type =
    float;
  _distance_type distance;
  using _zone_width_type =
    float;
  _zone_width_type zone_width;

  // setters for named parameter idiom
  Type & set__blocked(
    const bool & _arg)
  {
    this->blocked = _arg;
    return *this;
  }
  Type & set__distance(
    const float & _arg)
  {
    this->distance = _arg;
    return *this;
  }
  Type & set__zone_width(
    const float & _arg)
  {
    this->zone_width = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    frob_interfaces::msg::ObstacleDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const frob_interfaces::msg::ObstacleDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<frob_interfaces::msg::ObstacleDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<frob_interfaces::msg::ObstacleDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      frob_interfaces::msg::ObstacleDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<frob_interfaces::msg::ObstacleDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      frob_interfaces::msg::ObstacleDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<frob_interfaces::msg::ObstacleDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<frob_interfaces::msg::ObstacleDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<frob_interfaces::msg::ObstacleDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__frob_interfaces__msg__ObstacleDetection
    std::shared_ptr<frob_interfaces::msg::ObstacleDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__frob_interfaces__msg__ObstacleDetection
    std::shared_ptr<frob_interfaces::msg::ObstacleDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObstacleDetection_ & other) const
  {
    if (this->blocked != other.blocked) {
      return false;
    }
    if (this->distance != other.distance) {
      return false;
    }
    if (this->zone_width != other.zone_width) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObstacleDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObstacleDetection_

// alias to use template instance with default allocator
using ObstacleDetection =
  frob_interfaces::msg::ObstacleDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__MSG__DETAIL__OBSTACLE_DETECTION__STRUCT_HPP_
