#pragma once

#include <GL/glew.h>
#include "Shader.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <cstdint>

class SpriteRenderer
{
public:
    SpriteRenderer(Shader &shader);
    ~SpriteRenderer();

    void DrawSprite(Texture2D &texture, glm::vec2 position, 
        glm::vec2 size = glm::vec2(10.0f, 10.0f), float rotate = 0.0f, 
        glm::vec3 color = glm::vec3(1.0f));
private:
    Shader m_Shader; 
    uint32_t m_QuadVAO;

    void InitRenderData();
};