#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "GLFW/glfw3.h"
#include "ftwindow.hpp"

static void PixelPut(int32_t x, int32_t y)
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glPointSize(1.0); // Set the point size to 1 pixel

    glBegin(GL_POINTS); // Begin drawing points
    glColor3f(1.0, 0.0, 1.0); // Set color to red
    glVertex2f(x, y); // Specify the vertex (position) of the point
    glEnd(); // End drawing points

    glFlush(); // Flush OpenGL buffer
}

ftwindow& ftwindow::getInstance()
{
    static ftwindow instance;
    return instance;
}


bool ftwindow::init(const char* windowName, int argc, char* argv[], uint32_t width, uint32_t height)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutCreateWindow("Pixel Drawing Example"); // Create a window with the given title
   	glutDisplayFunc(ftwindow::render);
    _width = width;
    _height = height;
    glutKeyboardFunc(Input::keyboardCallback);
    glutMainLoop();
    return 0;
}


void ftwindow::render()
{
    uint32_t width = ftwindow::getInstance()._width;
    uint32_t height = ftwindow::getInstance()._height;
    std::cout << height << '\n' << width << std::endl;

    PixelPut(width / 4, height / 4);
    // for(int32_t i = 0 - height * 0.5; i < height * 1.5; i++)
    // {
    //     for(int32_t j = 0 - height * 0.5; j < width * 1.5; j++)
    //     {
    //     	PixelPut(i, j);
    //     }
    // }
}

