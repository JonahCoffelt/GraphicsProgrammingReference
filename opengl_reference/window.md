# OpenGL Window
The first step to starting an OpenGL project is creating a window. There are many ways to do this; I use GLFW.


## Implementation
For the full code, see the [boilerplate](../examples/01_boilerplate.cpp) example

To start, you need to set initalize GLFW and create a window for OpenGL. 

```c++
// Initialize GLFW for window
glfwInit();

// Set verion to GL 3.3 core
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// Create a window based on the hints
GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Window", NULL, NULL);
```

The window is made with inital size 800x800, and title "OpenGL Window". 
Once the window has been created, it is good practice to check that intialization went correctly. 

```c++
// Check the GLFW window
if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return 0;
}

// Once the window has been created, set the OpenGL context
glfwMakeContextCurrent(window);

// Check GLAD initalization
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return 0;
}
```

Finally, set the viewport:

```c++
int fbWidth, fbHeight;
glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
glViewport(0, 0, fbWidth, fbHeight);
```

## Resizing

To enable window resizing, you must first create a seperate function for resize callbacks

```c++
void framebuffer_resize_callback(GLFWwindow* window, int width, int height) {
    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);
}

```

Then set the callback function for the window like so:

```c++
glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
```

## Clearing

To clear, first set the clear color, then call `glClear`

```c++
glClearColor(0.2, 0.3, 0.3, 1.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
```


## Main Loop

With the window now fully set up, we can now enter the main loop.
The main loop will handle inputs, do all rendering, and swap the buffers.

```c++
while(!glfwWindowShouldClose(window)) {
    // Handle Input
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    // Rendering/Updating
    glClearColor(0.2, 0.3, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // GLFW update and swap
    glfwSwapBuffers(window);
    glfwPollEvents();    
}
```

## Common Additional Window Features

### Unlimited FPS
GLFW will limit the framerate by defult. If you want to have unlimited FPS, simply set the swap interval to 0:

```c++
glfwSwapInterval(0);
```

### OpenGL 
OpenGL has some build in functionality for common default behaviors you might want to enable.
Here are some that I commonly use:

```c++
// Draws closer objects in front of futher objects
glEnable(GL_DEPTH_TEST);  
// Does not draw faces that are not facing the camera
glEnable(GL_CULL_FACE);
// Antialiasing 
glEnable(GL_MULTISAMPLE);
```


## Wayland

If you plan on using Linux, it is best to account for windowing bugs caused by Wayland.
Wayland's default behavior will omit the window border, so to ensure we render using X11, put the following hint before `glfwInit`

```c++
const char* sessionType = getenv("XDG_SESSION_TYPE");    
if (sessionType && std::string(sessionType) == "wayland") {
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
}
```