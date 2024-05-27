#include "ftvector4.hpp"
#include <cmath>

ftvector4::ftvector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

ftvector4::ftvector4(const ftvector4& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

ftvector4& ftvector4::operator=(const ftvector4& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
        w = other.w;
    }
    return *this;
}

ftvector4::~ftvector4() {}

ftvector4 ftvector4::operator+(const ftvector4& other) const {
    return ftvector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

ftvector4 ftvector4::operator-(const ftvector4& other) const {
    return ftvector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

ftvector4 ftvector4::operator*(float scalar) const {
    return ftvector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

ftvector4 ftvector4::operator/(float scalar) const {
    if (scalar != 0.0f)
        return ftvector4(x / scalar, y / scalar, z / scalar, w / scalar);
    else
        return ftvector4(0.0f, 0.0f, 0.0f, 0.0f);
}

bool ftvector4::operator==(const ftvector4& other) const {
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool ftvector4::operator!=(const ftvector4& other) const {
    return !(*this == other);
}