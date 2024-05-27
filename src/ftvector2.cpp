#include "ftvector2.hpp"
#include <cmath>

ftvector2::ftvector2(float x, float y) : x(x), y(y) {}

ftvector2::ftvector2(const ftvector2& other) : x(other.x), y(other.y) {}

ftvector2& ftvector2::operator=(const ftvector2& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

ftvector2::~ftvector2() {}

ftvector2 ftvector2::normalize() const {
    float length = std::sqrt(x * x + y * y);
    if (length != 0.0f)
        return ftvector2(x / length, y / length);
    else
        return ftvector2(0.0f, 0.0f);
}

float ftvector2::dot(const ftvector2& other) const {
    return x * other.x + y * other.y;
}

ftvector2 ftvector2::operator+(const ftvector2& other) const {
    return ftvector2(x + other.x, y + other.y);
}

ftvector2 ftvector2::operator-(const ftvector2& other) const {
    return ftvector2(x - other.x, y - other.y);
}

ftvector2 ftvector2::operator*(float scalar) const {
    return ftvector2(x * scalar, y * scalar);
}

ftvector2 ftvector2::operator/(float scalar) const {
    if (scalar != 0.0f)
        return ftvector2(x / scalar, y / scalar);
    else
        return ftvector2(0.0f, 0.0f);
}

bool ftvector2::operator==(const ftvector2& other) const {
    return x == other.x && y == other.y;
}

bool ftvector2::operator!=(const ftvector2& other) const {
    return !(*this == other);
}