cmake_minimum_required(VERSION 3.12)
project(main)

set(CMAKE_CXX_STANDARD 14)

find_package(PostgreSQL REQUIRED)
link_libraries(${PostgreSQL_LIBRARIES})

add_executable(main
        main.cpp
        Controller.cpp
        Storage.cpp
        objects/task/Task.cpp
        objects/project/Project.cpp
        objects/user/User.cpp)

target_include_directories(main PRIVATE .)
target_include_directories(main PRIVATE objects)
target_include_directories(main PRIVATE commands)
target_include_directories(main PRIVATE connection)
target_include_directories(main PRIVATE connection/exceptions)


