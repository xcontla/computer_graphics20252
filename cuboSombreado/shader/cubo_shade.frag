#version 410 core
in vec3 fragNormal;
in vec3 shadedcolor;
out vec4 color;
void main()
{
    color = vec4(fragNormal, 1.0);
}