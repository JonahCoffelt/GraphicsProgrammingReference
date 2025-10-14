/**
 * @file 12_node.cpp
 * @author Jonah Coffelt
 * @brief 
 * @version 0.1
 * @date 2025-09-30
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
#include "src/camera.h"
#include "src/mouse.h"
#include "src/keyboard.h"
#include "src/mesh.h"
#include "src/node.h"

int main() {
    // Create a GLFW window
    Window* window = new Window(800, 800, "Example 13: Instance");
    glEnable(GL_CULL_FACE);  // For preformance
    
    // Create a key object for keyboard inputs
    Keyboard* keys = new Keyboard(window);
    // Create a mouse object for mouse input
    Mouse* mouse = new Mouse(window);
    mouse->setGrab();

    // Create a camera object
    Camera camera({-3, 0, 0});

    // Vertex data for a cube
    Mesh* sphereMesh = new Mesh("models/cube.obj");
    // Load shader from file
    Shader* shader = new Shader("shaders/13_instance.vert", "shaders/13_instance.frag");
    // Create a texture from image
    Image* image = new Image("textures/container.jpg");
    Texture* texture = new Texture(image);
    texture->setFilter(GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

    // Create VBO, EBO, and VAO
    VBO* vbo = new VBO(sphereMesh->getVertices());
    EBO* ebo = new EBO(sphereMesh->getIndices());
    VAO* vao = new VAO(shader, vbo, ebo);

    // Create buffer of instance data (just a grid of positions in this case)
    std::vector<float> translations {};
    int n = 10;
    float offset = 5.0f;
    for (int x = -n; x < n; x++) {
        for (int y = -n; y < n; y++) {
            for (int z = -n; z < n; z++) {
                translations.push_back(x * offset);
                translations.push_back(y * offset);
                translations.push_back(z * offset);
            }
        }
    }
    VBO* instanceVBO = new VBO(translations);

    // Bind the buffer and instance buffer
    vao->bindBuffer(vbo, ebo, {"in_position", "in_uv", "in_normal"});
    vao->bindBuffer(instanceVBO, {"instance_position"}, 1);

    // Main loop continues as long as the window is open
    while (window->isRunning()) {
        // Fill the screen with a low blue color
        window->clear(0.2, 0.3, 0.3, 1.0);
        // Update Mouse
        mouse->update();
        if (keys->getPressed(GLFW_KEY_ESCAPE)) {
            mouse->setVisible();
        }
        if (mouse->getClicked()) {
            mouse->setGrab();
        }
        // Update the camera for movement
        camera.update(mouse, keys);
        // Use the camera on the shader
        camera.use(shader);
        // Update and render the node

        // vao->render();
        vao->bind();
        shader->use();
        // GL_TRIANGLES, 0, ebo->getSize(), 100
        glDrawElementsInstanced(GL_TRIANGLES, ebo->getSize(), GL_UNSIGNED_INT, 0, (n * 2) * (n * 2) * (n * 2)); 
        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete image;
    delete texture;
    delete shader;
    delete window;
}