cmake_minimum_required(VERSION 3.12)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp Controller.cpp models/TaskManager.cpp)

target_include_directories(main PRIVATE .)
target_include_directories(main PRIVATE models)
target_include_directories(main PRIVATE commands)

target_include_directories(main PRIVATE orm/.)
target_include_directories(main PRIVATE orm/models)
target_include_directories(main PRIVATE orm/models/managers)
target_include_directories(main PRIVATE orm/models/managers/meta)
target_include_directories(main PRIVATE orm/fields)
target_include_directories(main PRIVATE orm/fields/validators)

