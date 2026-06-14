#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to frob_interfaces__srv__Turn_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Turn_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub angle: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: i32,

}



impl Default for Turn_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Turn_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Turn_Request {
  type RmwMsg = super::srv::rmw::Turn_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        angle: msg.angle,
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      angle: msg.angle,
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      angle: msg.angle,
      speed: msg.speed,
    }
  }
}


// Corresponds to frob_interfaces__srv__Turn_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Turn_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Turn_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Turn_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Turn_Response {
  type RmwMsg = super::srv::rmw::Turn_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}


// Corresponds to frob_interfaces__srv__Forward_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Forward_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub dist: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub speed: i32,

}



impl Default for Forward_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Forward_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Forward_Request {
  type RmwMsg = super::srv::rmw::Forward_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        dist: msg.dist,
        speed: msg.speed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      dist: msg.dist,
      speed: msg.speed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      dist: msg.dist,
      speed: msg.speed,
    }
  }
}


// Corresponds to frob_interfaces__srv__Forward_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Forward_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Forward_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Forward_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Forward_Response {
  type RmwMsg = super::srv::rmw::Forward_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
  }
}






#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__srv__Turn() -> *const std::ffi::c_void;
}

// Corresponds to frob_interfaces__srv__Turn
#[allow(missing_docs, non_camel_case_types)]
pub struct Turn;

impl rosidl_runtime_rs::Service for Turn {
    type Request = Turn_Request;
    type Response = Turn_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__srv__Turn() }
    }
}




#[link(name = "frob_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__srv__Forward() -> *const std::ffi::c_void;
}

// Corresponds to frob_interfaces__srv__Forward
#[allow(missing_docs, non_camel_case_types)]
pub struct Forward;

impl rosidl_runtime_rs::Service for Forward {
    type Request = Forward_Request;
    type Response = Forward_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__frob_interfaces__srv__Forward() }
    }
}


