#include "include/shader/shader.hpp"
#include <glm/glm.hpp>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

// BEGIN GLOBAL VARIABLES -----------------------------------------------------
unsigned int g_screenWidth = 1400, g_screenHeight = 800;
const char* g_appName = "OpenGL Graphics";
// END GLOBAL VARIABLES -------------------------------------------------------

// BEGIN MAIN FUNCTION --------------------------------------------------------
int main(void) {

    // BEGIN INIT GLFW WINDOW -----------------------------
    GLFWwindow* window;
    if (!glfwInit()) { return -1; }
    window = glfwCreateWindow(
            g_screenWidth, g_screenHeight, g_appName, NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // END INIT GLFW WINDOW -------------------------------

    // BEGIN INIT GLAD ------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // END INIT GLAD --------------------------------------

    float vertices[] = {
        -0.5, -0.5, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, -0.5, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -1.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f
    };

    unsigned int indices[] {
        0, 1, 2,
        3, 2, 0
    };

    unsigned int VAO, VBO, IBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*6, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
            sizeof(float)*6, (void*)(sizeof(float)*3));
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
            sizeof(indices), indices, GL_STATIC_DRAW);

    Shader shader;
    shader.loadShaders("src/shaders/basic.vert", "src/shaders/basic.frag");
    shader.linkProgram();
    shader.useProgram();


    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
// END MAIN FUNCTION ----------------------------------------------------------
