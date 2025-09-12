# Graphics Programming Reference
A collection of notes and scripts for various graphics programming techniques and paradigms. This is not intended to be a guide for graphics programming beginners, but it will cover theory and implementation of beginner to advanced techniques.

<p align="center">
    <img src="examples/images/quad.png" alt="mud" width="200"/>
    <img src="examples/images/triangle.png" alt="foil" width="200"/>
    <img src="examples/images/texture.png" alt="mud" width="200"/>
    <img src="examples/images/triangle.png" alt="mud" width="200"/>
</p>

# Contents

This repo contains reference/theory pages, class implementations, and example uses. 
Content has been divided into chapters which progressivly build.
All [reference pages](./opengl_reference/), [class implementations](./examples/src/), and [example scripts](./examples/) may be found in the linked folders.  

## Chapter 1 - The Basics
Gets you started with creating a window in OpenGL

- [GLFW Window Reference](./opengl_reference/window.md)
- [OpenGL Boilerplate](./examples/01_boilerplate.cpp)
- [Window Class](./examples/src/window.cpp)
- [Abstracted Boilerplate Example](./examples/02_abstracted_boilerplate.cpp)

## Chapter 2 - Rendering First Steps
Convers the basics of rendering 2D images to the screen. 

### VBO
- [VBO Reference](./opengl_reference/vbo.md)
- [VBO Class](./examples/src/vbo.cpp)
- [Triangle Example](./examples/03_triangle.cpp)

### EBO
- [EBO Reference](./opengl_reference/ebo.md)
- [EBO Class](./examples/src/ebo.cpp)
- [Quad Example](./examples/04_quad.cpp)

### Shader
- [Shader Reference](./opengl_reference/shader.md)
- [Shader Class](./examples/src/shader.cpp)

### VAO
- [VAO Reference](./opengl_reference/vao.md)
- [VAO Class](./examples/src/vao.cpp)
- [Color Attribute Example](./examples/05_color_attrib.cpp)

### Texture
- [Texture Reference](./opengl_reference/texture.md)
- [Image Class](./examples/src/image.cpp)
- [Texture Class](./examples/src/texture.cpp)
- [Texture Example](./examples/06_texture.cpp)

## Chapter 3 - 3D
Introduces GLM transformations and applies knowledge for 3D graphics

### Transformations
- [Transformation and GLM Reference](./opengl_reference/transformation.md)
- [Matrix Class](./examples/src/mat.cpp)
- [Transformation Example](./examples/07_transformation.cpp)

### Projections


# Usage
This repo contains a number of examples. Use CMake to run these examples from source.

```bash
cd ./examples/build

cmake ..
```

This process will download all of the required dependencies to the build folder. This may take a few minutes. Once it has finished, you can build the executables. 

```bash
cmake --build .

```

This creates a seperate executable for every example. Simply run the desired example:

```bash
./example
```

# Sources
Here is a list of sources used to create this reference. I highly reccomend all of these for deeper understanding:
- [learnopengl](https://learnopengl.com)
- [OpenGL Wiki](https://www.khronos.org/opengl/wiki/)