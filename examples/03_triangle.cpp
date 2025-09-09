/**
 * @file 03_triangle.cpp
 * @author Jonah Coffelt
 * @brief Shows how to render a simple triangle
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
    Window* window = new Window(800, 800, "Example 3: Triangle");

    std::vector<float> vertices {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };  
    
    Shader* shader = new Shader("shaders/03_triangle.vert", "shaders/03_triangle.frag");
    VBO* vbo = new VBO(vertices);
    VAO* vao = new VAO(shader, vbo);

    while (window->isRunning()) {
        window->clear(0.2, 0.3, 0.3, 1.0);
        vao->render();
        window->render();
    }

    delete vbo;
    delete shader;
    delete window;
}