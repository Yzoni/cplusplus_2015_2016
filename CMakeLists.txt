cmake_minimum_required(VERSION 3.3)
project(cmethoden)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES assignment2/main.cpp)

add_executable(cmethoden ${SOURCE_FILES})