#include "../include/Color.hpp"

Color::Color() : color(0), r(0), g(0), b(0), a(0) {}

Color::Color(int r, int g, int b, int a)
{
    this->r = convertRangeToUnit(r);
    this->g = convertRangeToUnit(g);
    this->b = convertRangeToUnit(b);
    this->a = convertRangeToUnit(a);
    this->color = (a << 24) | (b << 16) | (g << 8) | r;
}

Color::Color(const Color &a)
{
    this->color = a.color;
    this->r = a.r;
    this->g = a.g;
    this->b = a.b;
    this->a = a.a;
}

float Color::convertRangeToUnit(int value)
{
    if (value < 0) value = 0;
    if (value > 255) value = 255;
    return static_cast<float>(value) / 255.0f;
}

int Color::convertRangeTo255(float value)
{
    if (value < 0.0f) value = 0.0f;
    if (value > 1.0f) value = 1.0f;
    return static_cast<int>(value * 255.0f);
}

uint32_t Color::getColor() const
{
    return this->color;
}

void Color::setColor(uint32_t color)
{
    this->color = color;
    this->r = convertRangeToUnit((color >> 0) & 0xFF);
    this->g = convertRangeToUnit((color >> 8) & 0xFF);
    this->b = convertRangeToUnit((color >> 16) & 0xFF);
    this->a = convertRangeToUnit((color >> 24) & 0xFF);
}

float Color::getR() const
{
    return this->r;
}

void Color::setR(float r)
{
    this->r = r;
    this->color = (this->color & 0xFFFFFF00) | convertRangeTo255(this->r);
}

float Color::getG() const
{
    return this->g;
}

void Color::setG(float g)
{
    this->g = g;
    this->color = (this->color & 0xFFFF00FF) | (convertRangeTo255(this->g) << 8);
}

float Color::getB() const
{
    return this->b;
}

void Color::setB(float b)
{
    this->b = b;
    this->color = (this->color & 0xFF00FFFF) | (convertRangeTo255(this->b) << 16);
}

float Color::getA() const
{
    return this->a;
}

void Color::setA(float a)
{
    this->a = a;
    this->color = (this->color & 0x00FFFFFF) | (convertRangeTo255(this->a) << 24);
}


static void PixelPut(int32_t x, int32_t y, const Color& color)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glPointSize(1.0); // Set the point size to 1 pixel

    glBegin(GL_POINTS); // Begin drawing points
    glColor4f(color.getR(), color.getG(), color.getB(), color.getA()); // Set color using the Color class
    glVertex2f(static_cast<float>(x), static_cast<float>(y)); // Specify the vertex (position) of the point
    glEnd(); // End drawing points

    glFlush(); // Flush OpenGL buffer
}

// Display callback for OpenGL
void display()
{
    // Example coordinates for the pixel
    int32_t x = 100;
    int32_t y = 100;

    // Create a red color using the Color class
    Color redColor(255, 0, 0, 255);

    // Call the PixelPut function
    PixelPut(x, y, redColor);
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(500, 500); // Set the window size
    glutInitWindowPosition(100, 100); // Set the window position
    glutCreateWindow("OpenGL PixelPut Example"); // Create the window with a title

    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the background color to white
    gluOrtho2D(0.0, 500.0, 0.0, 500.0); // Set the coordinate system for the window

    glutDisplayFunc(display); // Set the display callback function
    glutMainLoop(); // Enter the GLUT event processing loop

    return 0;
}