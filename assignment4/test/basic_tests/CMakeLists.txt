include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runAssignment4Tests
        large_number_check.cpp small_number_check.cpp math_check.cpp)

target_link_libraries(runAssignment4Tests gtest gtest_main)
target_link_libraries(runAssignment4Tests assignment)
