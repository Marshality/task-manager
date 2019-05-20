cmake_minimum_required(VERSION 3.13)
project(Boost)

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT /usr/local/Cellar/boost/1.68.0_1)

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
find_package(Boost 1.68.0 COMPONENTS filesystem system REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(server server.cpp asyncserver.cpp getter.cpp getter.h)
    target_link_libraries(server ${Boost_LIBRARIES})
endif()