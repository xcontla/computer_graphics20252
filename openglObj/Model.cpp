// Model.cpp
#include "Model.h"
#include <cmath>

Model::Model(int num){

    numVertices = num;

}

void Model::createCircle(float radius) {
    vertices = new float[(numVertices + 1) * 3];
    float angleStep = 2.0f * M_PI / (float)(numVertices - 1);
    for (int i = 1; i < numVertices + 1; ++i) {
        vertices[i * 3 + 0] = radius * cosf(angleStep * (i - 1));
        vertices[i * 3 + 1] = radius * sinf(angleStep * (i - 1));
        vertices[i * 3 + 2] = 0.0f;
    }
    
}


void Model::initializeModel(){
    

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, (numVertices + 1) * 3 * sizeof(float), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

}

void Model::bindShader(const std::string& vertexPath, const std::string& fragmentPath){

    
    shaderID = Shader::createShaderProgramFromFiles(vertexPath,fragmentPath);
}

void Model::draw(){

    glUseProgram(shaderID);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_FAN, 0, numVertices + 1);
    glBindVertexArray(0);
}

Model::~Model(){ 
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderID);
    delete[] vertices;

}