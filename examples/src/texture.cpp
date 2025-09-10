#include "texture.h"

/**
 * @brief Construct a new Texture object from an existing Image object
 * 
 * @param image 
 */
Texture::Texture(Image* image) {
    // Create one texture, and update texture with the ID
    glGenTextures(1, &ID); 
    // Bind the texture to start working on it
    glBindTexture(GL_TEXTURE_2D, ID);
    // Add image data to the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->getWidth(), image->getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image->getData());
    // Generate Mipmaps
    glGenerateMipmap(GL_TEXTURE_2D);
}

/**
 * @brief Binds the texture to make changes or use for texture unit
 * 
 */
void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, ID);
}

/**
 * @brief Uses the texture on a shader
 * 
 * @param shader The shader object to bind the texture to
 * @param name The name of the Sampler2D uniform on the shader
 * @param slot The Texture Unit slot to bind the texture to
 */
void Texture::use(Shader* shader, std::string name, unsigned int slot) {
    // Use the shader to bind the texture to
    shader->use();
    // By default, texture units are deactive, so activate it first
    glActiveTexture(GL_TEXTURE0 + slot);
    // Bind this texture
    bind();
    // Specify the name of the texture on the shader
    shader->setUniform(name.c_str(), (int)slot);
}

/**
 * @brief 
 * 
 * @param filter 
 * @param mipFilter 
 */
void Texture::setFilter(unsigned int magFilter, unsigned int minFilter) {
    // Bind the texture
    bind();
    // Set filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
}

/**
 * @brief 
 * 
 * @param wrap 
 */
void Texture::setWrap(unsigned int wrap) {
    // Bind the texture
    bind();
    // Set wrap
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap);
}
