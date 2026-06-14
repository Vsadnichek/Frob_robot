# AGENTS.md — frob_robot

## Project Overview

**Autonomous city navigation robot** for the «Кубок РТК Высшая лига» hackathon.
The robot must drive on a 4×4m polygon (5×5 grid of 800mm cells) following road signs,
stopping at pickup zones («Остановка») for 2 seconds, and finishing at the drop-off zone («Парковка»).

- **Workspace**: `~/ros2_ws/frob_robot`
- **ROS2 distro**: Jazzy
- **Robot**: Differential drive (21×21 cm base, 2 wheels + 2 casters), Arduino Mega motor controller, YDLIDAR X4, MPU6050 IMU, USB camera
- **PC build**: requires `colcon build --packages-skip ros2_mpu6050` (no I2C)

---

## Package Map (14 packages in `src/`)

| Package | Type | Role |
|---------|------|------|
| `frob_interfaces` | CMake | Custom `.msg`, `.srv`, `.action` |
| `frob_bringup` | Python | Master launch for all hardware |
| `frob_control` | Python | Joystick teleop |
| `frob_description` | Python | URDF, TF tree, RViz configs |
| `frob_mission` | Python | **Graph-based path planning + motion execution** |
| `frob_navigation` | Python | Nav2 / SLAM launch + configs |
| `frob_odometry` | Python | Wheel encoder odometry + EKF |
| `frob_perception` | Python | **USB camera driver only** (sign detection via YOLO planned separately) |
| `keyboard_vel_control` | Python | Keyboard teleop (alternative) |
| `lidar_filter` | Python | Filters LiDAR points near robot body |
| `rf2o_laser_odometry` | CMake | Laser-based odometry (optional) |
| `ros2_arduino_bridge` | Python | Serial bridge to Arduino (motors/encoders) |
| `ros2_mpu6050` | CMake | MPU6050 IMU driver (I2C, Pi only) |
| `sllidar_ros2` | CMake | YDLIDAR X4 driver |

---

## Custom Interfaces (`frob_interfaces`)

### Messages (4)
- **`LineDetection`** — `detected`, `lateral_error`, `angle_error`, `confidence`, `line_center_x/y`
- **`SignDetection`** — `sign_type` (UNKNOWN=0, GO_STRAIGHT=1, GO_LEFT=2, GO_RIGHT=3, NO_LEFT_TURN=4, NO_RIGHT_TURN=5, BUS_STOP=6, PARKING=7, DANGER=8), `distance`, `confidence`, `bbox_*`
- **`IntersectionDetection`** — `junction_type` (NONE=0, T_LEFT=1, T_RIGHT=2, T_FORWARD=3, CORNER_LEFT=4, CORNER_RIGHT=5, CROSSROAD=6)
- **`ObstacleDetection`** — `blocked`, `distance`, `zone_width`

### Services (2)
- **`Turn`** — `int32 angle, int32 speed → bool success`
- **`Forward`** — `int32 dist, int32 speed → bool success`

### Actions (1)
- **`ExecuteMotion`** — `string command ("forward"|"rotate"), float32 value (m|rad) → bool success`

---

## All Topics

| Topic | Type | Publisher |
|-------|------|-----------|
| `/scan` | LaserScan | `sllidar_node` |
| `/scan/filtered` | LaserScan | `lidar_filter` |
| `/odom` | Odometry | `wheel_odometry` |
| `/odometry/filtered` | Odometry | `ekf_filter_node` |
| `/imu/mpu6050` | Imu | `mpu6050_sensor` |
| `/cmd_vel` | Twist | teleop nodes, `motion_executor`, `collision_monitor` |
| `/camera/image_raw` | Image | `camera_node` |
| `left_motor/encoder/delta` | Int32 | `arduino_bridge` |
| `right_motor/encoder/delta` | Int32 | `arduino_bridge` |
| `left_motor/speed` | Float32 | `arduino_bridge` |
| `right_motor/speed` | Float32 | `arduino_bridge` |
| `rotate_robot` | Turn.srv | `arduino_bridge` |
| `forward_robot` | Forward.srv | `arduino_bridge` |
| `execute_motion` | ExecuteMotion.action | `motion_executor` (server) |

---

## Launch Files and Arguments

### `frob_bringup` — `bringup.launch.py`
No arguments. Starts: arduino_bridge, sllidar (lidar), lidar_filter, mpu6050 (IMU), robot_state_publisher, odometry (encoder + EKF).

### `frob_mission` — `mission.launch.py`
| Argument | Default | Description |
|----------|---------|-------------|
| `start_node` | `13` | Start graph node ID |
| `target_node` | `108` | Target graph node ID |
| `initial_heading` | `0.0` | Initial robot heading in radians (0=east/+X, pi/2=north/+Y) |

### `frob_perception` — `perception.launch.py`
| Argument | Default | Description |
|----------|---------|-------------|
| `camera_device` | `0` | Camera device index (0=/dev/video0) |

### `frob_navigation` — `navigation.launch.py`
No arguments. Starts Nav2 with `nav2_params.yaml` + `map.yaml`/`map.pgm`.

