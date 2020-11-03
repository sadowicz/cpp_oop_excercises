cmake_minimum_required(VERSION 3.16)

project(runner)

add_executable(runner src/main.cpp)
target_include_directories(runner PRIVATE ./include/)

add_library(calculator STATIC src/Calculator.cpp)
target_include_directories(calculator PRIVATE ./include/)
target_link_libraries(runner PRIVATE calculator)

add_subdirectory(./tests)