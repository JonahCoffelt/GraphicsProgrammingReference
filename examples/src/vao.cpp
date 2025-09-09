#include "vao.h"

/**
 * @brief Construct a new VAO object with a shader object, VBO, and optional EBO
 * 
 * @param shader The shader to use when rendering the vao
 * @param vertices The buffer (VBO pointer) of the verticies
 * @param indices Optional buffer (EBO pointer) of the indices
 */
VAO::VAO(Shader* shader, VBO* vertices, EBO* indices): shader(shader), vbo(vertices), ebo(indices) {
    // Create a new VAO
    glGenVertexArrays(1, &ID);

    // Bind the VBO and EBO
    bind();
    vbo->bind();
    if (ebo) { ebo->bind(); } 

    // Bind attributes
    bindAttribute(0, 3, GL_FLOAT, 3 * sizeof(float), 0);
}

/**
 * @brief Binds an attribute on the vao.
 * 
 * @param location The location of the attribute in the shader source
 * @param count The number of components in the attribute (1 for float, 3 for vec3, etc.)
 * @param dataType OpenGL data type, such as GL_FLOAT, GL_INT
 * @param stride Space between each occurrence of the attribute in the VBO
 * @param offset Starting point of attribute in the VBO
 */
void VAO::bindAttribute(GLint location, GLint count, unsigned int dataType, unsigned int stride, unsigned int offset) {
    bind();
    glVertexAttribPointer(location, count, GL_FLOAT, dataType, stride, (const void*)(GLintptr)offset);
    glEnableVertexAttribArray(location);  
}

/**
 * @brief Binds this VAO for rendering
 * 
 */
void VAO::bind() {
    glBindVertexArray(ID);
}

/**
 * @brief Renders this VAO based on current data
 * 
 */
void VAO::render() {
    // Use the shader and this VAO
    shader->use();
    bind();
    
    // Choose render method based on EBO
    if (ebo) {
        int nVerts = ebo->getSize() / sizeof(unsigned int);
        glDrawElements(GL_TRIANGLES, nVerts, GL_UNSIGNED_INT, 0);
    }
    else {
        int nVerts = vbo->getSize() / (sizeof(float) * 3);
        glDrawArrays(GL_TRIANGLES, 0, nVerts);
    }
}