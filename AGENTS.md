# AGENTS.md — frob_robot

## Project Overview

**Autonomous city navigation robot** for the «Кубок РТК Высшая лига» hackathon (coursework).
The robot drives on a 4×4m polygon (5×5 grid of 800mm cells), follows road signs,
stops at pickup zones, and finishes at the drop-off zone.

- **Workspace**: `~/ros2_ws/frob_robot`
- **ROS2 distro**: Jazzy
- **Robot**: Differential drive (21×21 cm base, 2 wheels + 2 casters), Arduino Mega, YDLIDAR X4, MPU6050 IMU, USB camera
- **PC build**: `colcon build --packages-skip ros2_mpu6050` (no I2C on PC)
- **Simulation**: Gazebo Harmonic (`gz-sim8`) via `ros_gz_sim`, TurtleBot 4 model, custom city polygon world

---

## Package Map (14 packages in `src/`)

| Package | Type | Role |
|---------|------|------|
| `frob_interfaces` | CMake | Custom `.msg`, `.srv`, `.action` |
| `frob_bringup` | Python | Master launch for all hardware drivers |
| `frob_control` | Python | Joystick teleop |
| `frob_description` | Python | URDF, TF tree, RViz configs |
| `frob_mission` | Python | **Graph-based path planning + motion execution + simulation** |
| `frob_navigation` | Python | Nav2 / SLAM launch + configs |
| `frob_odometry` | Python | Wheel encoder odometry + EKF |
| `frob_perception` | Python | USB camera driver (V4L2 + compressed transport) |
| `keyboard_vel_control` | Python | Keyboard teleop (alternative) |
| `lidar_filter` | Python | Filters LiDAR points near robot body |
| `rf2o_laser_odometry` | CMake | Laser-based odometry (optional) |
| `ros2_arduino_bridge` | Python | Serial bridge to Arduino (motors/encoders) |
| `ros2_mpu6050` | CMake | MPU6050 IMU driver (I2C, Pi only) |
| `sllidar_ros2` | CMake | YDLIDAR X4 driver |

### External Dependencies (apt-installed)

| Package | Role |
|---------|------|
| `ros-jazzy-turtlebot4-simulator` | TB4 Gazebo model, bridges, launch |
| `ros-jazzy-ros-gz-sim` | ROS ↔ Gazebo integration |
| `ros-jazzy-turtlebot4-description` | TB4 URDF (transitive dep) |
| `ros-jazzy-irobot-create-gz-plugins` | Diff-drive, sensor plugins (transitive dep) |

---

## frob_mission Package — Core Nodes

### 1. `graph_navigator` (`frob_mission/graph_navigator.py`)

Dijkstra-based path planner over the city road graph.

**Parameters:**

| Parameter | YAML Default | CLI Override | Description |
|-----------|-------------|-------------|-------------|
| `start_node` | `13` | `start_node:=` | Start graph node ID |
| `target_node` | `108` | `target_node:=` | Destination graph node ID |
| `initial_heading` | `0.0` | `initial_heading:=` | Initial robot yaw in rad (0=east, π/2=north) |
| `turn_threshold` | `0.08` | — | Min angle diff to insert rotate command (rad) |

**Algorithm:**
1. Loads graph from `config/graph.yaml` (48 nodes, 92 directed edges)
2. Runs Dijkstra with Euclidean edge weights
3. Plans motion commands: for each edge, computes desired heading (`atan2(dy,dx)`), compares with current heading; if `|diff| > turn_threshold` → `rotate(Δθ)`, then `forward(distance)`
4. Sends `ExecuteMotion` action goals sequentially, blocks until each completes
5. Aborts mission on any failure

**Topics used:**
- Action client: `/execute_motion` (`ExecuteMotion` action)
- Reads graph from file (not from topics)

### 2. `motion_executor` (`frob_mission/motion_executor.py`)

Closed-loop motion controller — ActionServer for `execute_motion`.

**Parameters:**

