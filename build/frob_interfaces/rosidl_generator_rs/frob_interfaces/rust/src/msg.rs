#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to frob_interfaces__msg__LineDetection

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct LineDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub lateral_error: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub angle_error: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub line_center_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub line_center_y: f32,

}



impl Default for LineDetection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::LineDetection::default())
  }
}

impl rosidl_runtime_rs::Message for LineDetection {
  type RmwMsg = super::msg::rmw::LineDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        detected: msg.detected,
        lateral_error: msg.lateral_error,
        angle_error: msg.angle_error,
        confidence: msg.confidence,
        line_center_x: msg.line_center_x,
        line_center_y: msg.line_center_y,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      detected: msg.detected,
      lateral_error: msg.lateral_error,
      angle_error: msg.angle_error,
      confidence: msg.confidence,
      line_center_x: msg.line_center_x,
      line_center_y: msg.line_center_y,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      detected: msg.detected,
      lateral_error: msg.lateral_error,
      angle_error: msg.angle_error,
      confidence: msg.confidence,
      line_center_x: msg.line_center_x,
      line_center_y: msg.line_center_y,
    }
  }
}


// Corresponds to frob_interfaces__msg__SignDetection

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SignDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub sign_type: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub confidence: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_center_x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_center_y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_width: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_height: f32,

}

impl SignDetection {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const UNKNOWN: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GO_STRAIGHT: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GO_LEFT: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const GO_RIGHT: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NO_LEFT_TURN: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NO_RIGHT_TURN: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const BUS_STOP: u8 = 6;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const PARKING: u8 = 7;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DANGER: u8 = 8;

}


impl Default for SignDetection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::SignDetection::default())
  }
}

impl rosidl_runtime_rs::Message for SignDetection {
  type RmwMsg = super::msg::rmw::SignDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        sign_type: msg.sign_type,
        distance: msg.distance,
        confidence: msg.confidence,
        detected: msg.detected,
        bbox_center_x: msg.bbox_center_x,
        bbox_center_y: msg.bbox_center_y,
        bbox_width: msg.bbox_width,
        bbox_height: msg.bbox_height,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      sign_type: msg.sign_type,
      distance: msg.distance,
      confidence: msg.confidence,
      detected: msg.detected,
      bbox_center_x: msg.bbox_center_x,
      bbox_center_y: msg.bbox_center_y,
      bbox_width: msg.bbox_width,
      bbox_height: msg.bbox_height,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      sign_type: msg.sign_type,
      distance: msg.distance,
      confidence: msg.confidence,
      detected: msg.detected,
      bbox_center_x: msg.bbox_center_x,
      bbox_center_y: msg.bbox_center_y,
      bbox_width: msg.bbox_width,
      bbox_height: msg.bbox_height,
    }
  }
}


// Corresponds to frob_interfaces__msg__IntersectionDetection

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct IntersectionDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub junction_type: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub detected: bool,

}

impl IntersectionDetection {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NONE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const T_LEFT: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const T_RIGHT: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const T_FORWARD: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CORNER_LEFT: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CORNER_RIGHT: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CROSSROAD: u8 = 6;

}


impl Default for IntersectionDetection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::IntersectionDetection::default())
  }
}

impl rosidl_runtime_rs::Message for IntersectionDetection {
  type RmwMsg = super::msg::rmw::IntersectionDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        junction_type: msg.junction_type,
        distance: msg.distance,
        detected: msg.detected,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      junction_type: msg.junction_type,
      distance: msg.distance,
      detected: msg.detected,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      junction_type: msg.junction_type,
      distance: msg.distance,
      detected: msg.detected,
    }
  }
}


// Corresponds to frob_interfaces__msg__ObstacleDetection

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObstacleDetection {

    // This member is not documented.
    #[allow(missing_docs)]
    pub blocked: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub distance: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub zone_width: f32,

}



impl Default for ObstacleDetection {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ObstacleDetection::default())
  }
}

impl rosidl_runtime_rs::Message for ObstacleDetection {
  type RmwMsg = super::msg::rmw::ObstacleDetection;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        blocked: msg.blocked,
        distance: msg.distance,
        zone_width: msg.zone_width,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      blocked: msg.blocked,
      distance: msg.distance,
      zone_width: msg.zone_width,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      blocked: msg.blocked,
      distance: msg.distance,
      zone_width: msg.zone_width,
    }
  }
}


