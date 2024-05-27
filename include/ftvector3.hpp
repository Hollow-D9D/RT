#pragma once

class ftvector3 {
public:
    float x, y, z;

    ftvector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    ftvector3(const ftvector3& other);

    ftvector3& operator=(const ftvector3& other);

    ~ftvector3();

    ftvector3 normalize() const;

    float dot(const ftvector3& other) const;

    ftvector3 cross(const ftvector3& other) const;

    ftvector3 operator+(const ftvector3& other) const;

    ftvector3 operator-(const ftvector3& other) const;

    ftvector3 operator*(float scalar) const;

    ftvector3 operator/(float scalar) const;

    bool operator==(const ftvector3& other) const;

    bool operator!=(const ftvector3& other) const;
};