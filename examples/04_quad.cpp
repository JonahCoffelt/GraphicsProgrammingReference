/**
 * @file 04_quad.cpp
 * @author Jonah Coffelt
 * @brief Shows how to use a VBO and and EBO to render a quad
 * @version 0.1
 * @date 2025-09-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "src/window.h"
#include "src/shader.h"
#include "src/vbo.h"
#include "src/ebo.h"
#include "src/vao.h"

int main() {
    // Create a GLFW window
    Window* window = new Window(800, 800, "Example 3: Triangle");

    // Vertex data for a quad
    std::vector<float> vertices = {
        0.5f,  0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f 
    };
    // Index data for a quad
    std::vector<unsigned int> indices = {
        0, 1, 3,
        1, 2, 3
    }; 
    
    // Load shader from file
    Shader* shader = new Shader("shaders/04_quad.vert", "shaders/04_quad.frag");
    // Create a buffer from the vertex data
    VBO* vbo = new VBO(vertices);
    // Create a buffer from the index data
    EBO* ebo = new EBO(indices);
    // Create a VAO from the shader, vbo, and ebo
    VAO* vao = new VAO(shader, vbo, ebo);

    // Main loop continues as long as the window is open
    while (window->isRunning()) {
        // Fill the screen with a low blue color
        window->clear(0.2, 0.3, 0.3, 1.0);
        // Render the quad vao
        vao->render();
        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete vbo;
    delete ebo;
    delete shader;
    delete window;
}