#version 330 core

in vec3 vertexPosition_modelspace;

uniform mat4 MVP;
uniform mat4 modelMatrix;


void main() 
{
    gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;
    gl_Position =  MVP * vec4(vertexPosition_modelspace,1);
    gl_Position =  modelMatrix * gl_Position;
 }
