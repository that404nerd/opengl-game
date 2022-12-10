#include "Character.h"

Character::Character() {}

void Character::Init()
{
    float vertexPositions[] = {
         -0.5f, -0.5f, 0.0f,
          0.5f, -0.5f, 0.0f,
          0.0f,  0.5f, 0.0f, 
    };

    glGenBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12, 0);
    glEnableVertexAttribArray(0);

    std::string vertexSource = R"(
        #version 330 core

        layout(location = 0) in vec3 a_Position;

        void main()
        {
            gl_Position = vec4(a_Position, 1.0);
        }
    )";

    std::string fragmentSource = R"(
        #version 330 core

        layout(location = 0) out vec4 color;

        void main()
        {
            color = vec4(0.8, 0.2, 0.3, 1.0);
        }
    )";

    m_Shader.CreateShader(vertexSource.c_str(), fragmentSource.c_str());
}

void Character::MoveCharacter()
{
    if(m_Event.GetKeyInput(GLFW_KEY_A))
    {
        m_Log.Warn("Pressed Key A");
    }
}

void Character::Render()
{
    m_Shader.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

Character::~Character()
{
}