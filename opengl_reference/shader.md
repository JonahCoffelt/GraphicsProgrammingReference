# Shader

A shader is a program that runs on the GPU. Shaders are mostly used for rendering, but can also be used for arbitrary computations.
This article will not cover how to write GLSL, it is focused on how to implement existing shaders with OpenGL.

Full implementation of a shader class can be found at [shader.cpp](../examples/src/shader.cpp)

## Compiling a Shader

Shaders are compiled from a C-string of source code. 
Typically, for a shader program, we will have a vertex shader and a fragment shader. 
The vertex shader handles how we manipulate geometry, and the fragment shader handles coloring pixels that fall within geometry passed from the vertex shader. 
For now, lets assume we have these strings defined in our c++ file. 

```c++
const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
```

Before we start, lets define the variables we will use for compilation and error checking:
```c++
unsigned int vertex, fragment;
int success;
char infoLog[512];
```

Now, we can compile the vertex shader. 

```c++
// Create and compile the vertex shader
vertex = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertex, 1, &vertexShaderSource, NULL);
glCompileShader(vertex);
```

This creates a blank shader, sets the source code, then compiles. 

It is good practice to check for successful compilation of the shader at this point.

```c++
// Check for compilation errors
glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
if (!success) {
    glGetShaderInfoLog(vertex, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
}
```

Now that the vertex shader is done, we can compile our fragment shader in the same way.

```c++
// Create and compile the fragment shader
fragment = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragment, 1, &fragmentShaderSource, NULL);
glCompileShader(fragment);

// Check for compilation errors
glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
if (!success) {
    glGetShaderInfoLog(fragment, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
}
```

With the shader code compiled and checked, we will now link the vertex and fragment shaders into a single shader program.

```c++
// Create the shader program
program = glCreateProgram();
glAttachShader(program, vertex);
glAttachShader(program, fragment);
glLinkProgram(program);
```

We need to check that the shader linked correctly.

```c++
// Check for linking errors
glGetProgramiv(program, GL_LINK_STATUS, &success);
if(!success)
{
    glGetProgramInfoLog(program, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
}
```

Finally, release the vertex and fragment shaders to avoid memory leaks:

```c++
glDeleteShader(vertex);
glDeleteShader(fragment);
```


## Releasing a Shader Program

Once you are finished with a shader program, make sure to release the data.

```c++
glDeleteProgram(program);
```


## Loading Shader From File

Oftentimes, it is preferable to load shaders from files rather than put the source code as a string in our c++ file.
This is not an OpenGL topic, so I will simply provide the code and leave it to the reader to get a deeper explination if desired.

```c++
// Example path for vertex shader
const char* path = "shader.vert"

// Set out string and stream
std::string content;
std::ifstream file;
file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

// Attempt to load the file and read to string
try {
    file.open(path);
    std::stringstream vertexStream, fragmentStream;
    vertexStream << file.rdbuf();
    content = vertexStream.str();
    file.close();
}
catch (std::ifstream::failure e) {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
}

// Use content as the shader source
const char* vertexShaderSource = content;
```