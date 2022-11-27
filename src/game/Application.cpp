#include <GL/glew.h>

#include <GLFW/glfw3.h>
#include <iostream>

#include "Game.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define TITLE "Game"

int main()
{
    Game game(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
}