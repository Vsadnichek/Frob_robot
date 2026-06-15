# frob_robot

Робот для автономной навигации по городу в рамках хакатона «Кубок РТК Высшая лига»
(курсовая работа). Робот движется по полигону 4×4 м (сетка 5×5 ячеек 800×800 мм),
следует дорожным знакам, останавливается в зонах посадки и финиширует в зоне высадки.

- **ROS2**: Jazzy
- **Робот**: дифференциальный привод (база 21×21 см), Arduino Mega, YDLIDAR X4, MPU6050 IMU, USB-камера
- **Симуляция**: Gazebo Harmonic (`gz-sim8`), модель TurtleBot 4 (уменьшена в 0.453×), собственный мир с городским полигоном

---

## Пакеты

| Пакет | Язык | Назначение |
|-------|------|------------|
| `frob_interfaces` | CMake | Пользовательский `.action` для команд движения |
| `frob_mission` | Python | Планирование маршрута, управление движением, визуализация, запуск симуляции |
| `frob_perception` | Python | Драйвер USB-камеры (V4L2) для реального робота |

---

## Ноды

### `graph_navigator` — Планировщик маршрута и диспетчер команд

Загружает граф навигации, выполняет алгоритм Дейкстры для поиска кратчайшего пути
от `start_node` до `target_node`, планирует команды движения по аннотациям рёбер
графа и отправляет весь список команд одним action goal в `motion_executor`.

**Параметры:**

| Параметр | По умолч. | CLI | Описание |
|----------|-----------|-----|----------|
| `graph_file` | `''` (авто) | — | Путь к `graph.yaml` |
| `start_node` | `13` | `start_node:=` | ID стартового узла |
| `target_node` | `108` | `target_node:=` | ID целевого узла |
| `initial_heading` | `0.0` | `initial_heading:=` | Переопределение курса (рад), 0 = автовычисление |
| `execute` | `True` | `execute:=False` | `False` — только публикация пути (режим планирования) |

**Топики:**

| Направление | Топик | Тип | Назначение |
|-------------|-------|-----|------------|
| Публикация | `/path` | `Int32MultiArray` | Список ID узлов планируемого пути |

**Экшены:**

| Направление | Экшен | Тип | Назначение |
|-------------|-------|-----|------------|
| Клиент | `/execute_motion` | `ExecuteMotion` | Отправляет весь список команд одной целью |

---

### `motion_executor` — Контроллер движения

Сервер экшенов, принимающий список команд движения и выполняющий их последовательно
с замкнутым контуром управления по данным одометрии.

**Параметры:**

| Параметр | По умолч. | Описание |
|----------|-----------|----------|
| `forward_speed` | `0.12` | Линейная скорость (м/с) |
| `forward_tolerance` | `0.02` | Допуск по расстоянию для forward (м) |
| `rotate_tolerance` | `0.05` | Допуск по углу для поворотов (рад) |

**Топики:**

| Направление | Топик | Тип | Назначение |
|-------------|-------|-----|------------|
| Подписка | `/odometry/filtered` | `Odometry` | Позиция робота + yaw |
| Подписка | `/imu/mpu6050` | `Imu` | Источник yaw (недоступен в симуляции) |
| Публикация | `/cmd_vel` | `Twist` | Команды скорости роботу / Gazebo |

**Экшены:**

| Направление | Экшен | Тип | Назначение |
|-------------|-------|-----|------------|
| Сервер | `/execute_motion` | `ExecuteMotion` | Принимает список команд и выполняет последовательно |

---

### `graph_visualizer` — Визуализация для RViz

Публикует `MarkerArray` в `/graph_markers`: узлы графа, рёбра, планируемый путь,
позиция робота.

**Параметры:**

| Параметр | По умолч. | Описание |
|----------|-----------|----------|
| `graph_file` | `''` (авто) | Путь к `graph.yaml` |
| `publish_rate` | `1.0` | Частота публикации маркеров (Гц) |
| `frame_id` | `odom` | TF-фрейм для маркеров |

**Топики:**

| Направление | Топик | Тип | Назначение |
|-------------|-------|-----|------------|
| Подписка | `/path` | `Int32MultiArray` | Планируемый путь от `graph_navigator` |
| Подписка | `/odometry/filtered` | `Odometry` | Позиция робота |
| Публикация | `/graph_markers` | `MarkerArray` | Граф + путь + робот |

