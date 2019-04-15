cmake_minimum_required(VERSION 3.12)
project(database_test)

set(CMAKE_CXX_STANDARD 14)

find_package(PostgreSQL REQUIRED)

link_libraries(${PostgreSQL_LIBRARIES})

add_executable(database_test
        main.cpp
        Connection.cpp
        Manager.cpp
        Manager.h
        ResultSet.cpp
        ResultSet.h
        )