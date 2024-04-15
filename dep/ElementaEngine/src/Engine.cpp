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
        ImPlot::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        ImGui_ImplGlfw_InitForOpenGL(window.glfw_window, true);
        ImGui_ImplOpenGL3_Init();
        DEBUG("DEAR IMGUI INITIALIZED");

        for (int i = 0; i < 30; i++) {
            frame_count.push_back(i);
        }
    }

    void startEngine() {
        DEBUG("STARTING APPLICATION");
        startWindow();
    }

    std::vector<double> update_frame_times, render_frame_times, frame_times, frame_count;

    void update() {
        //Update Line Graph
        if (frame_times.size() >= 30)
            frame_times.erase(frame_times.begin());

        frame_times.push_back(DELTA_TIME * 1000);

        auto start_time = glfwGetTime();

        //Actual update functionality for game
        if (keyPressed(KEY_LEFT_CONTROL) && keyJustPressed(KEY_D))
            window.show_debug_info = !window.show_debug_info;

        //Update Line Graph
        double current_frame_time = (glfwGetTime() - start_time) * 1000;
        if (update_frame_times.size() >= 30)
            update_frame_times.erase(update_frame_times.begin());


        update_frame_times.push_back(current_frame_time);
    }

    void render() {
        double start_time = glfwGetTime();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        glClear(GL_COLOR_BUFFER_BIT);
        //ImGui Debug Window
        if (window.show_debug_info) {
            ImGui::Begin("Debugging", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
            ImGui::Text("Vsync: %s", window.vsync ? "True" : "False");
            if (ImGui::CollapsingHeader("FrameTimes", ImGuiTreeNodeFlags_DefaultOpen)) {
                ImGui::Text("Delta_Time: %f", DELTA_TIME);
                ImGui::Text("FPS: %f | FPS_LIMIT: %i", window.fps, window.fps_limit);
                ImGui::Text("Update: %fms\nRender: %fms\nTotal: %fms", update_frame_times[29],
                            render_frame_times[29], DELTA_TIME * 1000);
                ImPlot::SetNextAxesToFit();
                if (ImPlot::BeginPlot("Timings", ImVec2(300, 200))) {
                    ImPlot::SetupAxes("", "Time(ms)");
                    ImPlot::PlotLine("Total", frame_count.data(), frame_times.data(), 29, ImPlotLineFlags_Shaded);
                    ImPlot::PlotLine("Update", frame_count.data(), update_frame_times.data(), 29);
                    ImPlot::PlotLine("Render", frame_count.data(), render_frame_times.data(), 29);
                    ImPlot::EndPlot();
                }
            }
            ImGui::Text("Size:\n\twidth : %ipx\n\theight: %ipx", getWindowWidth(), getWindowHeight());
            if (ImGui::Button("close")) {
                window.show_debug_info = false;
            }
            ImGui::End();
        }

        double current_frame_time = (glfwGetTime() - start_time) * 1000;

        if (render_frame_times.size() >= 30)
            render_frame_times.erase(render_frame_times.begin());


        render_frame_times.push_back(current_frame_time);
    }
}