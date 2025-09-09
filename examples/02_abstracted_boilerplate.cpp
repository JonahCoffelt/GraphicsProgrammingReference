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
    Window* window = new Window(800, 800, "Example 2");

    while (window->isRunning()) {
        window->clear(0.2, 0.3, 0.3, 1.0);
        window->render();
    }

    delete window;
}