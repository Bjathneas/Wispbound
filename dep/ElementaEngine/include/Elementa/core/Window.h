//
// Created by benajah on 4/7/24.
//

#ifndef WISPBOUND_WINDOW_H
#define WISPBOUND_WINDOW_H

#include <GL/glew.h>
#include <functional>

#include "Elementa/core/InputHandler.h"
#include "Elementa/graphics/Color.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"

#define DELTA_TIME window.delta_time

namespace Elementa {
    typedef struct Window_ {
        GLFWwindow *glfw_window{nullptr};
        Color background_color{colorFromRGB(135, 206, 235)};
        int fps_limit{0};
        double fps{0.0}, delta_time;
        bool vsync{true}, show_debug_info;
        const char *title{};
        std::function<void()> update, render;

    } Window;

    extern Window window;

    int createWindow(const char *title, int width, int height, std::function<void()> update_function,
                     std::function<void()> render_function);

    void startWindow();

    void renderUI();

    void setWindowVsync(bool vsync);

    void setWindowFpsLimit(int fps_limit);

    void setWindowTitle(const char *title);

    void setWindowBackground(Color color);

    int getWindowWidth();

    int getWindowHeight();

    static void windowFramebufferSizeCallback(GLFWwindow *glfw_window, int width, int height);
}

#endif //WISPBOUND_WINDOW_H
