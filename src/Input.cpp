#include "Input.hpp"

Input::Input(/* args */)
{
}

Input::~Input()
{
}

Input& Input::getInstance()
{
    static Input input;
    return input;
}

 // Method to handle keyboard events
void Input::ESC(unsigned char key, int x, int y)
{
    glutDestroyWindow(glutGetWindow()); // Destroy the current window
    exit(0); // Terminate the application
}

// Static method to set the keyboard callback
void Input::keyboardCallback(unsigned char key, int x, int y)
{
    if (key == 27)
    {
        getInstance().ESC(key, x, y);
    }
}