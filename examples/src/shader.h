#ifndef SHADER_H
#define SHADER_H

#include "includes.h"

// GLint location, GLint count, unsigned int dataType, unsigned int stride, unsigned int offset
struct Attribute {
    std::string name;
    GLint location;
    GLint count;
    GLenum dataType;
    unsigned int offset;
};

class Shader {
    private:
        unsigned int ID;
        unsigned int stride;
        std::vector<Attribute> attributes;

        void loadAttributes();

    public:
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();

        void use();

        void bind(const char* name, unsigned int texture, unsigned int slot);

        int getUniformLocation(const char* name);
        unsigned int getStride() { return stride; }
        std::vector<Attribute>& getAttributes() { return attributes; }

        void setUniform(const char* name, float value);
        void setUniform(const char* name, double value);
        void setUniform(const char* name, int value);
        void setUniform(const char* name, glm::mat4 value);

        unsigned int getID() { return ID; }
};

#endif