| Parameter | YAML Default | Code Default | Description |
|-----------|-------------|-------------|-------------|
| `forward_speed` | `0.12` | `0.15` | Linear speed (m/s) |
| `rotate_speed` | `1.2` | `1.0` | Max angular speed (rad/s) |
| `forward_tolerance` | `0.02` | `0.02` | Distance tolerance (m) |
| `rotate_tolerance` | `0.05` | `0.05` | Angle tolerance (rad) |
| `kp_angular` | `2.5` | `2.0` | P-gain for rotation controller |

**Forward execution** (50 Hz loop):
- Records start position from `/odometry/filtered`
- Computes `traveled = sqrt(dx²+dy²)`, stays within `forward_tolerance` of target
- Slowdown ramp when `remaining < 0.1m`
- Publishes `Twist.linear.x` to `/cmd_vel`

**Rotate execution** (50 Hz loop):
- Computes target yaw, tracks error via P-controller
- Yaw source priority: `/imu/mpu6050` → fallback to `/odometry/filtered` orientation
- Min angular speed 0.1 rad/s to prevent stalling
- Absolute target (not incremental) — bounded overshoot

**Topics:**
- **Subscribes**: `/odometry/filtered` (Odometry), `/imu/mpu6050` (Imu)
- **Publishes**: `/cmd_vel` (Twist)
- **Action server**: `execute_motion` (ExecuteMotion)

### 3. `topic_relay` (`frob_mission/topic_relay.py`)

Generic topic relay — forwards messages from one topic to another (same type).

```
Usage: topic_relay <from_topic> <to_topic> <msg_type>
Example: topic_relay /odom /odometry/filtered nav_msgs.msg.Odometry
```

Used in simulation launch to map TB4 topics → frob_robot expected names.

---

## frob_mission Package — Launch Files

### `mission.launch.py` — Real Robot Mission

| Argument | Default | Description |
|----------|---------|-------------|
| `start_node` | `13` | Start graph node ID |
| `target_node` | `108` | Target graph node ID |
| `initial_heading` | `0.0` | Initial robot heading (rad) |

Starts: `motion_executor` + `graph_navigator` with `mission_params.yaml`.

```bash
ros2 launch frob_mission mission.launch.py
ros2 launch frob_mission mission.launch.py start_node:=23 target_node:=108 initial_heading:=0.0
```

### `simulation.launch.py` — Gazebo Simulation

| Argument | Default | Description |
|----------|---------|-------------|
| `mode` | `mission` | `city`=polygon only, `tb4`=polygon+robot, `mission`=polygon+robot+mission |
| `world` | `''` (auto) | Override SDF world path (auto-selected by mode if empty) |
| `headless` | `false` | Run Gazebo without GUI |
| `start_node` | `23` | Start graph node ID (mission mode only) |
| `target_node` | `108` | Target graph node ID (mission mode only) |
| `initial_heading` | `0.0` | Initial robot heading (mission mode only) |

**Mode behavior:**

| `mode` | SDF used | Robot | Bridges | Relays | Mission nodes |
|--------|----------|-------|---------|--------|---------------|
| `city` | `city_polygon.sdf` | — | clock only | — | — |
| `tb4` | `city_polygon_tb4.sdf` | TB4 embedded | clock + tb4_bridge | odom, imu | — |
| `mission` | `city_polygon_tb4.sdf` | TB4 embedded | clock + tb4_bridge | odom, imu | motion_executor + graph_navigator |

**Topic mapping in simulation:**
- `/odom` → `/odometry/filtered` (relay)
- `/imu` → `/imu/mpu6050` (relay)
- `/cmd_vel` (direct, same name)
- `/scan` (direct, same name)

**NVIDIA GPU workaround:**
```bash
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia \
__EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/10_nvidia.json \
ros2 launch frob_mission simulation.launch.py mode:=mission
```

---

## Simulation Worlds

