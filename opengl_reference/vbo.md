# VBO

In OpenGL, a VBO (Vertex Buffer Object) is a buffer object containing vertex information. 
A vertex is a single point that carries attributes such as position, normal, and uv. 
In essence, a VBO is just an array of vertices. 


# Implementation

In OpenGL, buffers are created with an ID. 
This id should be maintained to bind, access, and modify the buffer later on.
Note that to work with a buffer, it must be bound.
This is because in OpenGL all buffer operations are done on the currently bound buffer. 

To start, lets assume we have an array of vertices:
```c++
// Vertex data for a triangle
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};  
``` 

We can make a VBO from this data like so:
```c++
// ID to the buffer
unsigned int VBO;

// Create one buffer, and update VBO with the buffer ID
glGenBuffers(1, &VBO);

// Bind the vbo to start working on it
glBindBuffer(GL_ARRAY_BUFFER, VBO);

// Now, we can add our vertex data to the VBO
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

// Unbind the buffer for safety
glBindBuffer(GL_ARRAY_BUFFER, 0);
```

Notice that all the functions are general buffer functions, not VBO functions. This is because there are many types of buffers in OpenGL. In this case, we use `GL_ARRAY_BUFFER` to indicate that we are working with a VBO. 

Additionally, we specified `GL_STATIC_DRAW`. This is a hint for OpenGL that suggests that we will not be updating this information often. If we plan on updating data for the VBO, we can use `GL_DYNAMIC_DRAW`, which will store the VBO "closer" to the CPU for faster writes. 