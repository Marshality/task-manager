cmake_minimum_required(VERSION 3.12)
project(orm)

set(CMAKE_CXX_STANDARD 14)

add_executable(orm
        main.cpp
        fields/IntegerField.h
        fields/validators/BaseValidator.h
        fields/validators/IntegerValidator.h
        fields/CharField.h
        fields/validators/IntegerValidator.cpp
        fields/IntegerField.cpp
        fields/CharField.cpp
        objects/managers/meta/Meta.h
        objects/Project.h objects/Project.cpp objects/managers/ProjectManager.cpp objects/managers/ProjectManager.h)

#add_subdirectory(connection)
#target_link_libraries(orm wrapperlib)
#target_include_directories(orm PRIVATE ./connection)

target_include_directories(orm PRIVATE ./objects)
target_include_directories(orm PRIVATE ./objects/managers)
target_include_directories(orm PRIVATE ./objects/managers/meta)
target_include_directories(orm PRIVATE ./fields)
target_include_directories(orm PRIVATE ./fields/validators)
