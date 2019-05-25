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
        controller/Controller.cpp
        database/Storage.cpp
        objects/task/Task.cpp
        objects/project/Project.cpp
        objects/user/User.cpp
        objects/project/ProjectMeta.cpp
        objects/task/TaskMeta.cpp
        objects/user/UserMeta.cpp
        database/connection/Connection.cpp
        database/connection/ResultSet.cpp
        web_template_engine/Renderer.cpp
        )

target_include_directories(main PRIVATE .)
target_include_directories(main PRIVATE objects)
target_include_directories(main PRIVATE objects/base)
target_include_directories(main PRIVATE database)
target_include_directories(main PRIVATE database/connection)
target_include_directories(main PRIVATE database/connection/exceptions)
target_include_directories(main PRIVATE controller)


