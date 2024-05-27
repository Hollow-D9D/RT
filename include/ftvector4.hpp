#pragma once

class ftvector4 {
public:
    float x, y, z, w;

    ftvector4(float x = 0.0f, float y = 0.0f, float z = 0.0f, float w = 0.0f);
    ftvector4(const ftvector4& other);

    ftvector4& operator=(const ftvector4& other);

    ~ftvector4();


    ftvector4 operator+(const ftvector4& other) const;

    ftvector4 operator-(const ftvector4& other) const;

    ftvector4 operator*(float scalar) const;

    ftvector4 operator/(float scalar) const;

    bool operator==(const ftvector4& other) const;

    bool operator!=(const ftvector4& other) const;
};