
#include "src/window.h"
#include "src/shader.h"
#include "src/vbo.h"
#include "src/ebo.h"
#include "src/vao.h"
#include "src/image.h"
#include "src/texture.h"

int main() {
    Window* window = new Window(800, 800, "Example 6: Texture");

    std::vector<float> vertices = {
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f,
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  
    };
    std::vector<unsigned int> indices = {
        0, 1, 3,
        1, 2, 3
    }; 
    
    Shader* shader = new Shader("shaders/06_texture.vert", "shaders/06_texture.frag");
    VBO* vbo = new VBO(vertices);
    EBO* ebo = new EBO(indices);
    VAO* vao = new VAO(shader, vbo, ebo);

    // Create an Image
    Image* image = new Image("textures/container.jpg");
    // Create texture from the image
    Texture* texture = new Texture(image);
    // Set the filter on the texture
    texture->setFilter(GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
    // Bind the texture to a texture unit
    texture->use(shader, "texture1", 0);

    while (window->isRunning()) {
        window->clear(0.2, 0.3, 0.3, 1.0);
        vao->render();
        window->render();
    }

    delete image;
    delete texture;
    delete vbo;
    delete ebo;
    delete shader;
    delete window;
}