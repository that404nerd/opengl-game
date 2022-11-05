#pragma once

#include "Shader.h"
#include "Texture.h"
#include <glm/glm.hpp>

class Sprite
{
public:
    Sprite(Shader& shader);
    ~Sprite();

    void DrawSprite(Texture& texture);
};