#include "Game.h"

Game::Game(uint32_t width, uint32_t height, const char* title)
    :height(height), width(width), title(title), keys(), gameWindow()
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
}

void Game::ProcessInput(float dt)
{

}

void Game::Update(float dt)
{
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(gameWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(gameWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

}

void Game::Render()
{
    Init();
    Update(0.2f);
}

Game::~Game()
{
    glfwTerminate();
}