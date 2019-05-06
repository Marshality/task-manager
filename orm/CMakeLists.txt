cmake_minimum_required(VERSION 3.12)
project(orm)

set(CMAKE_CXX_STANDARD 17)

<<<<<<< HEAD
add_executable(orm main.cpp)
=======
add_executable(orm main.cpp models/Model.h models/managers/Manager-Impl.cpp fields/validators/CharValidator.h fields/DateTimeField.h fields/DateField.h fields/validators/DateValidator.h fields/Field.h fields/validators/Validator.h)

#add_subdirectory(connection)
#target_link_libraries(orm wrapperlib)
#target_include_directories(orm PRIVATE ./connection)
>>>>>>> main_logic

target_include_directories(orm PRIVATE .)
target_include_directories(orm PRIVATE models)
target_include_directories(orm PRIVATE models/managers)
target_include_directories(orm PRIVATE models/managers/meta)
target_include_directories(orm PRIVATE fields)
target_include_directories(orm PRIVATE fields/validators)
