#pragma once

#include <cstdint>

class IndexBuffer
{
private:
    uint32_t m_RendererID;
public:
    IndexBuffer(uint32_t* data, uint32_t count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;
};