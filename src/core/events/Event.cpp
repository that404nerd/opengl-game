#include "include/Event.h"

// intialize the static variables
bool Event::m_Keys[MAX_KEYS];
bool Event::m_MouseButtons[MAX_BUTTONS];
double Event::mx;
double Event::my;

void Event::InitKeys() // Initialize all the keys to false (meaning they are not pressed)
{
    for(int i = 0;i < MAX_KEYS;i++)
    {
        m_Keys[i] = false;
    }

    for(int i = 0;i < MAX_BUTTONS;i++)
    {
        m_MouseButtons[i] = false;
    }
}

void Event::window_resize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Event::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    m_Keys[key] = action != GLFW_RELEASE;
}

void Event::SetCallbacks(GLFWwindow* window)
{
    glfwSetWindowSizeCallback(window, window_resize);
    glfwSetKeyCallback(window, key_callback);
}

int Event::GetKeyInput(uint32_t code)
{
    if(code > MAX_KEYS)
        return false;

    return m_Keys[code];
}

int Event::GetMouseInput(uint32_t code)
{
    if(code > MAX_BUTTONS)
        return false;

    return m_MouseButtons[code];
}