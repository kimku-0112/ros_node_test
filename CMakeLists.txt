cmake_minimum_required(VERSION 3.0.2)
project(test)

set (CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES test
  CATKIN_DEPENDS roscpp rospy
  DEPENDS system_lib
)

set(TEST_SRC
  src/test.cpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}  
)

add_executable(test_node ${TEST_SRC})
target_link_libraries(test_node  ${catkin_LIBRARIES})
add_dependencies(test_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