### `city_polygon.sdf` (316 lines)
Pure city polygon without robot. Contains:
- Ground plane (centered at 2,2)
- 4 external walls (4×0.1×0.6 m each)
- 5×5 grid lines (12 lines, 0.8m spacing)
- 4 buildings (0.5×0.5×0.6 m) at cells (2,2), (2,4), (4,2), (4,4)
- 48 node markers (green cylinders at graph.yaml coordinates)

### `city_polygon_tb4.sdf` (1845 lines)
Same as `city_polygon.sdf` + embedded TurtleBot 4 robot model:
- `<scale>0.68 0.68 0.68</scale>` — scales TB4 from 31cm → ~21cm width
- `<pose>0.6 0.8 0.01 0 0 1.5708</pose>` — spawn at node 23, facing north
- Full SDF generated from `nav2_minimal_tb4_description` URDF via `gz sdf -p`

---

## frob_perception Package

### `camera_node` (`frob_perception/camera_node.py`)

USB camera driver with compressed transport.

**Parameters:**

| Parameter | Default | Description |
|-----------|---------|-------------|
| `device` | `0` | V4L2 device index (`0` = `/dev/video0`) |
| `width` | `640` | Frame width |
| `height` | `480` | Frame height |
| `fps` | `30.0` | Target framerate |
| `fourcc` | `'MJPG'` | V4L2 codec (set to `''` for auto) |
| `publish_compressed` | `true` | Also publish JPEG-compressed topic |
| `jpeg_quality` | `80` | JPEG quality 1–100 |

**Topics published:**
- `/camera/image_raw` — raw BGR8 (Image, 640×480×3 ≈ 900 KB/frame)
- `/camera/image_raw/compressed` — JPEG (CompressedImage, ~44 KB/frame, 20× smaller)

**Key fixes applied:**
- Explicit `cv2.CAP_V4L2` backend (fixes GStreamer pipeline failures on built-in cameras)
- `fourcc` set BEFORE width/height (required by V4L2 drivers)
- 0.2s warmup + 3 discard reads after camera open
- Compressed topic solves remote WiFi bandwidth issue (2 Hz raw → 25 Hz compressed)

### `perception.launch.py`

| Argument | Default | Description |
|----------|---------|-------------|
| `camera_device` | `0` | Camera device index |

```bash
ros2 run frob_perception camera_node
ros2 launch frob_perception perception.launch.py
```

---

## Custom Interfaces (`frob_interfaces`)

### Messages (4)
- **`LineDetection`** — `detected` (bool), `lateral_error`, `angle_error`, `confidence`, `line_center_x/y`
- **`SignDetection`** — `sign_type` (UNKNOWN=0, GO_STRAIGHT=1, GO_LEFT=2, GO_RIGHT=3, NO_LEFT_TURN=4, NO_RIGHT_TURN=5, BUS_STOP=6, PARKING=7, DANGER=8), `distance`, `confidence`, `detected`, `bbox_*`
- **`IntersectionDetection`** — `junction_type` (NONE=0, T_LEFT=1, T_RIGHT=2, T_FORWARD=3, CORNER_LEFT=4, CORNER_RIGHT=5, CROSSROAD=6), `distance`, `detected`
- **`ObstacleDetection`** — `blocked`, `distance`, `zone_width`

### Services (2)
- **`Turn`** — `int32 angle, int32 speed → bool success`
- **`Forward`** — `int32 dist, int32 speed → bool success`

### Actions (1)
- **`ExecuteMotion`** — `string command ("forward"|"rotate"), float32 value (m|rad) → bool success`, feedback: `float32 progress`

---

## All Topics

### Hardware (real robot)

| Topic | Type | Publisher |
|-------|------|-----------|
| `/scan` | LaserScan | `sllidar_node` |
| `/scan/filtered` | LaserScan | `lidar_filter` |
| `/odom` | Odometry | `wheel_odometry` |
| `/odometry/filtered` | Odometry | `ekf_filter_node` |
| `/imu/mpu6050` | Imu | `mpu6050_sensor` |
| `/cmd_vel` | Twist | `motion_executor`, teleop nodes |
| `/camera/image_raw` | Image | `camera_node` |
| `/camera/image_raw/compressed` | CompressedImage | `camera_node` |
| `left_motor/encoder/delta` | Int32 | `arduino_bridge` |
| `right_motor/encoder/delta` | Int32 | `arduino_bridge` |
| `left_motor/speed` | Float32 | `arduino_bridge` |
| `right_motor/speed` | Float32 | `arduino_bridge` |

