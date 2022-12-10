#pragma once

#include "../../gpch.h"

class Shader
{
private:
    uint32_t m_RendererID;
    std::unordered_map<std::string, int> m_UniformLocationCache;
public:
    Shader();
    ~Shader();

    void CreateShader(const char* vertexSource, const char* fragmentSource);
    //void CreateShader(const char* vertexPath, const char* fragmentPath);

    void CheckCompileErrors(uint32_t shader, std::string type);
    uint32_t GetUniformLocation(const std::string& name);

    void SetFloat(const char *name, float value);
    void SetInteger(const char *name, int value);
    void SetVector2f(const char *name, float x, float y);
    void SetVector3f(const char *name, glm::vec3& vec3);
    void SetVector4f(const char *name, const glm::vec4 &value);
    void SetMatrix4(const char *name, const glm::mat4 &matrix);

    void Bind() const;
    void Unbind() const;
};