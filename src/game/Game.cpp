#include <GL/glew.h>

#include "Game.h"
#include "Triangle.h"

Game::Game(uint32_t width, uint32_t height, const char* title)
    :height(height), width(width), title(title), keys(), gameWindow()
{
}

void Game::ProcessInput(float dt)
{

}

void Game::Init()
{
    if (!glfwInit())
        return;
    
    gameWindow = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!gameWindow)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(gameWindow);

    if(!glewInit()){
        return;
    }
}

void Game::Update(float dt)
{
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(gameWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        /* Swap front and back buffers */
        glfwSwapBuffers(gameWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }
}

void Game::Render()
{
    Triangle triangle;
}

void Game::Run()
{
    Init();
    Render();
    Update(0.2f);
}

Game::~Game()
{
    glfwTerminate();
}