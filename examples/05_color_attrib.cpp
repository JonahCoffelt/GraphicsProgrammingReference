/**
 * @file 05_color_attrib.cpp
 * @author Jonah Coffelt
 * @brief Shows how to use a second attribute with the abstraction. Much of the work is done in shaders. 
 * @version 0.1
 * @date 2025-09-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "src/window.h"
#include "src/shader.h"
#include "src/vbo.h"
#include "src/vao.h"

int main() {
    // Create a GLFW window
    Window* window = new Window(800, 800, "Example 5: Color");

    // Vertex data for a triangle
    std::vector<float> vertices {
        -0.5f, -0.5f, 0.0f,   1.0, 0.0, 0.0,
         0.5f, -0.5f, 0.0f,   0.0, 1.0, 0.0,
         0.0f,  0.5f, 0.0f,   0.0, 0.0, 1.0,
    };
    
    // Load shader from file
    Shader* shader = new Shader("shaders/05_color_attrib.vert", "shaders/05_color_attrib.frag");
    // Create a buffer from the vertex data
    VBO* vbo = new VBO(vertices);
    // Create a VAO from the shader and vbo
    VAO* vao = new VAO(shader, vbo);

    // Main loop continues as long as the window is open
    while (window->isRunning()) {
        // Fill the screen with a low blue color
        window->clear(0.2, 0.3, 0.3, 1.0);
        // Render the triangle vao
        vao->render();
        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete vbo;
    delete shader;
    delete window;
}