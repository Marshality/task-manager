cmake_minimum_required(VERSION 3.12)
project(Wrapper)

set(CMAKE_CXX_STANDARD 14)

find_package(PostgreSQL REQUIRED)
link_libraries(${PostgreSQL_LIBRARIES})

add_executable(Wrapper
        main.cpp
        Manager.cpp
        Manager.h
        Cursor.cpp
        Cursor.h
        )

add_library(wrapperlib
        Manager.cpp
        Manager.h
        Cursor.cpp
        Cursor.h
        )