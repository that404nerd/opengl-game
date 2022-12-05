#include "../include/Shader.h"

Shader::Shader()
{

}

void Shader::CreateShader(const char* vertexSource, const char* fragmentSource)
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    const GLchar *source = vertexSource;
    glShaderSource(vertexShader, 1, &source, 0);

    // Compile the vertex shader
    glCompileShader(vertexShader);

    GLint isCompiled = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
    if(isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);
        
        glDeleteShader(vertexShader);

        return;
    }

    // Create an empty fragment shader handle
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    source = fragmentSource;
    glShaderSource(fragmentShader, 1, &source, 0);

    // Compile the fragment shader
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);
        
        glDeleteShader(fragmentShader);
        glDeleteShader(vertexShader);

        return;
    }

    m_RendererID = glCreateProgram();

    // Attach our shaders to our program
    glAttachShader(m_RendererID, vertexShader);
    glAttachShader(m_RendererID, fragmentShader);

    // Link our program
    glLinkProgram(m_RendererID);

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(m_RendererID, GL_LINK_STATUS, (int *)&isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(m_RendererID, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(m_RendererID, maxLength, &maxLength, &infoLog[0]);
        
        glDeleteProgram(m_RendererID);
        // Don't leak shaders either.
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        return;
    }

    glDetachShader(m_RendererID, vertexShader);
    glDetachShader(m_RendererID, fragmentShader);
}

void Shader::CheckCompileErrors(uint32_t shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "Error: Failed compilation of type: " << type << "\n" << infoLog << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR: Failed compilation of type: " << type << "\n" << infoLog << std::endl;
        }
    }
}

void Shader::Bind() const
{
    glUseProgram(m_RendererID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

uint32_t Shader::GetUniformLocation(const std::string& name)
{
    if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
        return m_UniformLocationCache[name];

    int location = glGetUniformLocation(m_RendererID, name.c_str());
    if (location == -1)
        std::cout << "Warning: uniform " << name << " doesn't exist!" << std::endl;
    
    m_UniformLocationCache[name] = location;
    return location;
}

void Shader::SetFloat(const char *name, float value)
{
    glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetInteger(const char *name, int value)
{
    glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetVector2f(const char *name, float x, float y)
{
    glUniform2f(GetUniformLocation(name), x, y);
}

void Shader::SetVector3f(const char *name, glm::vec3 &vec3)
{
    glUniform3f(GetUniformLocation(name), vec3.x, vec3.y, vec3.z);
}

void Shader::SetVector4f(const char *name, const glm::vec4 &value)
{
    glUniform4f(GetUniformLocation(name), value.x, value.y, value.z, value.w);
}

void Shader::SetMatrix4(const char *name, const glm::mat4 &matrix)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, false, glm::value_ptr(matrix));
}

Shader::~Shader()
{
    
}