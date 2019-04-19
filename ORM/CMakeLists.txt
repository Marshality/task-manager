cmake_minimum_required(VERSION 3.12)
project(ORM)

set(CMAKE_CXX_STANDARD 14)

add_executable(ORM
        main.cpp
        )

add_subdirectory(Wrapper)
target_link_libraries(ORM wrapperlib)