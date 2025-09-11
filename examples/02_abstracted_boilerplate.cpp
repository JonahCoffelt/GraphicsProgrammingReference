/**
 * @file 02_abstracted_boilerplate.cpp
 * @author Jonah Coffelt
 * @brief Since many of the examples in this repo use abstractions, I thought it might be helpful to see the abstracted boilerplate. 
 * @version 0.1
 * @date 2025-09-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "src/window.h"

int main() {
    // Create a GLFW window
    Window* window = new Window(800, 800, "Example 2: Boilerplate");

    // Main loop continues as long as the window is open
    while (window->isRunning()) {
        // Fill the screen with a low blue color
        window->clear(0.2, 0.3, 0.3, 1.0);
        // Show the screen
        window->render();
    }

    // Free memory allocations
    delete window;
}