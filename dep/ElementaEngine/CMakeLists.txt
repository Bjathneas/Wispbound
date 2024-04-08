cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

project(Elementa)

add_subdirectory(deps/imgui)

add_library(Elementa
        src/core/Window.cpp
        src/Engine.cpp
        src/utils/Logger.cpp
        include/Elementa/core/InputHandler.h
        src/core/InputHandler.cpp
        include/Elementa/graphics/Shader.h
        include/Elementa/graphics/VBO.h
        include/Elementa/graphics/VAO.h
        include/Elementa/graphics/Sprite.h
        include/Elementa/ecs/Entity.h
        include/Elementa/ecs/Component.h
)

target_include_directories(Elementa PUBLIC include)
target_link_libraries(Elementa OpenGL::GL)
target_link_libraries(Elementa glfw)
target_link_libraries(Elementa GLEW::GLEW)
target_link_libraries(Elementa imgui)

