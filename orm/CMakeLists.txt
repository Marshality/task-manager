cmake_minimum_required(VERSION 3.12)
project(orm)

set(CMAKE_CXX_STANDARD 17)

add_executable(orm main.cpp fields/template/CharField.h fields/template/TextField.h fields/template/validators/BaseValidator.h fields/template/validators/IntegerValidator.h fields/template/validators/CharValidator.h fields/template/validators/TextValidator.h fields/template/DateField.h fields/template/validators/DateValidator.h fields/template/DateTimeField.h fields/template/TimeField.h)

#add_subdirectory(connection)
#target_link_libraries(orm wrapperlib)
#target_include_directories(orm PRIVATE ./connection)

target_include_directories(orm PRIVATE .)
target_include_directories(orm PRIVATE models)
target_include_directories(orm PRIVATE models/managers)
target_include_directories(orm PRIVATE models/managers/meta)
#target_include_directories(orm PRIVATE fields)
#target_include_directories(orm PRIVATE fields/validators)
target_include_directories(orm PRIVATE fields/template)
target_include_directories(orm PRIVATE fields/template/validators)
