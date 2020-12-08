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
        src/observer/Displacement.cpp
        include/observer/Speed.h
        src/observer/Speed.cpp

        include/factory/gui/Widget.h
        include/factory/gui/CheckBoxKdeWidget.h
        src/factory/gui/CheckBoxKdeWidget.cpp
        include/factory/gui/ListKdeWidget.h
        src/factory/gui/ListKdeWidget.cpp
        include/factory/gui/ButtonKdeWidget.h
        src/factory/gui/ButtonKdeWidget.cpp
        include/factory/gui/CheckBoxGnomeWidget.h
        src/factory/gui/CheckBoxGnomeWidget.cpp
        include/factory/gui/ListGnomeWidget.h
        src/factory/gui/ListGnomeWidget.cpp
        include/factory/gui/ButtonGnomeWidget.h
        src/factory/gui/ButtonGnomeWidget.cpp
        include/factory/gui/WidgetFactory.h
        include/factory/gui/KdeWidgetFactory.h
        src/factory/gui/KdeWidgetFactory.cpp
        include/factory/gui/GnomeWidgetFactory.h
        src/factory/gui/GnomeWidgetFactory.cpp
        include/factory/gui/Demo.h
        src/factory/gui/Demo.cpp)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)
