cmake_minimum_required(VERSION 3.16)

project(tests)

add_executable(tests src/CalculatorTest.cpp)

target_include_directories(tests PRIVATE ../../googletest/googletest/include/ PRIVATE ../include/)
target_link_directories(tests PRIVATE ../../googletest/build/lib/)
target_link_libraries(tests PRIVATE gtest gtest_main pthread)