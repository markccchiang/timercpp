cmake_minimum_required(VERSION 3.5)

project(timer_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Threads REQUIRED)

add_executable(sample sample.cpp)
target_link_libraries(sample ${CMAKE_THREAD_LIBS_INIT})
