#pragma once

#include <GL/glew.h>

class VertexBuffer
{
private:
    uint32_t m_RendererID;
public:
    VertexBuffer();
    VertexBuffer(const void* data, uint32_t size);

    void Bind();

    ~VertexBuffer();
};

class IndexBuffer
{
private:
    uint32_t m_RendererID;
public:
    IndexBuffer(uint32_t* data, uint32_t indicies);

    void Bind();

    ~IndexBuffer();
};