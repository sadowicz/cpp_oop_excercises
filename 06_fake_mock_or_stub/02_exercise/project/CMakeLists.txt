cmake_minimum_required(VERSION 3.16)

project(project)

add_library(utils
        include/Point.h
        include/Space.h
        include/Time.h
        include/Universe.h
        include/Observer.h
        src/Space.cpp
        src/Time.cpp
        src/Observer.cpp
        src/Universe.cpp)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)
