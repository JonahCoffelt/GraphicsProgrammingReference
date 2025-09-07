#ifndef VBO_H
#define VBO_H

#include "includes.h"

class VBO {
    private:
        unsigned int ID;
        unsigned int size;

    public:
        VBO(const void* data, unsigned int size, bool dynamic=false);
        template<typename T>
        VBO(const std::vector<T>& data, unsigned int bufferType, bool dynamic=false) : Buffer(data.data(), data.size() * sizeof(T), bufferType=GL_ARRAY_BUFFER, dynamic=false) {}
        ~VBO();
};

#endif