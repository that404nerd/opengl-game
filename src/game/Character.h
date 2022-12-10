#pragma once

#include "../gpch.h"

class Character
{
private:
    uint32_t m_RendererID;
private:
    Event m_Event;
public:
    Character();
    void Init();

    void MoveCharacter();

    void Render();

    ~Character();
};