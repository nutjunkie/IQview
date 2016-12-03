#version 120

varying vec3  normal;
varying vec4  color;

void main()
{
   color = gl_Color;
   normal = gl_NormalMatrix * gl_Normal;
   gl_Position = gl_ModelViewProjectionMatrix*gl_Vertex;
}
