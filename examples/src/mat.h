#ifndef MAT_H
#define MAT_H

#include "includes.h"

class Matrix {
    private:
        glm::mat4 matrix;

    public:
        Matrix();

        void makeIdentity();
        
        void translate(glm::vec3 translation);
        void rotate(glm::vec3 axis, float rotation);
        void scale(glm::vec3 scale);

        glm::mat4 getMatrix() { return matrix; }
};

#endif