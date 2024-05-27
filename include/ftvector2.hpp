#pragma once

class ftvector2 {
public:
    float x, y;

    ftvector2(float x = 0.0f, float y = 0.0f);
    ftvector2(const ftvector2& other);

    ftvector2& operator=(const ftvector2& other);

    ~ftvector2();

    ftvector2 normalize() const;

    float dot(const ftvector2& other) const;

    ftvector2 operator+(const ftvector2& other) const;

    ftvector2 operator-(const ftvector2& other) const;

    ftvector2 operator*(float scalar) const;

    ftvector2 operator/(float scalar) const;

    bool operator==(const ftvector2& other) const;

    bool operator!=(const ftvector2& other) const;
};