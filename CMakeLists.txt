cmake_minimum_required(VERSION 3.20)
project(Calc_machime)

set(CMAKE_CXX_STANDARD 23)

add_executable(Calc_machine main.cpp calculator.cpp calculator.h)

add_library(TESTS tests.cpp)

add_subdirectory(logger)
add_subdirectory(longInteger)
add_subdirectory(stack)

target_link_libraries(Calc_machine mainlogger BigInt)

add_subdirectory(tests/googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(Calc_machine gtest gtest_main TESTS)