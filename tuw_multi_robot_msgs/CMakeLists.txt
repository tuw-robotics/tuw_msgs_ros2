cmake_minimum_required(VERSION 3.5)
project(tuw_multi_robot_msgs)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # we dont use add_compile_options with pedantic in message packages
  # because the Python C extensions dont comply with it
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
endif()

find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)

rosidl_generate_interfaces(tuw_multi_robot_msgs
  "msg/PoseId.msg"
  "msg/PoseIdArray.msg"
  "msg/RoutePrecondition.msg"
  "msg/RouteSegment.msg"
  "msg/Route.msg"
  "msg/PlannerStatus.msg"
  "msg/Vertex.msg"
  "msg/Graph.msg"
  DEPENDENCIES builtin_interfaces geometry_msgs nav_msgs
)

ament_package()
