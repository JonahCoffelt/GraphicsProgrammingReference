#include "instancer.h"

Instancer::Instancer(Shader* shader, Mesh* mesh) : mesh(mesh){
    vbo = new VBO(mesh->getVertices());
    ebo = new EBO(mesh->getIndices());

    
}
