#pragma once

#include <array>
#include <cstdint>
#include <GLFW/glfw3.h>

enum class GameState
{
    NONE = 0,
    GAME_WIN = 1,
    GAME_PAUSE = 2,
    GAME_MENU = 3,
    GAME_QUIT = -1,
};

class Game
{
private:
    // The Game State
    GameState gameState = GameState::NONE;
    std::array<int, 1024> keys; // keys
    uint32_t width, height;
    const char* title;
    GLFWwindow* gameWindow;
public:
    Game(uint32_t width, uint32_t height, const char* title); // Define the width and height of the window
    ~Game();

    void Render(); // Render the actual game
    void Update(float dt); // To update the game every frame?
    void ProcessInput(float dt); // To Process Input

    void Init(); // To intialize shaders, sprites and stuff

};