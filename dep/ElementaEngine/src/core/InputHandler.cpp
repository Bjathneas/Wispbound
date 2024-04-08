//
// Created by benajah on 4/7/24.
//
#include "Elementa/core/InputHandler.h"

#define GLFW_WINDOW glfwGetCurrentContext()

namespace Elementa {
    InputData Input;

    void initInputHandler(GLFWwindow *glfw_window) {
        glfwSetKeyCallback(glfw_window, key_callback);
        glfwSetCursorPosCallback(glfw_window, cursor_position_callback);
        glfwSetMouseButtonCallback(glfw_window, mouse_button_callback);
    }

    void updateInputData() {
        Input.changed_button_states.clear();
        Input.changed_key_states.clear();
    }

    bool keyPressed(int key) {
        return glfwGetKey(GLFW_WINDOW, key) == GLFW_PRESS;
    }

    bool keyJustPressed(int key) {
        if (!Input.changed_key_states.contains(key))
            return false;
        return Input.changed_key_states[key] == GLFW_PRESS;
    }

    bool keyJustReleased(int key) {
        if (!Input.changed_key_states.contains(key))
            return false;
        return Input.changed_key_states[key] == GLFW_RELEASE;
    }

    bool mousePressed(int button) {
        return glfwGetMouseButton(GLFW_WINDOW, button) == GLFW_PRESS;
    }

    bool mouseJustPressed(int button) {
        if (!Input.changed_button_states.contains(button))
            return false;
        return Input.changed_button_states[button] == GLFW_PRESS;
    }

    bool mouseJustReleased(int button) {
        if (!Input.changed_button_states.contains(button))
            return false;
        return Input.changed_button_states[button] == GLFW_RELEASE;
    }

    double getMouseX() {
        return Input.mx;
    }

    double getMouseY() {
        return Input.my;
    }

    static void key_callback(GLFWwindow *glfw_window, int key, int scancode, int action, int mods) {
        Input.changed_key_states[key] = action;
    }

    static void cursor_position_callback(GLFWwindow *glfw_window, double xpos, double ypos) {
        Input.mx = xpos;
        Input.my = ypos;
    }

    static void mouse_button_callback(GLFWwindow *glfw_window, int button, int action, int mods) {
        Input.changed_button_states[button] = action;
    }

}