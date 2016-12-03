#version 330

layout(triangles) in;
layout(triangle_strip, max_vertices=9) out;

void main()
{	
   vec4 a = gl_in[0].gl_Position;
   vec4 b = gl_in[1].gl_Position;
   vec4 c = gl_in[2].gl_Position;

   gl_Position = a;
   EmitVertex();
   gl_Position = 0.5*(a+b);
   EmitVertex();
   gl_Position = 0.5*(a+c);
   EmitVertex();
   EndPrimitive();

   gl_Position = b;
   EmitVertex();
   gl_Position = 0.5*(b+c);
   EmitVertex();
   gl_Position = 0.5*(a+b);
   EmitVertex();
   EndPrimitive();

   gl_Position = c;
   EmitVertex();
   gl_Position = 0.5*(a+c);
   EmitVertex();
   gl_Position = 0.5*(b+c);
   EmitVertex();
   EndPrimitive();





//   for(int i=0; i<3; i++)
//   {
//     gl_Position = gl_in[i].gl_Position;
//     EmitVertex();
//   }
//   EndPrimitive();
}
