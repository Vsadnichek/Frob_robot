// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from frob_interfaces:action/ExecuteMotion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "frob_interfaces/action/execute_motion.hpp"


#ifndef FROB_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__BUILDER_HPP_
#define FROB_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "frob_interfaces/action/detail/execute_motion__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_Goal_value
{
public:
  explicit Init_ExecuteMotion_Goal_value(::frob_interfaces::action::ExecuteMotion_Goal & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::action::ExecuteMotion_Goal value(::frob_interfaces::action::ExecuteMotion_Goal::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_Goal msg_;
};

class Init_ExecuteMotion_Goal_command
{
public:
  Init_ExecuteMotion_Goal_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMotion_Goal_value command(::frob_interfaces::action::ExecuteMotion_Goal::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_ExecuteMotion_Goal_value(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_Goal>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_Goal_command();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_Result_success
{
public:
  Init_ExecuteMotion_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::frob_interfaces::action::ExecuteMotion_Result success(::frob_interfaces::action::ExecuteMotion_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_Result>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_Result_success();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_Feedback_progress
{
public:
  Init_ExecuteMotion_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::frob_interfaces::action::ExecuteMotion_Feedback progress(::frob_interfaces::action::ExecuteMotion_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_Feedback>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_Feedback_progress();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_SendGoal_Request_goal
{
public:
  explicit Init_ExecuteMotion_SendGoal_Request_goal(::frob_interfaces::action::ExecuteMotion_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Request goal(::frob_interfaces::action::ExecuteMotion_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Request msg_;
};

class Init_ExecuteMotion_SendGoal_Request_goal_id
{
public:
  Init_ExecuteMotion_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMotion_SendGoal_Request_goal goal_id(::frob_interfaces::action::ExecuteMotion_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMotion_SendGoal_Request_goal(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_SendGoal_Request>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_SendGoal_Request_goal_id();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_SendGoal_Response_stamp
{
public:
  explicit Init_ExecuteMotion_SendGoal_Response_stamp(::frob_interfaces::action::ExecuteMotion_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Response stamp(::frob_interfaces::action::ExecuteMotion_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Response msg_;
};

class Init_ExecuteMotion_SendGoal_Response_accepted
{
public:
  Init_ExecuteMotion_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMotion_SendGoal_Response_stamp accepted(::frob_interfaces::action::ExecuteMotion_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExecuteMotion_SendGoal_Response_stamp(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_SendGoal_Response>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_SendGoal_Response_accepted();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_SendGoal_Event_response
{
public:
  explicit Init_ExecuteMotion_SendGoal_Event_response(::frob_interfaces::action::ExecuteMotion_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Event response(::frob_interfaces::action::ExecuteMotion_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Event msg_;
};

class Init_ExecuteMotion_SendGoal_Event_request
{
public:
  explicit Init_ExecuteMotion_SendGoal_Event_request(::frob_interfaces::action::ExecuteMotion_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteMotion_SendGoal_Event_response request(::frob_interfaces::action::ExecuteMotion_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteMotion_SendGoal_Event_response(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Event msg_;
};

class Init_ExecuteMotion_SendGoal_Event_info
{
public:
  Init_ExecuteMotion_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMotion_SendGoal_Event_request info(::frob_interfaces::action::ExecuteMotion_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteMotion_SendGoal_Event_request(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_SendGoal_Event>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_SendGoal_Event_info();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_GetResult_Request_goal_id
{
public:
  Init_ExecuteMotion_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::frob_interfaces::action::ExecuteMotion_GetResult_Request goal_id(::frob_interfaces::action::ExecuteMotion_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_GetResult_Request>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_GetResult_Request_goal_id();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_GetResult_Response_result
{
public:
  explicit Init_ExecuteMotion_GetResult_Response_result(::frob_interfaces::action::ExecuteMotion_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::action::ExecuteMotion_GetResult_Response result(::frob_interfaces::action::ExecuteMotion_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_GetResult_Response msg_;
};

class Init_ExecuteMotion_GetResult_Response_status
{
public:
  Init_ExecuteMotion_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMotion_GetResult_Response_result status(::frob_interfaces::action::ExecuteMotion_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteMotion_GetResult_Response_result(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_GetResult_Response>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_GetResult_Response_status();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_GetResult_Event_response
{
public:
  explicit Init_ExecuteMotion_GetResult_Event_response(::frob_interfaces::action::ExecuteMotion_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::action::ExecuteMotion_GetResult_Event response(::frob_interfaces::action::ExecuteMotion_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_GetResult_Event msg_;
};

class Init_ExecuteMotion_GetResult_Event_request
{
public:
  explicit Init_ExecuteMotion_GetResult_Event_request(::frob_interfaces::action::ExecuteMotion_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_ExecuteMotion_GetResult_Event_response request(::frob_interfaces::action::ExecuteMotion_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ExecuteMotion_GetResult_Event_response(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_GetResult_Event msg_;
};

class Init_ExecuteMotion_GetResult_Event_info
{
public:
  Init_ExecuteMotion_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMotion_GetResult_Event_request info(::frob_interfaces::action::ExecuteMotion_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ExecuteMotion_GetResult_Event_request(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_GetResult_Event>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_GetResult_Event_info();
}

}  // namespace frob_interfaces


namespace frob_interfaces
{

namespace action
{

namespace builder
{

class Init_ExecuteMotion_FeedbackMessage_feedback
{
public:
  explicit Init_ExecuteMotion_FeedbackMessage_feedback(::frob_interfaces::action::ExecuteMotion_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::frob_interfaces::action::ExecuteMotion_FeedbackMessage feedback(::frob_interfaces::action::ExecuteMotion_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_FeedbackMessage msg_;
};

class Init_ExecuteMotion_FeedbackMessage_goal_id
{
public:
  Init_ExecuteMotion_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMotion_FeedbackMessage_feedback goal_id(::frob_interfaces::action::ExecuteMotion_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMotion_FeedbackMessage_feedback(msg_);
  }

private:
  ::frob_interfaces::action::ExecuteMotion_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::frob_interfaces::action::ExecuteMotion_FeedbackMessage>()
{
  return frob_interfaces::action::builder::Init_ExecuteMotion_FeedbackMessage_goal_id();
}

}  // namespace frob_interfaces

#endif  // FROB_INTERFACES__ACTION__DETAIL__EXECUTE_MOTION__BUILDER_HPP_
