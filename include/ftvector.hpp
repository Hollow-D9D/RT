#pragma once

template <typename T>
class Vector2D
{
public:    
    T x;
    T y;

    Vector2D() : x(0), y(0) {}
    Vector2D(T xVal, T yVal) : x(xVal), y(yVal) {}

    Vector2D operator+(const Vector2D& other) const { return Vector2D(x + other.x, y + other.y); }

    Vector2D operator-(const Vector2D& other) const { return Vector2D(x - other.x, y - other.y); }

    Vector2D operator*(double scalar) const { return Vector2D(x * scalar, y * scalar); }

    Vector2D operator/(double scalar) const 
    {
        if (scalar == 0)
        {
            std::cerr << "Error: Division by zero." << std::endl;
            return *this;
        }
        return Vector2D(x / scalar, y / scalar);
    }

    double dot(const Vector2D& other) const { return x * other.x + y * other.y; }

    double crossProduct(const Vector2D& other) const { return x * other.y - y * other.x; }

    double magnitude() const { return std::sqrt(x * x + y * y); }

    Vector2D normalize() const {
        double mag = magnitude();
        if (mag == 0) {
            std::cerr << "Error: Cannot normalize a zero vector." << std::endl;
            return *this;
        }
        return *this / mag;
    }

    void print() const { std::cout << "(" << x << ", " << y << ")"; }
}