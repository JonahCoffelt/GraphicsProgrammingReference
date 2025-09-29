# Transformations

Transformations allow us to manuplate vertex data very efficiently.
Typically, we use matrices to represent and compute a transformation.
We can use a matrix to represent any combination of translation, rotation, and scale. 
This page will not explain linear algebra, that knowledge is expected.

# GLM

GLM is a library that allows for efficient matrix creation and manipluation.
It comes built in with a number of helpful functions we need for 2D and 3D graphics.


## Matrix Basics

Typically, in computer graphics, we work with 4x4 matrices for transformations, thought it is possible to use matrices of different dimensions 
We will start by making a 4x4 identity matris.

```c++
glm::mat4 transform(1.0f);
```

The mat4 constructor is nicely overloaded to create the identity when we pass in `1.0f`. 
We will apply further transformations to this matrix.


### Translation

Given a matrix `transform`, we can translate it by some vector, where each compent of the vector, $x$, $y$, $z$, represents the amount to shift the matrix along that axis. 

```c++
glm::vec3 translation {1.0, 2.0, 3.0};
transform = glm::glm::translate(transform, translation);
```


### Rotation

Given a matrix `transform`, we can rotate it by some vector and a magnitude, the vector represents the axis about which to rotate, and the magnitude is the amount to rotate in radians.

```c++
float magnitude = 3.14;
glm::vec3 axis {1.0, 2.0, 3.0};
transform = glm::rotate(transform, magnitude, axis);
```


### Scale

Given a matrix `transform`, we can scale it by some vector, where each compent of the vector, $x$, $y$, $z$, represents the amount to scale the matrix along that axis. 

```c++
glm::vec3 scale {1.0, 2.0, 3.0};
transform = glm::glm::scale(transform, scale);
```


### Combining Transformations Order

All of the above mentinoed matrix transformations can be combined into a single matrix by applying the transformations in a specific order.
To achive this, apply translation, then rotation, then scale. 

```c++
transform = glm::glm::translate(transform, translation);
transform = glm::rotate(transform, magnitude, axis);
transform = glm::glm::scale(transform, scale);
```


## Projection Matrix

A projection matrix maps a vector onto a space. 
We can use these for creating 3D perspectives in real time.
GLM has a built in function for making different types of projection matrices.


### Perspective
```c++
float FOV    = 45.0f;  // Degrees
float aspect = (float)width / (float)height;
float near   = 0.1f;
float far    = 100.0f;

glm::mat4 proj = glm::perspective(glm::radians(FOV), aspect, near, far);
```

### Orthographic
```c++
float left   = 0.0f;
float right  = 800.0f;
float bottom = 0.0f;
float top    = 800.0f;
float near   = 0.1f;
float far    = 100.0f;

matrix = glm::ortho(left, right, bottom, top, near, far);
```


## View Matrix

A view matrix transforms world position of objects according to the view of the camera.
This allows the camera to move around and rotate.

```c++
glm::vec3 position {0.0, 0.0, 0.0};
glm::vec3 target {1.0, 0.0, 0.0};
glm::vec3 up {0.0, 1.0, 0.0};

glm::mat4 view = glm::lookAt(position, target, up);
```