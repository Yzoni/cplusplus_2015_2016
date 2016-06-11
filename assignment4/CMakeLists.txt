cmake_minimum_required(VERSION 3.3)
project(Assignment4)

add_definitions(-std=c++98)

set(SOURCE_FILES main.cpp)
add_executable(assignment_run ${SOURCE_FILES})

include_directories(assignment)

add_subdirectory(assignment)
add_subdirectory(test)
target_link_libraries(assignment_run assignment)