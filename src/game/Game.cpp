#include "Game.h"

////////////////////////////// Actual Game Code //////////////////////////

static Window m_Window;
static Character m_Character;

Game::Game(uint32_t width, uint32_t height, std::string title) 
{ 
    Init(width, height, title);
    Update(GetDeltaTime());
}

void Game::Init(uint32_t width, uint32_t height, std::string title)
{
    m_Character.Init();
}

void Game::Render()
{
    m_Character.Render();
}

void Game::Update(float dt)
{
   this->m_Dt = dt;
   while (!glfwWindowShouldClose(m_Window.GetWindowInstance()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.5f, 1.0f);

        float currentFrame = glfwGetTime();
        dt = currentFrame - lastFrame;
        lastFrame = currentFrame;

        Render();

        /* Swap front and back buffers */
        glfwSwapBuffers(m_Window.GetWindowInstance());

        /* Poll for and process events */
        glfwPollEvents();
        ProcessInput(dt);

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