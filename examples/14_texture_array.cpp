/**
 * @file 13_instance.cpp
 * @author Jonah Coffelt
 * @brief Shows how to use the VAO class to do instanced rendering
 * @version 0.1
 * @date 2025-10-14
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
#include "src/textureArray.h"

int main() {
    // Create a GLFW window
    Window* window = new Window(800, 800, "Example 14: Texture Array");
    glEnable(GL_CULL_FACE);  // For preformance
    
    // Create a key object for keyboard inputs
    Keyboard* keys = new Keyboard(window);
    // Create a mouse object for mouse input
    Mouse* mouse = new Mouse(window);
    mouse->setGrab();

    // Create a camera object
    Camera camera({-3, 0, 0});

    // Vertex data for a cube
    Mesh* mesh = new Mesh("models/cube.obj");
    // Load shader from file
    Shader* shader = new Shader("shaders/14_texture_array.vert", "shaders/14_texture_array.frag");
    // Create a texture from image
    Image* container = new Image("textures/container.jpg");
    Image* wall = new Image("textures/wall.jpg");

    // Create a texture array from images
    TextureArray* textureArray = new TextureArray(512, 512, {container});
    int wallIndex = textureArray->add(wall);
    shader->bind("textureArray", textureArray, 0);

    // Create VBO, EBO, and VAO
    VBO* vbo = new VBO(mesh->getVertices());
    EBO* ebo = new EBO(mesh->getIndices());
    VAO* vao = new VAO(shader, vbo, ebo);

    Matrix* transform1 = new Matrix();
    Matrix* transform2 = new Matrix();

    transform1->translate({3, 0, -2});
    transform2->translate({3, 0, 2});

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

        // Render the vao with specified number of instances
        shader->setUniform("textureLayer", 0);
        shader->setUniform("model", transform1->getMatrix());
        vao->render();
        shader->setUniform("textureLayer", wallIndex);  // Here we can use the location given when we added the wall image
        shader->setUniform("model", transform2->getMatrix());
        vao->render();

        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete container;
    delete wall;
    delete textureArray;
    delete shader;
    delete vbo;
    delete ebo;
    delete mesh;
    delete window;
}