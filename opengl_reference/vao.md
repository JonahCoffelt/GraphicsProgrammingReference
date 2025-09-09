# VAO

In OpenGL, a VAO (Vertex Array Object) is an object which contains buffer objects and vertex attribute information.
A VAO is used as a central point which nicely packages all nessecary data to render an object. 

# Implementation

Full implementation for vao class can be found [here](../examples/src/vao.cpp)

To start, generate a vao similar to how you would a vbo or ebo.

```c++
unsigned int VAO;
glGenVertexArrays(1, &VAO);
```

Now you can bind VBOs and EBOs to the VAO. 
To do this, first bind the VAO, then bind the VBO/EBO.

```c++
glBindVertexArray(VAO);
glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
```

With all the buffers bound, you can now specify the attributes for the VAO. 
For now, we will assume the VBO you are working with with interleaved, (`[p1, u1, n1, p2, u2, n2, ...]`).
It is possible to simply group all like vertex attributes, but this is not recommended because it has worse locality. 
This is done first by specifying the information for the attribute, then enabling it (all attributes are disabled by defualt).

```c++
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);  
```

Here are each of the `glVertexAttribPointer` parameters

1. The location of the attribute in the shader
2. The number of components in the attribute (3 for vec3, 1 for float, etc.)
3. The data type. Most will be floats or ints
4. Automatic data normalization flag. Generally not necessary.
5. Stride, which is the number of bytes between each occurance of the attribute (This is the size of each vertex in bytes).
6. Attribute offset in the buffer in bytes. Can think of it as the location of the first occurance of the attribute


## Rendering

Once you have your VAO set up, you can start to render some objects.
The way you render a VAO depends on whether or not you use an EBO.

### Without an EBO

```c++
glUseProgram(shaderProgram);
glBindVertexArray(VAO);
glDrawArrays(GL_TRIANGLES, 0, 3);
```

To render with `glDrawArrays`, you specify the drawing method (usually triangles), the vertex offset to start rendering, and the number of verticies to render. 

### With an EBO

```c++
glUseProgram(shaderProgram);
glBindVertexArray(VAO);
glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
```

To render with `glDrawArrays`, you specify the drawing method, the number of verticies to render, the index data type, and the index offset to start rendering. . 