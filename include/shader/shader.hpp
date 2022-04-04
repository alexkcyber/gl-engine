#pragma once
#include <iostream>
#include <glm/glm.hpp>
#include "../glad/glad.h"

class Shader {
    public:
        Shader(); // Constructor
        unsigned int shaderProgram; // Store the GL shader program

        // Loads the shaders and tests them
        // vPath: vertex shader path
        // fPath: fragment shader path
        void loadShaders(const char* vPath, const char* fPath);


        // Link all of the shaders loaded into shaderProgram
        void linkProgram();

        // Tell OpenGL to use shaderProgram
        void useProgram();
    private:
        // Reads a file path and returns
        // filePath: path to our shader file
        // Return the file as a string
        std::string readFile(const char* filePath);

        // Test the shader after it's been compiled
        // shader: the return of 'glCreateShader()'
        // Return 1 if successful, 0 if error
        unsigned int testShader(unsigned int shader);
};
