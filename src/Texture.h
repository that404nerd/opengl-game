#pragma once

#include <cstdint>
#include <string>

class Texture
{
private:
    uint32_t m_RendererID;
    std::string m_Filepath;
    int m_Width, m_Height, m_NrChannels;
    uint8_t* m_LocalBuffer;
public:
    Texture(const std::string& path);
    ~Texture();

    int GetWidth() const { return m_Width; }
    int GetHeight() const { return m_Height; }

    void Bind(uint32_t slot = 0) const;
    void Unbind() const;
};