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

| Package | Type | Role | Status |
|---------|------|------|--------|
| `frob_interfaces` | CMake | Custom `.msg`, `.srv`, `.action` | Active |
| `frob_mission` | Python | **Graph planning, motion execution, visualization, simulation** | **Active** |
| `frob_bringup` | Python | Master launch for all hardware drivers | Inactive (real robot only) |
| `frob_control` | Python | Joystick teleop | Inactive |
| `frob_description` | Python | URDF, TF tree, RViz configs | Inactive |
| `frob_navigation` | Python | Nav2 / SLAM launch + configs | Inactive |
| `frob_odometry` | Python | Wheel encoder odometry + EKF | Inactive (real robot only) |
| `frob_perception` | Python | USB camera driver (V4L2 + compressed) | Inactive |
| `keyboard_vel_control` | Python | Keyboard teleop (alternative) | Inactive |
| `lidar_filter` | Python | Filters LiDAR points near robot body | Inactive |
| `rf2o_laser_odometry` | CMake | Laser-based odometry (optional) | Inactive |
| `ros2_arduino_bridge` | Python | Serial bridge to Arduino (motors/encoders) | Inactive (real robot only) |
| `ros2_mpu6050` | CMake | MPU6050 IMU driver (I2C, Pi only) | Inactive (real robot only) |
| `sllidar_ros2` | CMake | YDLIDAR X4 driver | Inactive (real robot only) |

**Active packages for current development**: `frob_mission` (all logic), `frob_interfaces` (types).
All other packages are hardware drivers or future features — not needed for path planning + simulation.

### External Dependencies (apt-installed)

| Package | Role |
|---------|------|
| `ros-jazzy-turtlebot4-simulator` | TB4 Gazebo model, bridges, launch |
| `ros-jazzy-ros-gz-sim` | ROS ↔ Gazebo integration |
| `ros-jazzy-turtlebot4-description` | TB4 URDF (transitive dep) |
| `ros-jazzy-irobot-create-gz-plugins` | Diff-drive, sensor plugins (transitive dep) |
| `visualization_msgs` | Marker/MarkerArray for RViz graph display |
| `std_msgs` | Int32MultiArray for `/path` topic, ColorRGBA for markers |

---

## Architecture Overview

```
┌──────────────────┐     /path (Int32MultiArray)     ┌───────────────────┐
│  graph_navigator │ ──────────────────────────────▶ │  graph_visualizer │
│                  │                                  │  (RViz markers)   │
│  Dijkstra path   │                                  └───────────────────┘
│  Command planner │
│  (timer-based)   │     ExecuteMotion action goal     ┌───────────────────┐
│                  │ ──────────────────────────────▶ │  motion_executor  │
└──────────────────┘                                  │                   │
                                                     │  Action server    │
                                                     │  /cmd_vel (Twist) │
                                                     └───────────────────┘
```

Three nodes in `frob_mission`:
1. **`graph_navigator`** — plans the route and feeds commands to the motion executor
2. **`motion_executor`** — ActionServer, executes movement commands via closed-loop control
3. **`graph_visualizer`** — displays the graph + planned path in RViz via MarkerArray

Communication: `graph_navigator` → `/path` topic → `graph_visualizer` (path display).  
Commands: `graph_navigator` → `/execute_motion` action → `motion_executor`.

---

## 1. `graph_navigator` (`frob_mission/graph_navigator.py`)

Dijkstra-based path planner + timer-based command dispatcher.

### Architecture — Timer-based action client

Sends all commands as a **single action goal** (list) to avoid rclpy ActionClient bugs
with sequential goals (internal UUID tracking caused "Ignoring unexpected goal/response"
warnings and premature result delivery on 2nd+ goal).

- **Main thread** (`rclpy.spin(node)`): processes all ROS callbacks
- **One-shot timer** (`_mission_timer`): waits for action server, sends the entire
  command list as one goal, then cancels itself

