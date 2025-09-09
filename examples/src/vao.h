#ifndef VAO_H
#define VAO_H

#include "includes.h"
#include "vbo.h"
#include "ebo.h"
#include "shader.h"

class VAO {
    private:
        unsigned int ID;
        Shader* shader;
        VBO* vbo;
        EBO* ebo;

    public:
        VAO(Shader* shader, VBO* vertices, EBO* indices=nullptr);
        ~VAO();

        void render();
        
        void bind();
        void bindAttribute(GLint location, GLint count, unsigned int dataType, unsigned int stride, unsigned int offset);
};

#endif