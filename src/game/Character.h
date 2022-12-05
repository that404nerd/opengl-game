#pragma once

#include <GL/glew.h>
#include <iostream>
#include <memory>

#include "../core/include/Shader.h"

class Character
{
private:
    uint32_t m_RendererID;
    Shader m_Shader;
public:
    Character();
    void Init();

    void Render();

    ~Character();
};