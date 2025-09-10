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
    Window* window = new Window(800, 800, "Example 5: Color");

    std::vector<float> vertices {
        -0.5f, -0.5f, 0.0f,   1.0, 0.0, 0.0,
         0.5f, -0.5f, 0.0f,   0.0, 1.0, 0.0,
         0.0f,  0.5f, 0.0f,   0.0, 0.0, 1.0,
    };  
    
    Shader* shader = new Shader("shaders/05_color_attrib.vert", "shaders/05_color_attrib.frag");
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