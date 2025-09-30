/**
 * @file 11_mesh.cpp
 * @author Jonah Coffelt
 * @brief Model loading example which shows how to load a sphere mesh
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
    Window* window = new Window(800, 800, "Example 12: Node");
    
    // Create a key object for keyboard inputs
    Keyboard* keys = new Keyboard(window);
    // Create a mouse object for mouse input
    Mouse* mouse = new Mouse(window);
    mouse->setGrab();

    // Create a camera object
    Camera camera({-3, 0, 0});

    // Vertex data for a cube
    Mesh* sphereMesh = new Mesh("models/sphere.obj");
    // Load shader from file
    Shader* shader = new Shader("shaders/12_node.vert", "shaders/12_node.frag");
    // Create a texture from image
    Image* image = new Image("textures/container.jpg");
    Texture* texture = new Texture(image);
    texture->setFilter(GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);

    // Create a node from loaded data
    Node* node = new Node(shader, sphereMesh, texture);

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
        node->update();
        node->render();
        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete image;
    delete texture;
    delete node;
    delete shader;
    delete window;
}