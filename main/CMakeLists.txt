cmake_minimum_required(VERSION 3.12)
project(main)

set(CMAKE_CXX_STANDARD 14)

set(BOOST_ROOT /usr/local/Cellar/boost/1.68.0_1)

find_package(PostgreSQL REQUIRED)
link_libraries(${PostgreSQL_LIBRARIES})

find_package(Boost 1.68.0 COMPONENTS filesystem system REQUIRED)
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
#        web-server/beastserver/server.cpp
#        web-server/beastserver/HttpServer.cpp
#        web-server/beastserver/Session.cpp
#        web-server/beastserver/Listener.cpp
        controller/commands/BaseCommand.cpp
        )

target_include_directories(main PRIVATE .)
target_include_directories(main PRIVATE objects)
target_include_directories(main PRIVATE objects/base)
target_include_directories(main PRIVATE web-server)
target_include_directories(main PRIVATE database)
target_include_directories(main PRIVATE database/connection)
target_include_directories(main PRIVATE database/connection/exceptions)
target_include_directories(main PRIVATE controller)


