cmake_minimum_required(VERSION 3.12)
project(main_logic)

set(CMAKE_CXX_STANDARD 14)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(main_logic main.cpp Receiver.cpp)

target_link_libraries(main_logic ${PYTHON_LIBRARIES})

target_include_directories(main_logic PRIVATE connection)