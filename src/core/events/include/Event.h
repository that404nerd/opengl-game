#pragma once

#include <GLFW/glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Event
{
private:
    static bool m_Keys[MAX_KEYS];
    static bool m_MouseButtons[MAX_BUTTONS];
    static double mx, my;
private:
    friend void window_resize(GLFWwindow* window, int width, int height);
    friend void key_callback(GLFWwindow* window, int scancode, int action, int mode);
public:
    void InitKeys();

    int GetKeyInput(uint32_t code);
    int GetMouseInput(uint32_t code);
    void SetCallbacks(GLFWwindow* window);
public:
    static void window_resize(GLFWwindow* window, int width, int height);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
};