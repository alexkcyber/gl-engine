#include "../../include/shader/shader.hpp"
#include <fstream>
#include <sstream>

// Constructor
// Create a shader program and assign it
Shader::Shader() {
    shaderProgram = glCreateProgram();
}

// Link all of the shaders loaded into shaderProgram
void Shader::linkProgram() {
    glLinkProgram(shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    // Check if linking was successful
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout <<
            "ERROR: SHADER PROGRAM LINKING ERROR\n" <<
            infoLog << std::endl;
    }
}

// Sets a 4x4 uniform matrix in the shader
// uniName: String name of uniform
// matrix: 4x4 matrix
void Shader::setUniformM4(const char* uniName, glm::mat4 &matrix) {
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, uniName),
            1, GL_FALSE, &matrix[0][0]);
}

// Sets a vec3 uniform in the shader
// uniName: String name of uniform
// vec: a vector 3
void Shader::setUniformV3(const char* uniName, glm::vec3 &vec) {
    glUniform3fv(glGetUniformLocation(shaderProgram, uniName), 1, &vec[0]);
}

// Sets a float uniform in the shader
// uniName: String name of uniform
// f: float number
void Shader::setUniformF1(const char* uniName, float f) {
    glUniform1f(glGetUniformLocation(shaderProgram, uniName), f);
}

// Tell OpenGL to use shaderProgram
void Shader::useProgram() {
    glUseProgram(shaderProgram);
}

// Reads a file path and returns
// filePath: path to our shader file
// Return the file as a string
std::string Shader::readFile(const char* filePath) {
    std::string fileStr; std::ifstream fileStream(filePath, std::ios::in);
    if (fileStream.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "ERROR: SHADER FILE IS EMPTY" << std::endl;
        return fileStr;
    } else {
        std::string line = "";
        while(!fileStream.eof()) {
            std::getline(fileStream, line);
            fileStr.append(line + "\n");
        }
        fileStream.close();
        return fileStr;
    }
}

// Test the shader after it's been compiled
// shader: the return of 'glCreateShader()'
// return 1 if successful, 0 if error
unsigned int Shader::testShader(unsigned int shader) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER COMPILATION ERROR\n" << infoLog <<std::endl;
        return 0;
    }
    return 1;
}

// Loads the shaders and tests them
// vPath: vertex shader path
// fPath: fragment shader path
void Shader::loadShaders(const char* vPath, const char* fPath) {

    // Load, compile, and attach the vertex shader to the shaderProgram
    std::string fileStr = readFile(vPath);
    const char* vSource = fileStr.c_str();
    unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vShader, 1, &vSource, NULL);
    glCompileShader(vShader);
    if (testShader(vShader)) {
        glAttachShader(shaderProgram, vShader);
        glDeleteShader(vShader);
    }

    // Load, compile, and attach the fragment shader to the shaderProgram
    fileStr.clear();
    fileStr = readFile(fPath);
    const char* fSource = fileStr.c_str();
    unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fShader, 1, &fSource, NULL);
    glCompileShader(fShader);
    if (testShader(fShader)) {
        glAttachShader(shaderProgram, fShader);
        glDeleteShader(fShader);
    }
}

