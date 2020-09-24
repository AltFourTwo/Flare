#Shader Vertex
#version 460 core

layout(location = 0) in vec4 x_Position;

void main()
{
   gl_Position = x_Position;
};

#Shader Fragment
#version 460 core

layout(location = 0) out vec4 x_Color;

void main()
{
   x_Color = vec4(0.75, 0.50, 0.0, 1.0);
};