Logic:
1. `__init__` plans path/commands and creates a 1-second `_mission_timer`
2. Timer callback checks `_action_client.wait_for_server()`; once connected, sends
   one goal with `commands[]` and `values[]`
3. `_on_goal_response` callback receives goal acceptance
4. `_on_mission_result` callback receives final result (success/failure)
5. No sequential goals, no threading, no separate executor — eliminates the rclpy bug

### Command Model — Arc-based Turns

The robot moves along arcs (not rotate-in-place). Each edge in the graph is classified
relative to the robot's current heading `h`:

| Command | Condition (rel = h − edge_angle) | Value field | Effect |
|---------|------|-------------|--------|
| `forward` | rel ∈ [−30°, 30°] | distance (m) | Drive straight |
| `right_turn` | rel ∈ [30°, 150°] | arc radius R (m) | CW quarter-circle arc of radius R. Displaces robot (R forward, R right), heading −90° |
| `left_turn` | rel ∈ [−150°, −30°] | arc radius R (m) | CCW quarter-circle arc of radius R. Displaces robot (R forward, R left), heading +90° |
| `u_turn` | rel ∈ [−105°, −75°] AND dy_local ≈ 0 | arc radius R (m) | CCW half-circle arc. Displaces (0, 2R left), heading +180° |

Local frame components for R computation:
```
dx_local = dx * sin(h) - dy * cos(h)    # lateral (right positive)
dy_local = dx * cos(h) + dy * sin(h)    # forward
R = abs(dx_local)
```

**Heading tracking** in `_plan_motion`:
- `forward` → heading unchanged
- `right_turn` → heading −= π/2
- `left_turn` → heading += π/2
- `u_turn` → heading += π

`initial_heading` is auto-computed from the first edge of the Dijkstra path
(`atan2(dy, dx)` from `start_node` to the second node). The robot is expected to be
placed facing the first edge direction at the start node.

### Parameters

| Parameter | YAML Default | CLI Override | Description |
|-----------|-------------|-------------|-------------|
| `graph_file` | `''` (auto) | — | Path to `graph.yaml` (auto from package share) |
| `start_node` | `13` | `start_node:=` | Start graph node ID (23 in simulation — TB4 spawn) |
| `target_node` | `108` | `target_node:=` | Destination graph node ID |
| `initial_heading` | `0.0` | `initial_heading:=` | Override auto-computed heading (rad) |
| `turn_threshold` | `0.08` | — | Min angle diff for turn detection (rad, ≈4.6°) |
| `execute` | `True` | `execute:=False` | If False, publish path only (planning mode) |

### Topics

| Direction | Topic | Type | Purpose |
|-----------|-------|------|---------|
| Publish | `/path` | `Int32MultiArray` | List of graph node IDs forming the planned path |
| Action client | `/execute_motion` | `ExecuteMotion` | Sends entire command list as one goal |

Publishes `/path` once after planning, then republishes every 2 seconds (timer) so
late-connecting subscribers (`graph_visualizer`) can catch it.

### Algorithm

1. Loads graph from `config/graph.yaml` (48 nodes, 92 directed edges)
2. Runs Dijkstra with Euclidean edge weights
3. Publishes planned node IDs to `/path`
4. Plans motion commands using the arc-based turn model (see above)
5. If `execute=True`: waits for action server, sends all commands as a single action goal
6. Logs "MISSION COMPLETE" on success, aborts on any failure

---

## 2. `motion_executor` (`frob_mission/motion_executor.py`)

Closed-loop motion controller — ActionServer for `execute_motion`.

### Parameters

| Parameter | YAML Default | Code Default | Description |
|-----------|-------------|-------------|-------------|
| `forward_speed` | `0.12` | `0.15` | Linear speed (m/s) |
| `rotate_speed` | `1.2` | `1.0` | Max angular speed (rad/s, unused for arcs) |
| `forward_tolerance` | `0.02` | `0.02` | Distance tolerance (m) |
| `rotate_tolerance` | `0.05` | `0.05` | Angle tolerance (rad) |
| `kp_angular` | `2.5` | `2.0` | P-gain (unused for arcs) |

