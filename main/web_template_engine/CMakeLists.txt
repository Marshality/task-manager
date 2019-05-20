cmake_minimum_required(VERSION 3.13)
project(my_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(my_project main.cpp)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(my_project ${Boost_LIBRARIES})

add_subdirectory(mstch-master)
include_directories(${mstch_INCLUDE_DIR})
target_link_libraries(my_project mstch)