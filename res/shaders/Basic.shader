#shader vertex
#version core 330

layout (location=0) in vec3 positions;

void main()
{
    gl_Position = vec4(positions, 0.0f);
}

#shader fragment
#version core 330

out vec4 triangleColor;

void main()
{
    triangleColor = vec4(1.0f, 0.8f, 0.2f, 1.0f);
}