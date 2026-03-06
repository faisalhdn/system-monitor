cmake_minimum_required(VERSION 3.16)

project(system_monitor VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(system_monitor
    #mainwindow.ui
    #mainwindow.cpp
    src/main.cpp
)

target_link_libraries(system_monitor PRIVATE Qt6::Widgets)