### `frob_navigation` — `slam.launch.py`
| Argument | Default | Description |
|----------|---------|-------------|
| `slam_params_file` | `slam_toolbox_params.yaml` | SLAM config file |

### `frob_odometry` — `odometry.launch.py`
No arguments. Starts `wheel_odometry` + `ekf_filter_node`.

### `frob_description` — `description.launch.py`
No arguments. Starts `robot_state_publisher` + `joint_state_publisher`.

### `frob_control` — `joy_control.launch.py`
No arguments. Starts `joy_node` + `joystick_control_node`.

---

## Key Parameters

### `motion_executor` (frob_mission)
| Parameter | Default | Description |
|-----------|---------|-------------|
| `forward_speed` | 0.12 | Linear speed for forward motion (m/s) |
| `rotate_speed` | 1.2 | Max angular speed for rotation (rad/s) |
| `forward_tolerance` | 0.02 | Distance tolerance (m) |
| `rotate_tolerance` | 0.05 | Angle tolerance (rad) |
| `kp_angular` | 2.5 | P-gain for rotation controller |

### `graph_navigator` (frob_mission)
| Parameter | Default | Description |
|-----------|---------|-------------|
| `start_node` | 13 | Start node ID |
| `target_node` | 108 | Target node ID |
| `initial_heading` | 0.0 | Initial heading (rad) |
| `turn_threshold` | 0.08 | Min angle difference to trigger rotation (rad) |

### `camera_node` (frob_perception)
| Parameter | Default | Description |
|-----------|---------|-------------|
| `device` | 0 | Camera device index |
| `width` | 640 | Frame width |
| `height` | 480 | Frame height |
| `fps` | 30.0 | Target FPS |

### Odometry (`odometry_params.yaml`)
- `meters_per_tick: 0.00057` — encoder resolution
- `wheel_base: 0.18` — wheel separation in meters

### EKF (`ekf.yaml`)
- `frequency: 45.0` Hz
- Fuses `/odom` + `/imu/mpu6050` → `/odometry/filtered`
- `two_d_mode: true`

---

## Navigation Graph

Defined in `src/frob_mission/config/graph.yaml`. **48 nodes, 92 directed edges** representing the city road network.

Coordinate system: meters from left-bottom corner (0,0) of 4×4m polygon. Node naming: `"XY"` where X and Y are grid indices (1-10), mapped to coordinates via table:

| Index | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|-------|---|---|---|---|---|---|---|---|---|----|
| Meter | 0.2 | 0.6 | 0.8 | 1.6 | 1.8 | 2.2 | 2.4 | 3.2 | 3.4 | 3.8 |

Parsing logic: if node string ends with `"10"` → Y=10; otherwise last char = Y.

---

## Algorithm (current state)

1. Robot placed at start corner → operator provides `start_node`, `target_node`, `initial_heading`
2. `graph_navigator` loads graph, runs **Dijkstra** → path: [n1, n2, n3, ...]
3. For each edge (current → next):
   - Compute `atan2(dy, dx)` → desired heading
   - If |desired − current| > 0.08 rad → send `rotate(Δθ)` to `motion_executor`
   - Compute Euclidean distance → send `forward(distance)`
4. `motion_executor` executes:
   - **Forward**: closed-loop on `/odometry/filtered` (stops within 2 cm)
   - **Rotate**: closed-loop on `/imu/mpu6050` (P-controller, stops within 0.05 rad)
5. Repeat until `target_node` reached

Sign handling (YOLO, planned) will remove edges from graph and replan.

---

## Build Commands

```bash
# On Raspberry Pi (full hardware):
cd ~/ros2_ws
colcon build
source install/setup.bash

# On PC (no I2C):
cd ~/ros2_ws
colcon build --packages-skip ros2_mpu6050
source install/setup.bash

# Build specific packages:
colcon build --packages-select frob_mission frob_perception --symlink-install
```

---

## Run Commands

```bash
# Full bringup (hardware):
ros2 launch frob_bringup bringup.launch.py

# Mission (after bringup):
ros2 launch frob_mission mission.launch.py
ros2 launch frob_mission mission.launch.py start_node:=13 target_node:=108 initial_heading:=0.0

# Camera only:
ros2 run frob_perception camera_node
ros2 launch frob_perception perception.launch.py

# Keyboard teleop:
ros2 run frob_bringup keyboard_teleop
```

---

## Robot Specs

- **Base**: 21×21 cm, differential drive
- **Wheels**: radius 0.0344 m, separation 0.152 m (URDF), 0.18 m (odometry config)
- **Encoder**: 0.00057 m/tick
- **Max linear speed**: 0.486 m/s
- **Max angular speed**: 5.4 rad/s
- **LiDAR**: YDLIDAR X4, `/dev/ttyUSB0`, 460800 baud, frame `laser`
- **IMU**: MPU6050, I2C, frame `base_footprint`
- **Camera**: USB, `/dev/video0`, 640×480 @ 25 FPS actual (30 nominal)
- **Motors**: Arduino Mega via USB serial (`/dev/ttyACM*`), custom binary protocol

## Git

`.gitignore` excludes `build/`, `install/`, `log/`. These were removed from tracking via `git rm --cached`.
