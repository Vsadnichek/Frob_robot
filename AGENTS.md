# AGENTS.md — frob_robot

## Project Overview

**Autonomous city navigation robot** for the «Кубок РТК Высшая лига» hackathon (coursework).
The robot drives on a 4×4m polygon (5×5 grid of 800mm cells), follows road signs,
stops at pickup zones, and finishes at the drop-off zone.

- **Workspace**: `~/ros2_ws/frob_robot`
- **ROS2 distro**: Jazzy
- **Robot**: Differential drive (21×21 cm base, 2 wheels + 2 casters), Arduino Mega, YDLIDAR X4, MPU6050 IMU, USB camera
- **PC build**: `colcon build --symlink-install`
- **Simulation**: Gazebo Harmonic (`gz-sim8`) via `ros_gz_sim`, TurtleBot 4 model (geometry scaled ×0.453 in SDF), custom city polygon world

---

## Package Map (3 packages in `src/`)

| Package | Type | Role | Status |
|---------|------|------|--------|
| `frob_interfaces` | CMake | Custom `.action` for motion commands | Active |
| `frob_mission` | Python | **Graph planning, motion execution, visualization, simulation** | **Active** |
| `frob_perception` | Python | USB camera driver (V4L2 + compressed) | Inactive |

**Active packages for current development**: `frob_mission` (all logic), `frob_interfaces` (types).

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
┌──────────────────┐                                  │  /cmd_vel (Twist) │
│ set_initial_pose │  set_pose service (Gazebo)       └───────────────────┘
│ teleports robot  │ ──────────▶ [turtlebot4 model]
│ to start_node    │
└──────────────────┘
```

Four nodes in `frob_mission`:
1. **`graph_navigator`** — plans the route and feeds commands to the motion executor
2. **`motion_executor`** — ActionServer, executes movement commands via closed-loop control
3. **`graph_visualizer`** — displays the graph + planned path in RViz via MarkerArray
4. **`set_initial_pose`** — teleports robot from spawn position to `start_node` via Gazebo service

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

The robot moves along arcs (not rotate-in-place). Commands are **pre-annotated**
in the graph — `graph_navigator` reads the command type directly from the node's
`forward`/`right_turn`/`left_turn`/`u_turn` lists without heading-based classification.

| Command | Value (hardcoded) | Effect |
|---------|-------------------|--------|
| `forward` | 0.8 m | Drive straight one cell |
| `right_turn` | 0.2 m radius | CW quarter-circle arc. Displaces robot (R forward, R right), heading −90° |
| `left_turn` | 0.6 m radius | CCW quarter-circle arc. Displaces robot (R forward, R left), heading +90° |
| `u_turn` | 0.2 m radius | CCW half-circle arc. Displaces (0, 2R left), heading +180° |

Values are defined in `FIXED_VALUES` dict in `graph_navigator.py` — not stored in `graph.yaml`.  
Heading tracking in `_plan_motion` is used for fallback computation only.

### Parameters

| Parameter | YAML Default | CLI Override | Description |
|-----------|-------------|-------------|-------------|
| `graph_file` | `''` (auto) | — | Path to `graph.yaml` (auto from package share) |
| `start_node` | `13` | `start_node:=` | Start graph node ID (23 in simulation — TB4 spawn) |
| `target_node` | `108` | `target_node:=` | Destination graph node ID |
| `initial_heading` | `0.0` | `initial_heading:=` | Override auto-computed heading (rad). 0 = use `suggested_heading` from graph |
| `execute` | `True` | `execute:=False` | If False, publish path only (planning mode) |

### Heading Convention

Heading values use the convention **0 = north, π/2 = east** (standard compass convention).
All `suggested_heading` values in `graph.yaml` use this convention. Internally,
`graph_navigator` converts to standard math (0 = east) via `HEADING_OFFSET = π/2`
before tracking heading through the command sequence. The `initial_heading` CLI
parameter also uses the compass convention (0 = north).

`set_initial_pose` adds `π/2` when reading `suggested_heading` to convert back
to standard math for the Gazebo `set_pose` service (which uses 0 = east).

### Initial Heading Resolution

When `initial_heading` is 0.0 (default), the node reads `suggested_heading` from the
start node's entry in `graph.yaml` (in compass convention, 0 = north). The value
is converted to standard math via `HEADING_OFFSET` for internal use.

If the node has no `suggested_heading`, falls back to computing `atan2(dy, dx)` from
the first edge of the planned path (legacy behavior).

### Topics

| Direction | Topic | Type | Purpose |
|-----------|-------|------|---------|
| Publish | `/path` | `Int32MultiArray` | List of graph node IDs forming the planned path |
| Action client | `/execute_motion` | `ExecuteMotion` | Sends entire command list as one goal |

Publishes `/path` once after planning, then republishes every 2 seconds (timer) so
late-connecting subscribers (`graph_visualizer`) can catch it.

### Algorithm

1. Loads graph from `config/graph.yaml` (48 nodes, 92 directed edges).
   Each node has `forward`, `right_turn`, `left_turn`, `u_turn` lists of target nodes
   with pre-computed command values.
2. Runs Dijkstra on the combined adjacency (union of all four command fields)
3. Publishes planned node IDs to `/path`
4. Plans motion commands by looking up each edge in the node's command annotations
   (reads `forward`/`right_turn`/etc. directly — no heading-based computation needed)
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
| `kp_angular` | `2.5` | `2.0` | P-gain for heading correction during forward |
| `kp_cross_track` | `1.0` | `1.0` | P-gain for cross-track error correction |
| `settle_time` | `0.3` | `0.3` | Pause between commands (s), 0 to disable |

### Command Execution

**`forward(distance)`** (50 Hz loop):
- Records start position and heading from `/odometry/filtered`
- Tracks `_target_heading` — the IDEAL heading the robot should maintain
- Applies dual correction: `angular.z = kp_angular * yaw_error - kp_cross_track * cross_track`
- `yaw_error` = difference between ideal heading and actual yaw
- `cross_track` = perpendicular distance from intended straight line
- Slowdown ramp when `remaining < 0.1m`
- Publishes `Twist.linear.x` and `Twist.angular.z` to `/cmd_vel`
- Timeout: 10 seconds waiting for initial odometry

**`right_turn(R)` / `left_turn(R)` / `u_turn(R)`** (arc execution, 50 Hz):
- Computes angular velocity: `ω = forward_speed / R` (signed by direction)
- Publishes constant `Twist(linear.x=forward_speed, angular.z=ω)` to `/cmd_vel`
- Stops when yaw reaches `target_yaw = start_yaw + angle` within `rotate_tolerance`
- Angle: `right_turn` = −π/2, `left_turn` = +π/2, `u_turn` = +π
- After completion, updates `_target_heading` to the IDEAL post-turn value
  (`_target_heading += angle`), NOT the actual yaw — this chains ideal headings
  through the sequence, preventing error accumulation

**`_settle()`** — called after each command:
- Sends zero Twist, waits `settle_time` seconds
- Prevents residual motion from affecting the next command

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

### Coordinate Transform (world → odom)

The graph stores node coordinates in **world frame** (matching the SDF polygon), but
the DiffDrive plugin publishes odometry in the **odom frame** (robot starts at 0,0).
The visualizer transforms all graph coordinates from world to odom using the robot's
spawn position and heading (`start_node`'s coordinates and `suggested_heading + π/2`):

```
odom_point = R(−heading) * (world_point − origin)
```

This keeps markers and the robot dot perfectly aligned in RViz without needing TF.

### Parameters

| Parameter | Default | Description |
|-----------|---------|-------------|
| `graph_file` | `''` (auto) | Path to `graph.yaml` |
| `publish_rate` | `1.0` | Marker publish rate (Hz) |
| `frame_id` | `odom` | TF frame for markers |
| `start_node` | `-1` (auto from graph) | Robot spawn node (defines world→odom origin) |

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

## 4. `set_initial_pose` (`frob_mission/set_initial_pose.py`)

Teleports robot from hardcoded SDF spawn position (node 23) to the desired `start_node`.

- Reads `graph.yaml` to get coordinates and `suggested_heading` for `start_node`
- Calls Gazebo service `/world/city_polygon/set_pose` via `gz service` CLI
- Retries up to 30 times with 2s interval (Gazebo may not be ready immediately)
- Used in simulation with modes `tb4` and `mission`

**Parameters:**

| Parameter | Default | Description |
|-----------|---------|-------------|
| `start_node` | `23` | Target graph node ID for teleport |

---

## frob_mission Package — Launch Files

### `planning.launch.py` — Path Display Only (no robot)

| Argument | Default | Description |
|----------|---------|-------------|
| `start_node` | `13` | Start graph node ID |
| `target_node` | `108` | Target graph node ID |

Starts: `graph_navigator` (execute=False) + `graph_visualizer` + `rviz2`.
No Gazebo, no robot, no motion execution.

```bash
ros2 launch frob_mission planning.launch.py start_node:=23 target_node:=108
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
| `start_node` | `23` | Start graph node ID (mission mode only, also sets robot spawn) |
| `target_node` | `108` | Target graph node ID (mission mode only) |
| `initial_heading` | `0.0` | Initial robot heading (mission mode only) |

