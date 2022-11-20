#pragma once

#include <cstdint>

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
};

class Game
{
public:
    GameState m_State;	
    bool m_Keys[1024];
    bool m_KeysProcessed[1024];
    uint32_t m_Width, m_Height;
public:
     Game(uint32_t width, uint32_t height);
    ~Game();
    // initialize game state (load all shaders/textures/levels)
    void Init();
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};