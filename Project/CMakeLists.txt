cmake_minimum_required(VERSION 3.12)
project(Project)

set(CMAKE_CXX_STANDARD 11)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(Project main.cpp Receiver.cpp)

target_link_libraries(Project ${PYTHON_LIBRARIES})