### Simulation (TB4 in Gazebo)

| Topic | Type | Source | Notes |
|-------|------|--------|-------|
| `/odom` | Odometry | `ros_gz_bridge` ← GZ diff-drive plugin | Relayed → `/odometry/filtered` |
| `/odometry/filtered` | Odometry | `topic_relay` ← `/odom` | Consumed by `motion_executor` |
| `/imu` | Imu | `ros_gz_bridge` ← GZ IMU sensor | ⚠️ Not publishing (GZ sensor issue) |
| `/imu/mpu6050` | Imu | `topic_relay` ← `/imu` | Empty — `motion_executor` uses odom yaw fallback |
| `/scan` | LaserScan | `ros_gz_bridge` ← GZ RPLIDAR | |
| `/cmd_vel` | Twist | `motion_executor` → GZ diff-drive | |
| `/clock` | Clock | `ros_gz_bridge` ← GZ | Sim time |
| `/tf` | TFMessage | `ros_gz_bridge` ← GZ | Robot link transforms |
| `/joint_states` | JointState | `ros_gz_bridge` ← GZ | |

### Services (hardware)

| Service | Type | Provider |
|---------|------|----------|
| `rotate_robot` | Turn.srv | `arduino_bridge` |
| `forward_robot` | Forward.srv | `arduino_bridge` |

### Actions

| Action | Type | Server |
|--------|------|--------|
| `execute_motion` | ExecuteMotion | `motion_executor` |

---

## Navigation Graph

File: `src/frob_mission/config/graph.yaml`. **48 nodes, 92 directed edges**.

Coordinate system: meters from left-bottom corner (0,0) of 4×4m polygon.

**Node ID encoding**: `"XY"` where X and Y are grid indices (1–10), mapped to coordinates via lookup table:

| Index | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|-------|---|---|---|---|---|---|---|---|---|----|
| Meter | 0.2 | 0.6 | 0.8 | 1.6 | 1.8 | 2.2 | 2.4 | 3.2 | 3.4 | 3.8 |

Special: IDs ending in `10` (e.g., `310`) → Y=10 (3.8m). Otherwise last digit = Y index.

### Node Coordinates (all 48)

| ID | (x, y) | ID | (x, y) | ID | (x, y) | ID | (x, y) |
|----|--------|----|--------|----|--------|----|--------|
| 13 | (0.2, 0.8) | 14 | (0.2, 1.6) | 17 | (0.2, 2.4) | 18 | (0.2, 3.2) |
| 23 | (0.6, 0.8) | 24 | (0.6, 1.6) | 27 | (0.6, 2.4) | 28 | (0.6, 3.2) |
| 31 | (0.8, 0.2) | 32 | (0.8, 0.6) | 35 | (0.8, 1.8) | 36 | (0.8, 2.2) |
| 39 | (0.8, 3.4) | 41 | (1.6, 0.2) | 42 | (1.6, 0.6) | 45 | (1.6, 1.8) |
| 46 | (1.6, 2.2) | 49 | (1.6, 3.4) | 53 | (1.8, 0.8) | 54 | (1.8, 1.6) |
| 57 | (1.8, 2.4) | 58 | (1.8, 3.2) | 63 | (2.2, 0.8) | 64 | (2.2, 1.6) |
| 67 | (2.2, 2.4) | 68 | (2.2, 3.2) | 71 | (2.4, 0.2) | 72 | (2.4, 0.6) |
| 75 | (2.4, 1.8) | 76 | (2.4, 2.2) | 79 | (2.4, 3.4) | 81 | (3.2, 0.2) |
| 82 | (3.2, 0.6) | 85 | (3.2, 1.8) | 86 | (3.2, 2.2) | 89 | (3.2, 3.4) |
| 93 | (3.4, 0.8) | 94 | (3.4, 1.6) | 97 | (3.4, 2.4) | 98 | (3.4, 3.2) |
| 103 | (3.8, 0.8) | 104 | (3.8, 1.6) | 107 | (3.8, 2.4) | 108 | (3.8, 3.2) |
| 310 | (0.8, 3.8) | 410 | (1.6, 3.8) | 710 | (2.4, 3.8) | 810 | (3.2, 3.8) |

