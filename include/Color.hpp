#pragma once

#include <iostream>
#include <stdint.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include "GLFW/glfw3.h"

class Color
{
private:
    uint32_t color;
    float r, g, b, a;

public:
    Color();
    Color(int r, int g, int b, int a);
    Color(const Color &a);
    ~Color() = default;

private:
    float convertRangeToUnit(int value);
    int convertRangeTo255(float value);

public:
    uint32_t getColor() const;
    void setColor(uint32_t color);

    float getR() const;
    void setR(float r);

    float getG() const;
    void setG(float g);

    float getB() const;
    void setB(float b);

    float getA() const;
    void setA(float a);
};
