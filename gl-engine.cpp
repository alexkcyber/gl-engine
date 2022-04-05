#include "include/lights/dirlight.hpp"
#include "include/shader/shader.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

// BEGIN GLOBAL VARIABLES -----------------------------------------------------
unsigned int g_screenWidth = 1400, g_screenHeight = 800;
const char* g_appName = "OpenGL Graphics";

glm::vec3 g_cameraPos = glm::vec3(0.0f, 0.0f, 5.0f);
glm::vec3 g_cameraForward = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 g_cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

float g_deltaTime, g_lastFrame = 0.0f;
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

        /*
        // Vertices             // Normals
        -0.5f, -0.5f, -0.5f,    1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, -0.5f,      0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, -0.5f,     1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.5f,       0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f,      0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.5f,      1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.5f,     0.0f, 1.0f, 0.0f*/

        // Points               // Normals              // Texture Coords
        -0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,     0.0f,  0.0f, -1.0f,     1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,     0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,    0.0f,  0.0f, 1.0f,      0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,     0.0f,  0.0f, 1.0f,      1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,     0.0f,  0.0f, 1.0f,      1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,     0.0f,  0.0f, 1.0f,      1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f,  0.0f, 1.0f,      0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    0.0f,  0.0f, 1.0f,      0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,    -1.0f,  0.0f,  0.0f,    0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    -1.0f,  0.0f,  0.0f,    1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,     1.0f,  0.0f,  0.0f,     0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,     1.0f,  0.0f,  0.0f,     1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,     0.0f, -1.0f,  0.0f,     1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,     0.0f, -1.0f,  0.0f,     1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f,     0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,     0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,     0.0f,  1.0f,  0.0f,     1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,     0.0f,  1.0f,  0.0f,     1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f,  1.0f,  0.0f,     0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,     0.0f, 1.0f
    };

    unsigned int indices[] {
        // Triangle indices
        0, 1, 2,
        0, 2, 3,
        1, 2, 4,
        1, 4, 5,
        5, 4, 6,
        5, 6, 7,
        7, 0, 6,
        6, 3, 0,
        2, 6, 3,
        2, 6, 4,
        0, 5, 1,
        0, 5, 7
    };

    unsigned int VAO, VBO, IBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*8, (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
            sizeof(float)*8, (void*)(sizeof(float)*3));
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
            sizeof(indices), indices, GL_STATIC_DRAW);

    Shader shader;
    shader.loadShaders("../src/shaders/basic.vert", "../src/shaders/basic.frag");
    shader.linkProgram();
    shader.useProgram();

    glm::mat4 projection, view, model = glm::mat4(1.0f);

    projection = glm::perspective(glm::radians(45.0f),
            (float)g_screenWidth/(float)g_screenHeight, 0.1f, 100.0f);
    shader.setUniformM4("projection", projection);

    // OBJECTS IN THE SCENE -------------------------------
    DirLight light01;
    // END OBJECTS IN THE SCENE ---------------------------

    shader.setUniformV3("viewPos", g_cameraPos);
    glm::vec3 ambientLight = glm::vec3(0.0215f, 0.1745f, 0.0215f);
    shader.setUniformV3("material.ambient", ambientLight);
    glm::vec3 diffuse = glm::vec3(0.07568f, 0.61424f, 0.07568f);
    shader.setUniformV3("material.diffuse", diffuse);
    glm::vec3 specular = glm::vec3(0.633f, 0.727811f, 0.633f);
    shader.setUniformV3("material.specular", specular);
    shader.setUniformF1("material.shininess", 32.0f);

    shader.setUniformV3("dirLight.direction", light01.direction);
    shader.setUniformV3("dirLight.ambient", light01.ambient);
    shader.setUniformV3("dirLight.diffuse", light01.diffuse);
    shader.setUniformV3("dirLight.specular", light01.specular);

    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = static_cast<float>(glfwGetTime());
        g_deltaTime = currentFrame - g_lastFrame;
        g_lastFrame = currentFrame;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        view = glm::lookAt(g_cameraPos, g_cameraPos + g_cameraForward, g_cameraUp);
        shader.setUniformM4("view", view);

        model = glm::rotate(model, glm::radians(50.0f * g_deltaTime), glm::vec3(1.0f, 0.5f, 0.5f));
        shader.setUniformM4("model", model);

        //glDrawElements(GL_TRIANGLES, 3*12, GL_UNSIGNED_INT, nullptr);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
// END MAIN FUNCTION ----------------------------------------------------------
