#include <GLFW/glfw3.h>

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

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
// END MAIN FUNCTION ----------------------------------------------------------