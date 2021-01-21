#pragma once
#include <stdio.h>
#include <glad/glad.h>
typedef char * Shader;
typedef int C_Shader;

typedef struct
{
    float r;
    float g;
    float b;
    float alpha;
    //float rgb[3] = {r/255.0, g/255.0, b/255.0};
    // This struct is for later, when i get materials working
    // Material mat;
} FragShader;


// Create Fragment Shader from RGB values
Shader CreateFragmentShaderFromRGB(float r, float g, float b, float alpha)
{
    Shader source;
    sprintf(source, "#version 330 core\nout vec4 FragColor;\nvoid main()\n{\n   FragColor = vec4(%ff, %ff, %ff, %ff);\n}\n\0", r, g, b, alpha);
    return source;
}

Shader CreateVertexShaderFromXYZ(float x, float y)
{
    Shader source;
    sprintf(source, "#version 330 core\n layout (location = 0) in vec3 aPos;\n void main()\n {\n   gl_Position = vec4(%ff, %ff, 0.0f, 1.0);\n }\0", x, y);
    return source;
}

C_Shader CompileFragmentShader(Shader shader)
{
    C_Shader fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &shader, NULL);
    glCompileShader(fragmentShader);
    int success;
    char infoLog[512];

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        printf("\e[0;31m!! Fatal Error !! \e[4;31mERROR::FATAL::CompileFragmentShader::FAILED\x1B[0m\n%s",infoLog);
    }
    return fragmentShader;
}

C_Shader CompileVertexShader(Shader shader)
{
    C_Shader vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &shader, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("\e[0;31m!! Fatal Error !! \e[4;31mERROR::FATAL::CompileVertexShader::FAILED\x1b[0m\n%s", infoLog);
    }

    return vertexShader;
}