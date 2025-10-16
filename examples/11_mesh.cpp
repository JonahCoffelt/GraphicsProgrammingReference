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

int main() {
    // Create a GLFW window
    Window* window = new Window(800, 800, "Example 11: Mesh");
    
    // Create a key object for keyboard inputs
    Keyboard* keys = new Keyboard(window);
    // Create a mouse object for mouse input
    Mouse* mouse = new Mouse(window);
    mouse->setGrab();

    // Vertex data for a cube
    Mesh* sphereMesh = new Mesh("models/sphere.obj");
    
    // Load shader from file
    Shader* shader = new Shader("shaders/11_mesh.vert", "shaders/11_mesh.frag");
    // Create a buffers from the vertex and index data
    VBO* vbo = new VBO(sphereMesh->getVertices());
    EBO* ebo = new EBO(sphereMesh->getIndices());
    // Create a VAO from the shader, VBO, and EBO
    VAO* vao = new VAO(shader, vbo, ebo);
    // Manually bind because we are not yet using normals but it appears in the mesh VBO
    vao->bindAttribute(0, 3, GL_FLOAT, 8 * sizeof(float), 0 * sizeof(float));
    vao->bindAttribute(1, 2, GL_FLOAT, 8 * sizeof(float), 3 * sizeof(float));
    vao->bindAttribute(2, 3, GL_FLOAT, 8 * sizeof(float), 5 * sizeof(float));
    
    // Create a camera object
    Camera camera({-3, 0, 0});

    // Create an Image
    Image* image = new Image("textures/container.jpg");
    // Create texture with the image
    Texture* texture = new Texture(image);
    // Set the filter on the texture to linear
    texture->setFilter(GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
    // Bind the texture to texture unit 0
    shader->bind("texture1", texture, 0);

    // Create a model matrix for the cube. It will be static in this scene
    Matrix* model = new Matrix();
    model->makeIdentity();
    shader->setUniform("model", model->getMatrix());

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
        // Render the quad vao
        vao->render();
        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete image;
    delete model;
    delete texture;
    delete vbo;
    delete shader;
    delete window;
}