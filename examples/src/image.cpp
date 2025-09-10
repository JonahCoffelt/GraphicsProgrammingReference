#include "image.h"

/**
 * @brief Construct a new Image object from image file
 * 
 * @param file Path to the image to load
 */
Image::Image(std::string file) {
    stbi_set_flip_vertically_on_load(true);  
    unsigned char *data = stbi_load(file.c_str(), &width, &height, &nChannels, 0); 
    if (!data) { std::cout << "Failed to load texture" << std::endl; }
}

/**
 * 
 @brief Destroy the Image object and free image data
 * 
 */
Image::~Image() {
    stbi_image_free(data);
}