cmake_minimum_required(VERSION 3.5)
project(tuw_nav_msgs)
SET(GCC_COVERAGE_COMPILE_FLAGS "-fdump-ada-spec")

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
find_package(rclcpp REQUIRED)
find_package(rmw_implementation REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tuw_geometry_msgs REQUIRED)

rosidl_generate_interfaces(tuw_nav_msgs
  "msg/RouteSegment.msg"
  "msg/RouteSegments.msg"
  "msg/Float64Array.msg"
  "msg/Spline.msg"
  "msg/JointsIWS.msg"
  "msg/IwsCmdVRAT.msg"
  "msg/IwsCmdVRATVec.msg"
  "msg/IwsCmdVWWTVec.msg"
  "msg/DiffDriveCmdVWVec.msg"
  "msg/PathVec.msg"
  DEPENDENCIES std_msgs tuw_geometry_msgs nav_msgs
)

#include_directories(
#  include
#  ${rclcpp_INCLUDE_DIRS}
#  ${rmw_connext_cpp_INCLUDE_DIRS}
#  ${std_msgs_INCLUDE_DIRS}
#  ${nav_msgs_INCLUDE_DIRS}
#  ${geometry_msgs_INCLUDE_DIRS}
#  ${tuw_geometry_msgs_INCLUDE_DIRS}
#)

#add_library(tuw_nav_msgs_lib
#   src/route_segment.cpp
#   src/route_segments.cpp
#   src/path.cpp
#)

#target_link_libraries(tuw_nav_msgs_lib ${rclcpp_LIBRARIES} ${rmw_connext_cpp_LIBRARIES} ${std_msgs} ${nav_msgs} ${geometry_msgs} ${tuw_geometry_msgs})


ament_package()