### Command Execution

**`forward(distance)`** (50 Hz loop):
- Records start position from `/odometry/filtered`
- Computes `traveled = sqrt(dx²+dy²)`, stops within `forward_tolerance` of target
- Slowdown ramp when `remaining < 0.1m`
- Publishes `Twist.linear.x` to `/cmd_vel`
- Timeout: 10 seconds waiting for initial odometry

**`right_turn(R)` / `left_turn(R)` / `u_turn(R)`** (arc execution, 50 Hz):
- Computes angular velocity: `ω = forward_speed / R` (signed by direction)
- Publishes constant `Twist(linear.x=forward_speed, angular.z=ω)` to `/cmd_vel`
- Stops when yaw reaches `target_yaw = start_yaw + angle` within `rotate_tolerance`
- Angle: `right_turn` = −π/2, `left_turn` = +π/2, `u_turn` = +π

**Yaw source** (`_ensure_yaw`):
- Priority: `/imu/mpu6050` (if available) → `/odometry/filtered` orientation
- In simulation, IMU topic is empty — falls back to odometry yaw
- Computes yaw from quaternion: `atan2(2(qw·qz + qx·qy), 1 − 2(qy² + qz²))`
- Timeout: 10 seconds

### Topics

| Direction | Topic | Type | Purpose |
|-----------|-------|------|---------|
| Subscribe | `/odometry/filtered` | `Odometry` | Robot position + yaw fallback |
| Subscribe | `/imu/mpu6050` | `Imu` | Primary yaw source |
| Publish | `/cmd_vel` | `Twist` | Velocity commands to robot/Gazebo |
| Action server | `/execute_motion` | `ExecuteMotion` | Receives movement commands |

### Executor

Uses `MultiThreadedExecutor` — the action server callback is in a
`MutuallyExclusiveCallbackGroup` to prevent concurrent command execution.

---

## 3. `graph_visualizer` (`frob_mission/graph_visualizer.py`)

Publishes `visualization_msgs/MarkerArray` to `/graph_markers` for RViz.

### Parameters

| Parameter | Default | Description |
|-----------|---------|-------------|
| `graph_file` | `''` (auto) | Path to `graph.yaml` |
| `publish_rate` | `1.0` | Marker publish rate (Hz) |
| `frame_id` | `odom` | TF frame for markers |

### Topics

| Direction | Topic | Type | Purpose |
|-----------|-------|------|---------|
| Subscribe | `/path` | `Int32MultiArray` | Receives planned path from `graph_navigator` |
| Subscribe | `/sign_detected` | `SignDetection` | Future: sign-based graph rebuilding |
| Subscribe | `/odometry/filtered` | `Odometry` | Robot position marker |
| Publish | `/graph_markers` | `MarkerArray` | Graph + path visualization for RViz |

### Display

| Element | Color | Marker type |
|---------|-------|-------------|
| Nodes (regular) | Green (α=0.4) | SPHERE radius 0.03m |
| Start node | Blue (α=1.0) | SPHERE |
| Target node | Red (α=1.0) | SPHERE |
| Path nodes | Yellow/orange (α=0.9) | SPHERE |
| Node labels (ID) | White (α=0.5) / colored | TEXT_VIEW_FACING |
| Edges (regular) | Gray (α=0.3) | ARROW |
| Path edges | Yellow/orange (α=0.9) | ARROW |
| Blocked edges | Red (α=0.7) | ARROW |
| Robot position | Magenta (α=0.8) | SPHERE radius 0.04m |

Path received log is printed once when path changes (not on every republish).

---

## 4. `topic_relay` (`frob_mission/topic_relay.py`)

