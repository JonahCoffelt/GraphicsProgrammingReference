/**
 * @file 09_cube.cpp
 * @author Jonah Coffelt
 * @brief Shows how to render a cube with transformations
 * @version 0.1
 * @date 2025-09-13
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
    Window* window = new Window(800, 800, "Example 8: Cube");

    // Vertex data for a cube
    std::vector<float> vertices {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    
    // Load shader from file
    Shader* shader = new Shader("shaders/08_cube.vert", "shaders/08_cube.frag");
    // Create a buffer from the vertex data
    VBO* vbo = new VBO(vertices);
    // Create a VAO from the shader, vbo
    VAO* vao = new VAO(shader, vbo);

    // Create an Image
    Image* image = new Image("textures/container.jpg");
    // Create texture with the image
    Texture* texture = new Texture(image);
    // Set the filter on the texture to linear
    texture->setFilter(GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
    // Bind the texture to texture unit 0
    texture->use(shader, "texture1", 0);

    // Create matrices for model, view, and projection
    Matrix model;
    Matrix view;
    Matrix projection;
    // Update the view and perspective matrices
    view.makeView({0, 0, -3}, {0, 0, 1}, {0, 1, 0});
    projection.makePerspective(45.0, 1.0, 0.1, 100.0);
    // Set the matrices on the shader
    shader->setUniform("view", view.getMatrix());
    shader->setUniform("projection", projection.getMatrix());

    // Main loop continues as long as the window is open
    while (window->isRunning()) {
        // Fill the screen with a low blue color
        window->clear(0.2, 0.3, 0.3, 1.0);

        // Get time for animation
        float t = (float)glfwGetTime();
        // Create transformations
        model.makeIdentity();
        model.translate({sin(t) * 0.5, cos(t) * 0.5, 0.0});
        model.rotate({0.0, 1.0, 1.0}, t);
        model.scale({0.5, 0.5, 0.5});
        // Write the tranformation on the shader
        shader->setUniform("model", model.getMatrix());

        // Render the quad vao
        vao->render();
        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete image;
    delete texture;
    delete vbo;
    delete shader;
    delete window;
}