#pragma once
#include <glad/glad.h>
#include <stdio.h>
#include "Shader.h"




unsigned int VBO, VAO;
int shaderProgram;
int times_ran = 0;


void CreateTriangle(float vertices[], C_Shader fragmentShader, C_Shader vertexShader)
{

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("\e[0;31m!! Fatal Error !! \e[4;31mERROR::FATAL::CreateTriangle::CreateShaderProgram::FAILED\x1B[0m\n%s",infoLog);
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    printf("\e[0;33m<< WARNING >> \e[4;33mCompiled Vertex + Fragment Shader Cleared\n");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
}

void RenderTriangles()
{
    
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    if(times_ran == 0)
    {
        printf("\e[0;32m[[ Status ]] -- Triangle(s) Rendered\n");
        times_ran += 1;
    }
    else
    {
        // just pass :D
    }
}

