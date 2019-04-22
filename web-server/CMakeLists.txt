cmake_minimum_required(VERSION 3.13)
project(Boost)

set(CMAKE_CXX_STANDARD 11)

set(BOOST_ROOT "/usr/local/Cellar/boost/1.69.0")

find_package(Boost 1.69.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(server server.cpp)

if(Boost_FOUND)
    target_link_libraries(server ${Boost_LIBRARIES})
endif()