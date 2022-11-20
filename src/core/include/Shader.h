#pragma once

#include <string>
#include <unordered_map>
#include <cstdint>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

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

    void SetFloat(const char *name, float value);
    void SetInteger(const char *name, int value);
    void SetVector2f(const char *name, float x, float y);
    void SetVector3f(const char *name, glm::vec3& vec3);
    void SetVector4f(const char *name, const glm::vec4 &value);
    void SetMatrix4(const char *name, const glm::mat4 &matrix);

    uint32_t GetUniformLocation(const std::string& name);

    void Bind() const;
    void Unbind() const;
};