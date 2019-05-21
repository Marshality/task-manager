cmake_minimum_required(VERSION 3.13)
project(web_template_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(web_template_engine)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(web_template_engine ${Boost_LIBRARIES})

add_subdirectory(mstch-master)
include_directories(${mstch_INCLUDE_DIR})
target_link_libraries(web_template_engine mstch)