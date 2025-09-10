# Texture

A texture is an object that contains one or more images. 
An image is a 1D, 2D, or 3D array of pixels with a particular format.


## Creating a Texture

Full implementation for [texture class](../examples/src/texture.cpp)
Full implementation for [image class](../examples/src/image.cpp)

Generally, we will create textures from file using stb_image, a header only image loading library. 

### Loading and Image
The first step is to include stb_image.

```c++
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Set flip to true for OpenGL coordinates
stbi_set_flip_vertically_on_load(true);  
```

Now we can load an image, keeping track of the width and height for later use in texture generation. 

```c++
int width, height, nrChannels;
unsigned char *data = stbi_load("image.png", &width, &height, &nrChannels, 0); 
```

We should verify that the image was properly loaded before proceeding.

```c++
if (!data) { std::cout << "Failed to load texture" << std::endl; }
```


### Generate a Texture
Now, lets actually make the texture. 
The process is very similar to VBO creation.

```c++
// ID to the texture
unsigned int texture;

// Create one texture, and update texture with the ID
glGenTextures(1, &texture); 

// Bind the texture to start working on it
glBindTexture(GL_TEXTURE_2D, texture);

// Add image data to the texture
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
```

This has created a texture using the image data. 

Note that it is often good practice to release the data loaded by stb_image once you are done using it.

```c++
stbi_image_free(data);
```


## Using a Texture

To use a texture in a shader, it can be bound to a texture unit.
Typically, you will have access to 16 texture units, each of which can store a single texture. 

Assume we have a shader with a `sampler2D` for the texture we want to use

```glsl
uniform sampler2D exampleTexture;
```

We can bind our texture to that sampler using a texture unit

```c++
// Use the shader to bind the texture to
glUseProgram(shader); 
// By default, texture units are deactive, so activate it first
glActiveTexture(GL_TEXTURE0);
// Bind the texture
glBindTexture(GL_TEXTURE_2D, texture);
// Specify the name of the texture on the shader
glUniform1i(glGetUniformLocation(ourShader.ID, "exampleTexture"), 0);
```


## Mipmaps

Mipmaps are layers in a texture with different resolutions. 
They are useful for rendering textures far in the distance (since resolution is not as important), and for texture arrays.

```c++
// Bind the texture
glBindTexture(GL_TEXTURE_2D, texture);

// Generate Mipmaps
glGenerateMipmap(GL_TEXTURE_2D);
```


## Texture Filters

Texture filters tell the GPU how to sample from a texture when rednering. 
OpenGL allows linear or nearest filtering. 
Linear has a smoother look while nearest has a more pixelated look. 

```c++
// Bind the texture
glBindTexture(GL_TEXTURE_2D, texture);

// Set filter
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
```

## Texture Wrap

Texture wrapping tells the GPU how to render a texture when the uv coordinates exceed the [0, 1] range.
OpenGL offers the following options: `GL_REPEAT`, `GL_MIRRORED_REPEAT`, `GL_CLAMP_TO_EDGE`, `GL_CLAMP_TO_BORDER`.

```c++
// Bind the texture
glBindTexture(GL_TEXTURE_2D, texture);

// Set wrap
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
```