#include "ftvector3.hpp"
#include <cmath>

ftvector3::ftvector3(float x, float y, float z) : x(x), y(y), z(z) {}

ftvector3::ftvector3(const ftvector3& other) : x(other.x), y(other.y), z(other.z) {}

ftvector3& ftvector3::operator=(const ftvector3& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

ftvector3::~ftvector3() {}

ftvector3 ftvector3::normalize() const {
    float length = std::sqrt(x * x + y * y + z * z);
    if (length != 0.0f)
        return ftvector3(x / length, y / length, z / length);
    else
        return ftvector3(0.0f, 0.0f, 0.0f);
}

float ftvector3::dot(const ftvector3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

ftvector3 ftvector3::cross(const ftvector3& other) const {
    return ftvector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

ftvector3 ftvector3::operator+(const ftvector3& other) const {
    return ftvector3(x + other.x, y + other.y, z + other.z);
}

ftvector3 ftvector3::operator-(const ftvector3& other) const {
    return ftvector3(x - other.x, y - other.y, z - other.z);
}

ftvector3 ftvector3::operator*(float scalar) const {
    return ftvector3(x * scalar, y * scalar, z * scalar);
}

ftvector3 ftvector3::operator/(float scalar) const {
    if (scalar != 0.0f)
        return ftvector3(x / scalar, y / scalar, z / scalar);
    else
        return ftvector3(0.0f, 0.0f, 0.0f);
}

bool ftvector3::operator==(const ftvector3& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool ftvector3::operator!=(const ftvector3& other) const {
    return !(*this == other);
}