**Mode behavior:**

| `mode` | SDF used | Gazebo | Bridges | Relays | Mission nodes | RViz2 |
|--------|----------|--------|---------|--------|---------------|-------|
| `city` | `city_polygon.sdf` | World only | clock | — | — | — |
| `tb4` | `city_polygon_tb4.sdf` | World + TB4 | clock + tb4_bridge | odom, imu | set_initial_pose | — |
| `mission` | `city_polygon_tb4.sdf` | World + TB4 | clock + tb4_bridge | odom, imu | set_initial_pose + motion_executor + graph_navigator + graph_visualizer | Yes |

**Gazebo camera**: auto-positioned via `--gui-config` loading `config/gazebo_camera.config`
with camera pose `(2, 2, 3) pitch=π/2 yaw=π/2` — top-down view centered on polygon.

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
- All geometry (meshes, primitives, poses, masses, inertias) directly scaled by factor 0.453
- `<pose>0.6 0.8 0.01 0 0 1.5708</pose>` — spawn at node 23 (0.6, 0.8), facing world +Y (north, standard math yaw = π/2)
- **Note**: `<scale>` at model level is invalid in SDF 1.7 and silently ignored by Gazebo;
  scaling is applied directly to all geometry values
- Full SDF generated from `nav2_minimal_tb4_description` URDF via `gz sdf -p`, then
  post-processed to apply the 0.453 geometry scale