Generic topic relay — forwards messages from one topic to another (same type).

```
Usage: topic_relay <from_topic> <to_topic> <msg_type>
Example: topic_relay /odom /odometry/filtered nav_msgs.msg.Odometry
```

Used in simulation launch to map TB4 topics → frob_robot expected names:
- `/odom` → `/odometry/filtered`
- `/imu` → `/imu/mpu6050` (⚠️ IMU not publishing in Gazebo — yaw falls back to odometry)

---

## frob_mission Package — Launch Files

### `planning.launch.py` — Path Display Only (no robot)

| Argument | Default | Description |
|----------|---------|-------------|
| `start_node` | `13` | Start graph node ID |
| `target_node` | `108` | Target graph node ID |

Starts: `graph_navigator` (execute=False) + `graph_visualizer`.
No Gazebo, no robot, no motion execution.

```bash
ros2 launch frob_mission planning.launch.py start_node:=23 target_node:=108
# In another terminal: rviz2 → Add /graph_markers MarkerArray → Fixed Frame = odom
```

### `mission.launch.py` — Real Robot Mission

| Argument | Default | Description |
|----------|---------|-------------|
| `start_node` | `13` | Start graph node ID |
| `target_node` | `108` | Target graph node ID |
| `initial_heading` | `0.0` | Initial robot heading (rad, overrides auto-computed) |

Starts: `motion_executor` + `graph_navigator` (execute=True) + `graph_visualizer`.