---

## Other Launch Files

### `frob_bringup` — `bringup.launch.py`
No arguments. Starts: arduino_bridge, sllidar, lidar_filter, mpu6050 (IMU), robot_state_publisher, odometry (encoder + EKF).

### `frob_navigation` — `navigation.launch.py`
No arguments. Starts Nav2 with `nav2_params.yaml` + static map.

### `frob_navigation` — `slam.launch.py`
| Argument | Default | Description |
|----------|---------|-------------|
| `slam_params_file` | `slam_toolbox_params.yaml` | SLAM config |

### `frob_odometry` — `odometry.launch.py`
No arguments. Starts `wheel_odometry` + `ekf_filter_node`.

### `frob_description` — `description.launch.py`
No arguments. Starts `robot_state_publisher` + `joint_state_publisher` for URDF display.

### `frob_control` — `joy_control.launch.py`
No arguments. Joystick teleop.

---

## Robot Specs

- **Base**: 21×21 cm, differential drive
- **Wheels**: radius 0.0344 m, separation 0.152 m (URDF), 0.18 m (odometry config)
- **Encoder**: 0.00057 m/tick
- **Max linear speed**: 0.486 m/s
- **Max angular speed**: 5.4 rad/s
- **LiDAR**: YDLIDAR X4, `/dev/ttyUSB0`, 460800 baud, frame `laser`
- **IMU**: MPU6050, I2C, frame `base_footprint`
- **Camera**: USB, `/dev/video0`, 640×480 @ ~25 FPS actual
- **Motors**: Arduino Mega via USB serial (`/dev/ttyACM*`)

---

## Known Issues & Limitations

1. **Gazebo IMU sensor not publishing** — TB4 URDF→SDF conversion produces `gz_frame_id` warnings. `/imu` topic empty in simulation. Workaround: `motion_executor` uses odometry orientation for yaw.
2. **No dynamic re-planning** — `graph_navigator` computes path once. No sign/obstacle detection integration yet. `blocked_edges` parameter exists in Dijkstra but always empty.
3. **No sign detection** — YOLO model not yet trained. `SignDetection` message defined but no publisher.
4. **No bus stop / parking logic** — 2-second stop at pickup zones not implemented.
5. **NVIDIA EGL warnings at Gazebo startup** — needs env vars (see simulation launch section). Cosmetic, doesn't affect functionality.
6. **Robot pose hardcoded in SDF** — `city_polygon_tb4.sdf` has fixed spawn pose. Dynamic spawn by `start_node` not yet implemented.

---

## Build & Run

```bash
# Build (PC, skip I2C):
cd ~/ros2_ws
colcon build --packages-skip ros2_mpu6050 --symlink-install
source install/setup.zsh

# Real robot bringup:
ros2 launch frob_bringup bringup.launch.py

# Real robot mission:
ros2 launch frob_mission mission.launch.py start_node:=13 target_node:=108

# Simulation — just the city:
ros2 launch frob_mission simulation.launch.py mode:=city

# Simulation — city + robot (no mission):
ros2 launch frob_mission simulation.launch.py mode:=tb4

# Simulation — full mission run:
ros2 launch frob_mission simulation.launch.py mode:=mission

# Camera:
ros2 run frob_perception camera_node
# Remote view (compressed, stable framerate):
ros2 topic hz /camera/image_raw/compressed

# Build specific packages only:
colcon build --packages-select frob_mission frob_perception --symlink-install
```

---

## Git

`.gitignore` excludes `build/`, `install/`, `log/`.