---

## Navigation Graph

File: `src/frob_mission/config/graph.yaml`. **48 nodes, 92 directed edges**.

Each node stores its coordinates and four command-annotated adjacency lists:

```yaml
nodes:
  23:
    x: 0.6
    y: 0.8
    forward: [24]
    right_turn: []
    left_turn: [13]
    u_turn: []
    suggested_heading: 0.0
```

- `forward` — straight-line movement
- `right_turn` — CW quarter-circle arc
- `left_turn` — CCW quarter-circle arc
- `u_turn` — CCW half-circle arc
- `suggested_heading` — recommended initial heading in radians (**0 = north, π/2 = east**).
  Computed from the first outgoing edge (priority: forward > right_turn > left_turn > u_turn).
  Used by `graph_navigator` for auto‑initialization and by `set_initial_pose` for spawn orientation.
  Converted to/from standard math (0 = east) at the boundary by adding/subtracting π/2.

Edges are pre-annotated with command types. The motion planner reads the command
directly from the graph without heading-based classification. Values are defined
in `FIXED_VALUES` dict in `graph_navigator.py` — not stored in `graph.yaml`.

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
6. **NVIDIA EGL warnings at Gazebo startup** — needs env vars (see simulation
   section). Cosmetic, doesn't affect functionality.

---

## Build & Run

```bash
# Build (PC):
cd ~/ros2_ws
colcon build --symlink-install
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
