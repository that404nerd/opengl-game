#include "../gpch.h"

const uint32_t SCREEN_WIDTH = 1280;
const uint32_t SCREEN_HEIGHT = 720;
const char* TITLE = "Game";

int main()
{
    Game game(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
}