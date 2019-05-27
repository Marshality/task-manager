cmake_minimum_required(VERSION 3.12)
project(orm)

set(CMAKE_CXX_STANDARD 17)

add_executable(orm main.cpp)

target_include_directories(orm PRIVATE .)
target_include_directories(orm PRIVATE models)
target_include_directories(orm PRIVATE models/managers)
target_include_directories(orm PRIVATE models/managers/meta)
target_include_directories(orm PRIVATE fields)
target_include_directories(orm PRIVATE fields/validators)
