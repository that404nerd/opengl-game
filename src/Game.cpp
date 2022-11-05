#include "Game.h"
#include "Texture.h"

#include <iostream>

Game::Game(unsigned int width, unsigned int height) 
    : m_State(GAME_ACTIVE), m_Keys(), m_Width(width), m_Height(height)
{ 

}

void Game::Init()
{
   Texture texture("../res/textures/wall.png"); 
}

void Game::Update(float dt)
{
    
}

void Game::ProcessInput(float dt)
{
   
}

void Game::Render()
{
    
}

Game::~Game()
{
}