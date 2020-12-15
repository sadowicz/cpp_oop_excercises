cmake_minimum_required(VERSION 3.16)

add_executable(tests
        src/UniverseTest.cpp)

target_link_libraries(tests PRIVATE utils)
target_include_directories(tests PRIVATE include)


set(GTEST ../../googletest)

target_include_directories(tests PRIVATE ${GTEST}/googletest/include)
target_include_directories(tests PRIVATE ${GTEST}/googlemock/include)

target_link_directories(tests PRIVATE ${GTEST}/build/lib)

target_link_libraries(tests PRIVATE gtest gmock gtest_main pthread)
