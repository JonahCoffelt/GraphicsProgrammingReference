# EBO

In OpenGL, an EBO (Element Buffer Object) is a buffer object containing index information. 
An index identifies a single vertex within an array. In essence, a EBO is just an array of indices. 
Using an EBO allows us to avoid duplicating data in a VBO when a vertex is used more than once.


# Implementation

```c++
// Assume an array of indices
unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

// ID to the buffer
unsigned int EBO;

// Create one buffer, and update VBO with the buffer ID
glGenBuffers(1, &EBO);

// Bind the vbo to start working on it
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

// Now, we can add our vertex data to the VBO
glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

// Unbind the buffer for safety
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
```

Explination may be found in the [VBO](vbo.md) article.