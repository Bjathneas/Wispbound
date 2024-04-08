//
// Created by benajah on 4/7/24.
//
#include "Elementa/Engine.h"

namespace Elementa {
    void initEngine(const char *title, int width, int height) {
        INFO("KEEP IT SIMPLE, MORE FEATURES AS THEY ARE NEEDED");
        //GLFW
        if (!glfwInit()) {
            CRITICAL("GLFW failed to initialize. Terminating application");
            exit(EXIT_FAILURE);
        }
        DEBUG("GLFW INITIALIZED");
        //Window
        if (!createWindow(title, width, height, &update, &render)) {
            CRITICAL("Window could not be created. Terminating application");
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
        DEBUG("Window CREATED");
        //InputHandler
        initInputHandler(window.glfw_window);
        //GLEW
        glewExperimental = true;
        if (!glewInit()) {
            CRITICAL("GLEW failed to initialize. Terminating application");
        }
        DEBUG("GLEW INITIALIZED");
        //Dear ImGui
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        ImGui_ImplGlfw_InitForOpenGL(window.glfw_window, true);
        ImGui_ImplOpenGL3_Init();
        DEBUG("DEAR IMGUI INITIALIZED");
    }

    void startEngine() {
        DEBUG("STARTING APPLICATION");
        startWindow();
    }

    void update() {

    }

    void render() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::ShowDemoWindow();

    }
}