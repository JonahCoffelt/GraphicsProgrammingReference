#ifndef TEXTURE_H
#define TEXTURE_H

#include "image.h"
#include "shader.h"

class Texture {
    private:
        unsigned int ID;

    public:
        Texture(Image* image);
        ~Texture();

        void bind();
        void use(Shader* shader, std::string name, unsigned int slot);
        
        void setFilter(unsigned int magFilter, unsigned int minFilter);
        void setWrap(unsigned int wrap);
};

#endif