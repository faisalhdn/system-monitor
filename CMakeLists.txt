cmake_minimum_required(VERSION 3.16)

project(system_monitor VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

set(SYSTEM_MONITOR_SOURCES
    src/main.cpp
    src/core/CpuMonitorService.cpp
)

if(WIN32)
    list(APPEND SYSTEM_MONITOR_SOURCES
        src/platform/windows/WindowsCpuReader.cpp
    )
elseif(UNIX AND NOT APPLE)
    list(APPEND SYSTEM_MONITOR_SOURCES
        src/platform/linux/LinuxCpuReader.cpp
    )
endif()

qt_add_executable(system_monitor
    ${SYSTEM_MONITOR_SOURCES}
)

target_include_directories(system_monitor PRIVATE src)

if(MSVC)
    target_compile_options(system_monitor PRIVATE /permissive- /Zc:__cplusplus /W4 /WX)
else()
    target_compile_options(system_monitor PRIVATE -Wall -Wextra -Werror -pedantic)
endif()


target_link_libraries(system_monitor PRIVATE Qt6::Widgets)