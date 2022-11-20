#pragma once

#include <cstdint>

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
};

class Game
{
private:
    GameState State;	
    bool m_Keys[1024];
    bool m_KeysProcessed[1024];
    uint32_t m_Width, m_Height;
public:
    Game();
    ~Game();

    void Init();

    void ProcessInput(float dt);
    void Update(float dt);
    void Render();
};