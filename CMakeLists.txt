cmake_minimum_required(VERSION 2.8.4)
project(cppcon-room-assignment)

find_package(CURL REQUIRED)
set(CURL_LIBRARY "-lcurl")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -pedantic")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cppcon-room-assignment
    main.cpp
    http_get.h
    http_get.cpp
    http_init.h
    http_init.cpp
    sched_event.h
    sched_event.cpp
    utils.h
    utils.cpp
    flags.hpp)

include_directories(${CURL_INCLUDE_DIR})

target_link_libraries(cppcon-room-assignment ${CURL_LIBRARIES} pthread)
