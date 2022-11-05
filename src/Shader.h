#pragma once

#include <string>
#include <unordered_map>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

class Shader
{
private:
    std::string m_Filepath;
    uint32_t m_RendererID;

    std::unordered_map<std::string, int> m_UniformLocationCache;
public:
    Shader(const std::string& filepath);
    ~Shader();

    ShaderProgramSource ParseShader(const std::string& filePath);
    uint32_t CompileShader(uint32_t type, const std::string& source);
    uint32_t CreateShader(const std::string& m_VertexShader, const std::string& m_FragmentShader);

    void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    uint32_t GetUniformLocation(const std::string& name);


    void Bind() const;
    void Unbind() const;
};