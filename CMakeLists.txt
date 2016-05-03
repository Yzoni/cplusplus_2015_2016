cmake_minimum_required(VERSION 3.3)
project(cmethoden)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES assignment4/SmallNumber.cpp assignment4/LargeNumber.cpp assignment4/LargeNumber.h assignment4/Number.cpp assignment4/Number.h assignment4/Math.cpp assignment4/Math.h assignment4/SmallNumber.h assignment4/main.cpp)

add_executable(cmethoden ${SOURCE_FILES})