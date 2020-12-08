cmake_minimum_required(VERSION 3.16)

project(project)

add_library(utils
        include/Calculator.h
        src/Calculator.cpp
        include/observer/Observer.h
        include/observer/Observable.h
        src/observer/Observable.cpp
        include/observer/Acceleration.h
        src/observer/Acceleration.cpp
        include/observer/Displacement.h
        include/observer/Speed.h
        src/observer/Speed.cpp)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)
