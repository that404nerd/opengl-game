#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include "Game.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main()
{
    GLFWwindow* m_Window;
    Game game;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, false);

    glViewport(0, 0, 1280, 720);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if(!glfwInit())
    {
        return -1;
    }

    m_Window = glfwCreateWindow(1280, 720, "Game", nullptr, nullptr);
    if (!m_Window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(m_Window);
    
    game.Init();

    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while (!glfwWindowShouldClose(m_Window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        game.Update(deltaTime);

        glDrawArrays(GL_TRIANGLES, 0, 2);


        glfwSwapBuffers(m_Window);

        glfwPollEvents();
    }  

    glfwTerminate();

    return 0;
}