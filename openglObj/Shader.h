// Shader.h
#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <string>

class Shader {
public:
    static GLuint createShaderProgramFromFiles(const std::string& vertexPath, const std::string& fragmentPath);
private:
    static std::string readFile(const std::string& filePath);
};

#endif