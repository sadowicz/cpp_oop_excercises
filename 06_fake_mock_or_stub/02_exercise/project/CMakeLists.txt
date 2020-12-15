cmake_minimum_required(VERSION 3.16)

project(project)

add_library(utils
        include/Point.h
        include/SpaceImpl.h
        include/Time.h
        include/Universe.h
        include/ObserverImpl.h
        src/SpaceImpl.cpp
        src/Time.cpp
        src/ObserverImpl.cpp
        src/Universe.cpp)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp include/Space.h include/Observer.h)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)
