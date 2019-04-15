cmake_minimum_required(VERSION 3.12)
project(PostgreSQL_ORM)

set(CMAKE_CXX_STANDARD 14)

add_executable(PostgreSQL_ORM main.cpp Object.h Object.cpp User.cpp User.h Manager.cpp Manager.h Fields.h Creator.cpp Creator.h)