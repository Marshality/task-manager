cmake_minimum_required(VERSION 3.12)
project(connection)

set(CMAKE_CXX_STANDARD 14)

find_package(PostgreSQL REQUIRED)
link_libraries(${PostgreSQL_LIBRARIES})

add_executable(connection
        main.cpp
        Connection.cpp
        Cursor.cpp
 )

target_include_directories(connection PRIVATE ./exceptions)