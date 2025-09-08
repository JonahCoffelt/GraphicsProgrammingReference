#ifndef SHADER_H
#define SHADER_H

#include "includes.h"

class Shader {
    private:
        unsigned int ID;

    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();

        void use();

        void bind(const char* name, unsigned int texture, unsigned int slot);

        int getUniformLocation(const char*   name);

        void setUniform(const char* name, float value);
        void setUniform(const char* name, double value);
        void setUniform(const char* name, int value);
        void setUniform(const char* name, glm::mat4 value);

        unsigned int getID() { return ID; }
};

#endif