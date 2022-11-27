#include <GL/glew.h>

#include "Game.h"

float positions[6] = {
    -0.5, -0.5,
    0.0, 0.5,
    0.5, -0.5
};

////////////////////////////// Actual Game Code //////////////////////////

static Window m_Window;

Game::Game(uint32_t width, uint32_t height, std::string title) 
{ 
    Init(width, height, title);
    Update(GetDeltaTime());
}

void Game::Init(uint32_t width, uint32_t height, std::string title)
{
    unsigned int buffer;
    glGenBuffers(1, &buffer); 
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 8, (const void*)0);
    glEnableVertexAttribArray(0);
}

void Game::Render()
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Game::Update(float dt)
{
   this->m_Dt = dt;
   while (!glfwWindowShouldClose(m_Window.GetWindowInstance()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        Render();

        /* Swap front and back buffers */
        glfwSwapBuffers(m_Window.GetWindowInstance());

        /* Poll for and process events */
        glfwPollEvents();
    }

}

void Game::ProcessInput(float dt)
{
   this->m_Dt = dt; 
}

Game::~Game()
{
    m_Window.DestroyWindow();    
}