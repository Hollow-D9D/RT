#include "Color.hpp"

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

