cmake_minimum_required(VERSION 3.20)

find_package(glfw3 REQUIRED)

project(imgui)

add_library(imgui SHARED src/imgui.cpp
        src/imgui_demo.cpp
        src/imgui_draw.cpp
        src/imgui_widgets.cpp
        src/imgui_tables.cpp
        src/imgui_impl_glfw.cpp
        src/imgui_impl_opengl3.cpp
        src/implot.cpp
        src/implot_demo.cpp
        src/implot_items.cpp)

target_include_directories(imgui PUBLIC include)
target_link_libraries(imgui glfw)