---

### `topic_relay` — Ретранслятор топиков

Пересылает сообщения из одного топика в другой (тот же тип). Используется в симуляции
для сопоставления топиков TB4 → frob_robot (`/odom` → `/odometry/filtered`, `/imu` → `/imu/mpu6050`).

```
topic_relay <из_топика> <в_топик> <тип_сообщения>
```

---

## Экшен: `ExecuteMotion`

```
# Goal
string[] commands    # "forward" | "right_turn" | "left_turn" | "u_turn"
float32[] values     # Значения команд (задаются жёстко в graph_navigator)
---
# Result
bool success
string message
int32 completed_steps
---
# Feedback
float32 progress     # Прогресс текущей команды (0.0..1.0)
int32 current_step   # Индекс текущего шага (0-based)
string current_command
```

### Жёстко заданные значения команд

Значения не хранятся в `graph.yaml` — они определены в `graph_navigator.py`:

| Команда | Значение | Смысл |
|---------|----------|-------|
| `forward` | 0.8 м | Проезд прямо на одну ячейку |
| `right_turn` | 0.2 м | Радиус дуги CW (четверть окружности) |
| `left_turn` | 0.6 м | Радиус дуги CCW (четверть окружности) |
| `u_turn` | 0.2 м | Радиус дуги CCW (полуокружность) |

---

## Граф навигации

Файл: `src/frob_mission/config/graph.yaml`. **48 узлов, 92 направленных ребра**.

Каждая нода хранит координаты и четыре списка достижимых узлов с типом команды:

```yaml
nodes:
  23:
    x: 0.6
    y: 0.8
    forward: [24]
    right_turn: []
    left_turn: [13]
    u_turn: []
```

- `forward` — движение прямо
- `right_turn` — поворот направо (дуга CW)
- `left_turn` — поворот налево (дуга CCW)
- `u_turn` — разворот (полуокружность CCW)

Планировщик читает тип команды напрямую из аннотаций графа, без вычисления по курсу.

**Кодировка ID узлов**: `"XY"` где X и Y — индексы сетки (1–10):

| Индекс | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|-----------|---|---|---|---|---|---|---|---|---|----|
| Метры  | 0.2 | 0.6 | 0.8 | 1.6 | 1.8 | 2.2 | 2.4 | 3.2 | 3.4 | 3.8 |

---

## Сборка и запуск

```bash
# Сборка:
cd ~/ros2_ws
colcon build --symlink-install
source install/setup.zsh

# Планирование — путь в RViz (без робота):
ros2 launch frob_mission planning.launch.py start_node:=23 target_node:=108

# Миссия на реальном роботе:
ros2 launch frob_mission mission.launch.py start_node:=23 target_node:=108

# Симуляция — только полигон:
ros2 launch frob_mission simulation.launch.py mode:=city

# Симуляция — полигон + робот (без миссии):
ros2 launch frob_mission simulation.launch.py mode:=tb4

# Симуляция — полная миссия:
ros2 launch frob_mission simulation.launch.py mode:=mission start_node:=23 target_node:=108
```

### Аргументы симуляции

| Аргумент | По умолч. | Описание |
|----------|-----------|----------|
| `mode` | `mission` | `city` / `tb4` / `mission` |
| `world` | `''` (авто) | Путь к SDF-миру |
| `headless` | `false` | Gazebo без GUI |
| `start_node` | `23` | Стартовый узел (mission) |
| `target_node` | `108` | Целевой узел (mission) |
| `initial_heading` | `0.0` | Начальный курс, рад (mission) |

### RViz

`planning.launch.py` автоматически запускает RViz с `Fixed Frame = odom` и подпиской
на `/graph_markers`. Конфиг: `src/frob_mission/config/planning.rviz`.

### NVIDIA GPU

```bash
__NV_PRIME_RENDER_OFFLOAD=1 __GLX_VENDOR_LIBRARY_NAME=nvidia \
__EGL_VENDOR_LIBRARY_FILENAMES=/usr/share/glvnd/egl_vendor.d/10_nvidia.json \
ros2 launch frob_mission simulation.launch.py mode:=mission
```

---

## Внешние зависимости

```bash
sudo apt install ros-jazzy-turtlebot4-simulator ros-jazzy-ros-gz-sim \
  ros-jazzy-turtlebot4-description ros-jazzy-irobot-create-gz-plugins
```
