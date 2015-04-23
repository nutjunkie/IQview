#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#include <QGLViewer/qglviewer.h>
#include <QGLFunctions>
#include <QGLContext>


GLuint LoadShaders(QGLContext* context,
                   const char * vertex_file_path,
                   const char * geometry_file_path,
                   const char * fragment_file_path){
QGLFunctions f(context);
 
    // Create the shaders
    GLuint VertexShaderID   = f.glCreateShader(GL_VERTEX_SHADER);
//  GLuint GeometryShaderID = f.glCreateShader(GL_GEOMETRY_SHADER);
    GLuint FragmentShaderID = f.glCreateShader(GL_FRAGMENT_SHADER);
 
    // Read the Vertex Shader code from the file
    std::string VertexShaderCode;
    std::ifstream VertexShaderStream(vertex_file_path, std::ios::in);
    if(VertexShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(VertexShaderStream, Line))
            VertexShaderCode += "\n" + Line;
        VertexShaderStream.close();
    }

/*
    // Read the Geometry Shader code from the file
    std::string GeometryShaderCode;
    std::ifstream GeometryShaderStream(geometry_file_path, std::ios::in);
    if(GeometryShaderStream.is_open())
    {
        std::string Line = "";
        while(getline(GeometryShaderStream, Line))
            GeometryShaderCode += "\n" + Line;
        GeometryShaderStream.close();
    }
*/
 
    // Read the Fragment Shader code from the file
    std::string FragmentShaderCode;
    std::ifstream FragmentShaderStream(fragment_file_path, std::ios::in);
    if(FragmentShaderStream.is_open()){
        std::string Line = "";
        while(getline(FragmentShaderStream, Line))
            FragmentShaderCode += "\n" + Line;
        FragmentShaderStream.close();
    }
 
    GLint Result = GL_FALSE;
    int InfoLogLength;
 
    // Compile Vertex Shader
    printf("Compiling shader : %s\n", vertex_file_path);
    char const * VertexSourcePointer = VertexShaderCode.c_str();
    f.glShaderSource(VertexShaderID, 1, &VertexSourcePointer , NULL);
    f.glCompileShader(VertexShaderID);
 
    // Check Vertex Shader
    f.glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    f.glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> VertexShaderErrorMessage(InfoLogLength);
    f.glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);

/*
    // Compile Geometry Shader
    printf("Compiling shader : %s\n", geometry_file_path);
    char const * GeometrySourcePointer = GeometryShaderCode.c_str();
    f.glShaderSource(GeometryShaderID, 1, &GeometrySourcePointer , NULL);
    f.glCompileShader(GeometryShaderID);
 
    // Check Geometry  Shader
    f.glGetShaderiv(GeometryShaderID, GL_COMPILE_STATUS, &Result);
    f.glGetShaderiv(GeometryShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> GeometryShaderErrorMessage(InfoLogLength);
    f.glGetShaderInfoLog(GeometryShaderID, InfoLogLength, NULL, &GeometryShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &GeometryShaderErrorMessage[0]);
*/
 
 
    // Compile Fragment Shader
    printf("Compiling shader : %s\n", fragment_file_path);
    char const * FragmentSourcePointer = FragmentShaderCode.c_str();
    f.glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer , NULL);
    f.glCompileShader(FragmentShaderID);
 
    // Check Fragment Shader
    f.glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    f.glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> FragmentShaderErrorMessage(InfoLogLength);
    f.glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);
 

    // Link the program
    fprintf(stdout, "Linking program\n");
    GLuint ProgramID = f.glCreateProgram();
    f.glAttachShader(ProgramID, VertexShaderID);
    //f.glAttachShader(ProgramID, GeometryShaderID);
    f.glAttachShader(ProgramID, FragmentShaderID);
    f.glLinkProgram(ProgramID);
 
    // Check the program
    f.glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    f.glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
    f.glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
 
    f.glDeleteShader(VertexShaderID);
    //f.glDeleteShader(GeometryShaderID);
    f.glDeleteShader(FragmentShaderID);
 
    return ProgramID;
}
