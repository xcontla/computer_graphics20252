#version 410 core
layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_normal;
out vec3 fragColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform vec3 posCam;
//uniform vec3 posLuz;
vec3 posLuz = vec3(0.0,2.0,0.0);
vec3 colorLuz = vec3(0.0,1.0,1.0);

float coef_ambiental = 0.2;
float coef_difuso = 0.6;
float coef_especular = 0.9;

float glossines = 100.0;

vec3 colorBase = vec3(244.0, 127.0, 38.0) / 255.0;



void main()
{

    

    vec4 p = model * vec4(vertex_position,1.0);
    vec3 N = normalize((model * vec4(vertex_normal, 1.0)).xyz);
    vec3 L = normalize(posLuz - p.xyz);

    vec3 R = reflect(-L, N);
    vec3 V = normalize(posCam - p.xyz);
    vec3 H = normalize(L + V);
    



    fragColor =  colorBase * (coef_ambiental + coef_difuso * max(dot(N,L),0.0)) 
                + colorLuz * coef_especular * pow(max(dot(N,H),0.0),glossines);
                //+ colorLuz * coef_especular * pow(max(dot(R,V),0.0),glossines);
   

    gl_Position = projection * view * model * vec4(vertex_position, 1.0);
}