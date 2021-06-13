#version 330 core

layout(location = 0) out vec4 x_color;

in vec3 v_Position;
in vec4 v_Color;

void main()
{
   x_color = v_Color;
}