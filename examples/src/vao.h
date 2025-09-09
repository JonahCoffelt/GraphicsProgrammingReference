#ifndef VAO_H
#define VAO_H

#include "includes.h"
#include "vbo.h"
#include "ebo.h"
#include "shader.h"

class VAO {
    private:
        unsigned int ID;

    public:
        VAO(Shader* shader, VBO* vertices, EBO* indices=nullptr);
        ~VAO();

        void bindAttribute(GLint location, GLint count, unsigned int stride, unsigned int offset, unsigned int dataType=GL_FLOAT);
};

#endif