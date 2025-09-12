/**
 * @file 07_transformation.cpp
 * @author Jonah Coffelt
 * @brief Shows how to create and apply transformations
 * @version 0.1
 * @date 2025-09-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "src/window.h"
#include "src/shader.h"
#include "src/vbo.h"
#include "src/ebo.h"
#include "src/vao.h"
#include "src/image.h"
#include "src/texture.h"
#include "src/mat.h"

int main() {
    // Create a GLFW window
    Window* window = new Window(800, 800, "Example 7: Transformation");

    // Vertex data for a quad
    std::vector<float> vertices = {
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  
    };
    // Index data for a quad
    std::vector<unsigned int> indices = {
        0, 1, 3,
        1, 2, 3
    }; 
    
    // Load shader from file
    Shader* shader = new Shader("shaders/07_transformation.vert", "shaders/07_transformation.frag");
    // Create a buffer from the vertex data
    VBO* vbo = new VBO(vertices);
    // Create a buffer from the index data
    EBO* ebo = new EBO(indices);
    // Create a VAO from the shader, vbo, and ebo
    VAO* vao = new VAO(shader, vbo, ebo);

    // Create an Image
    Image* image = new Image("textures/container.jpg");
    // Create texture with the image
    Texture* texture = new Texture(image);
    // Set the filter on the texture to linear
    texture->setFilter(GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
    // Bind the texture to texture unit 0
    texture->use(shader, "texture1", 0);

    Matrix* transform;

    // Main loop continues as long as the window is open
    while (window->isRunning()) {
        // Fill the screen with a low blue color
        window->clear(0.2, 0.3, 0.3, 1.0);

        // Get time for animation
        float t = (float)glfwGetTime();
        // Create transformations
        transform->makeIdentity();
        transform->translate({sin(t) * 0.5, cos(t) * 0.5, 0.0});
        transform->rotate({0.0, 0.0, 1.0}, t);
        transform->scale({0.5, 0.5, 1.0});
        // Write the tranformation on the shader
        shader->setUniform("transform", transform->getMatrix());

        // Render the quad vao
        vao->render();
        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete image;
    delete texture;
    delete vbo;
    delete ebo;
    delete shader;
    delete window;
}