# Input using GLFW

Input handling is not the primary focus of this reference guide. 
However, input handling is frustrating enough that I felt the inclusion of this section would be appreciated.

This section will cover mouse and keyboard inputs. 
Other forms of input are certainly possible, but mouse and keyboard are more commonly used.

## Keyboard

GLFW provides us with the ability to check the state (Pressed or Unpressed) of any given key. 
Checking the state of a key requires a window and a keycode:

```c++
GLFWwindow window;
int keyCode = GLFW_KEY_A;

glfwGetKey(window, keyCode);
```

This function will return `GLFW_PRESS` if the key is down and `GLFW_RELEASE` is the key is up. 

Note that there is a `GLFW_REPEAT` which can track temporally held keys, but this requires a callback (does not work with the above function) and is OS dependent. 
If we want to track held keys, we would be better off creating this behavior ourselves. 


## Mouse

There are two aspects of mouse input: buttons, and position.


## Mouse Buttons

Button polling works very similarly to key polling

```c++
glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
```

Like `glfwGetKey`, this function may either return `GLFW_PRESS` or `GLFW_RELEASE`. 


## Mouse Position

As for position, we need to define two variables `x` and `y`. 
These will be updated by reference for mouse screen position.

```c++
glfwGetCursorPos(window, &x, &y);
```

Note that the position returned will be in pixels (not on `[-1, 1]` like OpenGL coordinates), with `(0, 0)` being at the top left. 
Addtionally, positive `x` is to the right and positive `y` is down. 


## Relative Position

Oftentimes it is useful to get a relative mouse position, which is the amount the mouse position changed from the previous frame to the current frame. 
To get this value, we will need to keep track of the previous position using `previousX` and `previousY`. 
With these, calculating `relativeX` and `relativeY` is trivial. 

```c++
int relativeX = x - previousX;
int relativeY = y - previousY;
```