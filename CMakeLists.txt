project(system_watch)

cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=native -O3 -pthread")

set(SRC_LISTS src/main.cpp)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC_LISTS})
target_link_libraries(${PROJECT_NAME} wdt_dio pthread)
