# Graphics Programming Reference
A collection of notes for various graphics programming techniques and paradigms. This is not intended to be a guide for graphics programming or OpenGL beginners, but it will cover theory and implementation of beginner to advanced techniques. Much of the information from these notes comes directly from learnopengl.com


## Contents

### OpenGL Reference
References on various topics regarding OpenGL theory and implementation. 
- [GLFW Window](./opengl_reference/window.md)
- [VBO](./opengl_reference/vbo.md)
- [EBO](./opengl_reference/ebo.md)

### Rendering Methods
High-level overviews of different methods/paradigms for therendering pipeline.
- [Individual Draw](./rendering_methods/individual_draw_rendering.md)
- [Batch](./rendering_methods/batch_rendering.md)
- [Instance](./rendering_methods/instance_rendering.md)

### Examples
Small scripts that show how to implement a specific technique.
- [OpenGL Boilerplate](./examples/01_boilerplate.cpp)

### Class Implementations
Collection of fully implemented classes to use for an abstracted OpenGL workflow. 
These are used in many of the examples. 
- [VBO Class](./examples/src/vbo.cpp)

## Usage
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

## Sources
Here is a list of sources used to create this reference. I highly reccomend all of these for deeper understanding:
- [learnopengl](learnopengl.com)