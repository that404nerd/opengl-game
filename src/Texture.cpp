#include <GL/glew.h>
#include "Texture.h"

Texture::Texture(const std::string& path)
    :m_RendererID(0), m_Filepath(path), m_Width(0),
     m_Height(0), m_NrChannels(0), m_LocalBuffer(nullptr)
{
    // stbi_set_flip_vertically_on_load(1);
    // m_LocalBuffer = stbi_load(path.c_str(), &m_Width, &m_Height, &m_NrChannels, 4);

    // glGenTextures(1, &m_RendererID);
    // glBindTexture(GL_TEXTURE_2D, m_RendererID);

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA,
    //             GL_UNSIGNED_INT, m_LocalBuffer);
    // glBindTexture(GL_TEXTURE_2D, 0);

    // if(m_LocalBuffer)
    //     stbi_image_free(m_LocalBuffer);
}   

Texture::~Texture()
{
    glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind(uint32_t slot) const
{
    glActiveTexture(GL_TEXTURE0 + slot);
    glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::Unbind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

