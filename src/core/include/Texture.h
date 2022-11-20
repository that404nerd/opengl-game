#pragma once

#include <cstdint>

class Texture2D
{
public:
    uint32_t m_ID;
    uint32_t m_Width, m_Height; 
    uint32_t m_InternalFormat; 
    uint32_t m_ImageFormat;
    uint32_t m_WrapS; 
    uint32_t m_WrapT; 
    uint32_t m_FilterMin;
    uint32_t m_FilterMax;

    Texture2D();
    // generates texture from image data
    void Generate(uint32_t width, uint32_t height, uint8_t* data);
    // binds the texture as the current active GL_TEXTURE_2D texture object
    void Bind() const;
};