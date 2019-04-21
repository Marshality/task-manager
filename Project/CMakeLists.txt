cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD 11)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

add_executable(Project main.cpp Receiver.cpp Receiver.h commands/BaseCommand.h commands/ConcreteCommand.h Invoker.h User.h Task.h Project.h DatabaseManager.h HttpServer.h commands/CreateTaskCommand.h commands/CreateProjectCommand.h commands/DeleteTaskCommand.h commands/DeleteProjectCommand.h commands/EditProjectCommand.h commands/EditTaskCommand.h commands/exceptions/FieldIsMissedException.h)

target_link_libraries(Project ${PYTHON_LIBRARIES})
