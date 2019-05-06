cmake_minimum_required(VERSION 3.12)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp Controller.cpp models/TaskManager.cpp model/Types.h)

target_include_directories(main PRIVATE .)
target_include_directories(main PRIVATE model)
target_include_directories(main PRIVATE models)
target_include_directories(main PRIVATE commands)
