/**
 * @file 01_boilerplate.cpp
 * @author Jonah Coffelt
 * @brief Minimal example for creating an OpenGL window with GLFW
 * @version 0.1
 * @date 2025-09-08
 * 
 */

#include "src/includes.h"

void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);
}

int main() {
    // Wayland fix
    const char* sessionType = getenv("XDG_SESSION_TYPE");    
    if (sessionType && std::string(sessionType) == "wayland") {
        glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
    }

    // Initialize GLFW for window
    glfwInit();

    // Set verion to GL 3.3 core
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a window based on the hints
    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Window", NULL, NULL);

    // Check the GLFW window
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return 0;
    }

    // Once the window has been created, set the OpenGL context
    glfwMakeContextCurrent(window);

    // Check GLAD initalization
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return 0;
    }

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

    while(!glfwWindowShouldClose(window)) {
        // Handle Input
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }

        // Rendering/Updating
        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // GLFW update and swap
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    // End GLFW
    glfwTerminate();
}