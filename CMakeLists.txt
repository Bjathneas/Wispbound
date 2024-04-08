cmake_minimum_required(VERSION 3.29)
set(CMAKE_CXX_STANDARD 20)

option(DEBUG_MODE "Show debug messages" OFF)

project(Wispbound)

if(DEBUG_MODE)
    add_definitions(-DELEMENTA_DEBUG_MODE)
endif ()

add_subdirectory(dep/ElementaEngine)

add_executable(Wispbound main.cpp
        dep/ElementaEngine/include/Elementa/core/Window.h)

target_link_libraries(Wispbound Elementa)