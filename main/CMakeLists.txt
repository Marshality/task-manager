cmake_minimum_required(VERSION 3.12)
project(main)

set(CMAKE_CXX_STANDARD 14)

find_package(PostgreSQL REQUIRED)
link_libraries(${PostgreSQL_LIBRARIES})

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
link_libraries(${Boost_LIBRARIES})

add_subdirectory(web_template_engine/mstch-master)
include_directories(${mstch_INCLUDE_DIR})
link_libraries(mstch)

add_executable(main
        main.cpp
        Controller.cpp
        Storage.cpp
        objects/task/Task.cpp
        objects/project/Project.cpp
        objects/user/User.cpp
        objects/project/ProjectMeta.cpp
        objects/task/TaskMeta.cpp
        objects/user/UserMeta.cpp
        connection/Connection.cpp
        connection/ResultSet.cpp web_template_engine/Renderer.cpp web_template_engine/exceptions/FileNotOpenException.h)

target_include_directories(main PRIVATE .)
target_include_directories(main PRIVATE objects)
target_include_directories(main PRIVATE objects/base)
target_include_directories(main PRIVATE commands)
target_include_directories(main PRIVATE connection)
target_include_directories(main PRIVATE connection/exceptions)


