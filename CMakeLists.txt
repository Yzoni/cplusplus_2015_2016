cmake_minimum_required(VERSION 3.3)
project(cmethoden)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES assignment3/World.cpp assignment3/Menu.cpp assignment3/Menu.h assignment3/World.cpp assignment3/World.h assignment3/main.cpp assignment3/BasicLCG.cpp assignment3/BasicLCG.h)

add_executable(cmethoden ${SOURCE_FILES})