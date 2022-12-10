#pragma once

#include "core/include/Shader.h"
#include "core/events/include/Event.h"
#include "core/include/Log.h"

class Character
{
private:
    uint32_t m_RendererID;
private:
    Event m_Event;
    Log m_Log;
    Shader m_Shader;
public:
    Character();
    void Init();

    void MoveCharacter();

    void Render();

    ~Character();
};