```bash
ros2 launch frob_mission mission.launch.py start_node:=23 target_node:=108
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

| `mode` | SDF used | Gazebo | Bridges | Relays | Mission nodes |
|--------|----------|--------|---------|--------|---------------|
| `city` | `city_polygon.sdf` | World only | clock | — | — |
| `tb4` | `city_polygon_tb4.sdf` | World + TB4 | clock + tb4_bridge | odom, imu | — |
| `mission` | `city_polygon_tb4.sdf` | World + TB4 | clock + tb4_bridge | odom, imu | motion_executor + graph_navigator + graph_visualizer |

**Topic mapping in simulation:**
- `/odom` → `/odometry/filtered` (relay)
- `/imu` → `/imu/mpu6050` (relay, ⚠️ IMU not publishing in Gazebo)
- `/cmd_vel` (direct, same name)
- `/scan` (direct, same name)

**NVIDIA GPU workaround:**
```bash
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia \
__EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/10_nvidia.json \
ros2 launch frob_mission simulation.launch.py mode:=mission
```

---

## Custom Interfaces (`frob_interfaces`)

### Action: `ExecuteMotion` (`frob_interfaces/action/ExecuteMotion.action`)

```
# Goal - list of commands to execute sequentially
string[] commands    # "forward" | "right_turn" | "left_turn" | "u_turn"
float32[] values     # distance (m) for forward, arc radius (m) for turns
---
# Result
bool success
string message       # Error description if failed
int32 completed_steps # Number of completed steps (0-based, = total on success)
---
# Feedback
float32 progress     # 0.0..1.0 progress of current command
int32 current_step   # Current step index (0-based)
string current_command
```

### Messages (4) — defined but not yet integrated

| Message | Fields | Status |
|---------|--------|--------|
| `SignDetection` | `sign_type` (UNKNOWN=0…DANGER=8), `detected`, `distance`, `confidence`, `bbox_*` | No publisher yet |
| `LineDetection` | `detected`, `lateral_error`, `angle_error`, `confidence`, `line_center_x/y` | No publisher |
| `IntersectionDetection` | `junction_type`, `distance`, `detected` | No publisher |
| `ObstacleDetection` | `blocked`, `distance`, `zone_width` | No publisher |

### Services (2) — defined but unused

- `Turn.srv`: `int32 angle, int32 speed → bool success`
- `Forward.srv`: `int32 dist, int32 speed → bool success`

---

## Simulation Worlds

### `city_polygon.sdf` (`worlds/city_polygon.sdf`)
Pure city polygon without robot. Contains:
- Ground plane (centered at 2,2)
- 4 external walls (4×0.1×0.6 m each)
- 5×5 grid lines (12 lines, 0.8m spacing)
- 4 buildings (0.5×0.5×0.6 m) at cells (2,2), (2,4), (4,2), (4,4)
- 48 node markers (green cylinders at graph.yaml coordinates)

### `city_polygon_tb4.sdf` (`worlds/city_polygon_tb4.sdf`)
Same as `city_polygon.sdf` + embedded TurtleBot 4 robot model:
- `<scale>0.68 0.68 0.68</scale>` — scales TB4 from 31cm → ~21cm width
- `<pose>0.6 0.8 0.01 0 0 1.5708</pose>` — spawn at node 23 (0.6, 0.8), facing north
- Full SDF generated from `nav2_minimal_tb4_description` URDF via `gz sdf -p`

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

## Robot Specs (real robot)

- **Base**: 21×21 cm, differential drive
- **Wheels**: radius 0.0344 m, separation 0.152 m (URDF), 0.18 m (odometry config)
- **Encoder**: 0.00057 m/tick
- **Max linear speed**: 0.486 m/s, max angular speed: 5.4 rad/s
- **LiDAR**: YDLIDAR X4, `/dev/ttyUSB0`, 460800 baud, frame `laser`
- **IMU**: MPU6050, I2C, frame `base_footprint`
- **Camera**: USB, `/dev/video0`, 640×480 @ ~25 FPS
- **Motors**: Arduino Mega via USB serial (`/dev/ttyACM*`)

---

## Known Issues & Limitations

1. **rclpy ActionClient bug (worked around)** — rclpy's internal goal UUID tracking gets
   confused when sending sequential action goals, producing "Ignoring unexpected
   goal/response" warnings and premature result delivery on 2nd+ goal. **Workaround**:
   send entire mission as a single action goal with `commands[]` and `values[]` lists,
   eliminating sequential goals entirely (`graph_navigator.py`).
2. **Gazebo IMU sensor not publishing** — TB4 URDF→SDF conversion produces
   `gz_frame_id` warnings. `/imu` topic empty in simulation. **Workaround**:
   `motion_executor` uses odometry orientation for yaw.
3. **No sign detection** — YOLO model not yet trained. `SignDetection` message
   defined, `graph_visualizer` subscribes to `/sign_detected` (skeleton ready).
4. **No dynamic re-planning** — Path computed once. No sign/obstacle integration.
   `blocked_edges` exists in Dijkstra but always `set()`.
5. **No bus stop / parking logic** — Pause at pickup zones not implemented.
6. **Robot pose hardcoded in SDF** — `city_polygon_tb4.sdf` has fixed spawn at
   node 23. Dynamic spawn by `start_node` not yet implemented.
7. **NVIDIA EGL warnings at Gazebo startup** — needs env vars (see simulation
   section). Cosmetic, doesn't affect functionality.

---

## Build & Run

```bash
# Build (PC, skip I2C):
cd ~/ros2_ws
colcon build --packages-skip ros2_mpu6050 --symlink-install
source install/setup.zsh

# Show planned path in RViz (no robot):
ros2 launch frob_mission planning.launch.py start_node:=23 target_node:=108

# Simulation — just the city polygon:
ros2 launch frob_mission simulation.launch.py mode:=city

# Simulation — city + TB4 robot (no mission):
ros2 launch frob_mission simulation.launch.py mode:=tb4

# Simulation — full mission:
ros2 launch frob_mission simulation.launch.py mode:=mission start_node:=23 target_node:=108

# Build only frob_mission:
colcon build --packages-select frob_mission --symlink-install
```

---

## Git

`.gitignore` excludes `build/`, `install/`, `log/`.
