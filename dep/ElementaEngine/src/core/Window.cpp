//
// Created by benajah on 4/7/24.
//
#include <cmath>
#include <thread>
#include <utility>

#include "Elementa/core/Window.h"

#define TIME glfwGetTime()

namespace Elementa {

    Window window;

    int createWindow(const char *title, int width, int height, std::function<void()> update_function,
                     std::function<void()> render_function) {
        window.title = title;
        window.glfw_window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!window.glfw_window)
            return false;

        window.update = std::move(update_function);
        window.render = std::move(render_function);

        glfwSetFramebufferSizeCallback(window.glfw_window, windowFramebufferSizeCallback);

        glfwMakeContextCurrent(window.glfw_window);

        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);

        return true;
    }

    void startWindow() {
        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

        glfwSwapInterval(window.vsync);

        glClearColor(135 / 255.0, 206 / 255.0, 235 / 255.0, 1.0);

        glViewport(0, getWindowWidth(), 0, getWindowHeight());

        double previous_time = TIME;
        while (!glfwWindowShouldClose(window.glfw_window)) {
            double current_time = TIME;

            DELTA_TIME = current_time - previous_time;

            previous_time = current_time;

            window.fps = std::ceil(1.0 / DELTA_TIME);

            window.update();
            window.render();

            renderUI();

            glfwSwapBuffers(window.glfw_window);

            updateInputData();
            glfwPollEvents();

            if (window.fps_limit > 0 && !window.vsync) {
                double frame_time = 1.0 / window.fps_limit;
                double sleep_time = frame_time - (TIME - previous_time);
                if (sleep_time > 0.0)
                    std::this_thread::sleep_for(std::chrono::duration<double>(sleep_time));
            }
        }

        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImPlot::DestroyContext();
        ImGui::DestroyContext();

        glfwDestroyWindow(window.glfw_window);
        glfwTerminate();
    }

    void renderUI() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    int getWindowWidth() {
        int width, height;
        glfwGetWindowSize(window.glfw_window, &width, &height);
        return width;
    }

    int getWindowHeight() {
        int width, height;
        glfwGetWindowSize(window.glfw_window, &width, &height);
        return height;
    }

    void windowFramebufferSizeCallback(GLFWwindow *glfw_window, int width, int height) {
        glViewport(0, width, 0, height);
    }
}