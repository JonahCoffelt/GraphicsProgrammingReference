#ifndef INSTANCER_H
#define INSTANCER_H

#include "includes.h"
#include "shader.h"
#include "vbo.h"
#include "vao.h"
#include "ebo.h"
#include "mesh.h"

class Instancer {
    private:
        Mesh* mesh;
        VBO* vbo;
        VAO* vao;
        EBO* ebo;

    public:
        Instancer(Shader* shader, Mesh* mesh);
        ~Instancer();

        void add();
        void remove();

        void render();
};

#endif
