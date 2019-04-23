cmake_minimum_required(VERSION 3.12)
project(orm)

set(CMAKE_CXX_STANDARD 14)

add_executable(orm
        main.cpp
        "TemplateManager.h")

#add_subdirectory(connection)
#target_link_libraries(orm wrapperlib)
#target_include_directories(orm PRIVATE ./connection)

target_include_directories(orm PRIVATE ./objects)
target_include_directories(orm PRIVATE ./objects/managers)
target_include_directories(orm PRIVATE ./objects/managers/meta)
target_include_directories(orm PRIVATE ./fields)
target_include_directories(orm PRIVATE ./fields/validators)
