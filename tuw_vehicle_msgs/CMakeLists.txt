cmake_minimum_required(VERSION 3.5)
project(tuw_vehicle_msgs)

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
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

rosidl_generate_interfaces(tuw_vehicle_msgs
   "msg/Wheelspeeds.msg"
   "msg/AutonomousState.msg"
   "msg/RWDControl.msg"
   "msg/ChassisState.msg"
   "msg/BatteryState.msg"
   "msg/RWDMotion.msg"
   "msg/RWDKinCmd.msg"
   "msg/Track.msg"
   "msg/TrackMarking.msg"
   "msg/CmdMpcVecVphi.msg"
   DEPENDENCIES std_msgs geometry_msgs
)

include_directories(
  include
  ${std_msgs_INCLUDE_DIRS}
  ${geometry_msgs_INCLUDE_DIRS}
)


add_library(tuw_vehicle_msgs_lib
   src/battery_state.cpp
)

rosidl_target_interfaces(tuw_vehicle_msgs_lib
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

target_link_libraries(tuw_vehicle_msgs_lib)

ament_export_include_directories(include)
ament_export_libraries(tuw_vehicle_msgs_lib)

ament_package()

# install artifacts
#install(
#  DIRECTORY cmake
#  DESTINATION share/${PROJECT_NAME}
#)
install(
  DIRECTORY include/
  DESTINATION include
)
install(
  TARGETS tuw_vehicle_msgs_lib
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

