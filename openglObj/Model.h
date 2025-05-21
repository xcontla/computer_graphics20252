// Model.h
#ifndef MODEL_H
#define MODEL_H
#include <string>
#include <GL/glew.h>
#include "Shader.h"


class Model {

public:
    GLuint VBO;
    GLuint VAO;
    GLuint shaderID;
    GLfloat* vertices; 
    int numVertices;


public:
    Model(int num);
    ~Model();
    void createCircle( float radius);
    void initializeModel();
    void bindShader(const std::string& vertexPath, const std::string& fragmentPath);
    void draw();
    
    


};

#endif