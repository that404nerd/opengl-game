#pragma once

#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <iostream>

#include "../events/include/Event.h"

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

struct WindowProps
{
    uint32_t WindowWidth;
    uint32_t WindowHeight;
    const char* WindowTitle;

    WindowProps(uint32_t windowWidth = 1280,
            uint32_t windowHeight = 720,
            const char* windowTitle = "Game")
        : WindowWidth(windowWidth), WindowHeight(windowHeight),
          WindowTitle(windowTitle)
    {};
};

class Window
{
private:
    GLFWwindow* m_Window;
    Event m_Event;

    uint32_t m_WindowWidth;
    uint32_t m_WindowHeight;

    struct WindowData
    {
        uint32_t WindowWidth;
        uint32_t WindowHeight;
        const char* WindowTitle;
    } m_WindowData;
public:
    int InitWindow(const WindowProps& props = WindowProps());
    Window(const uint32_t& windowWidth, const uint32_t& windowHeight, const char* windowTitle);
    Window();

    void MakeWindowContextCurrent();
    void DestroyWindow();

    inline uint32_t GetWindowWidth() const { return m_WindowData.WindowWidth; }
    inline uint32_t GetWindowHeight() const { return m_WindowData.WindowHeight; }

    inline GLFWwindow* GetWindowInstance() const { return m_Window; }

    ~Window();
};