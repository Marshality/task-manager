cmake_minimum_required(VERSION 3.12)
project(connection)

set(CMAKE_CXX_STANDARD 14)

find_package(PostgreSQL REQUIRED)
link_libraries(${PostgreSQL_LIBRARIES})

add_executable(connection
        main.cpp
        BaseSet.h)



#target_include_directories(connection PRIVATE ./exceptions)

#include(exceptions/CMakeLists.txt)
#
#set(CONNECTION_HEADERS
#        Connection.h
#        Cursor.h
#        ${CONNECTION_EXCEPTIONS_HEADERS})