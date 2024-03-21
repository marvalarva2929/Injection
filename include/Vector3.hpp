#pragma once
#include <assert.h>

class Vector3 {
    public:
    // Default Constructor
    Vector3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
    // Variable Set Constructor
    Vector3(float x_, float y_, float z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
    // Bool Equals Operator Overload
    bool operator==(const Vector3& other) const
    {
        return (this->x == other.x && this->y == other.y && this->z == other.z);
    }
    // Bool Not Equals Operator Overload
    bool operator!=(const Vector3& other) const
    {
        return !(this->x == other.x && this->y == other.y && this->z == other.z);
    }
    // Addition Operator Overload
    Vector3 operator+(const Vector3& right) const
    {
        return Vector3(this->x + right.x, this->y + right.y, this->z + right.z);
    }
    // Subtraction Operator Overload
    Vector3 operator-(const Vector3& right) const
    {
        return Vector3(this->x - right.x, this->y - right.y, this->z - right.z);
    }
    // Float Multiplication Operator Overload
    Vector3 operator*(const float& other) const
    {
        return Vector3(this->x * other, this->y * other, this->z * other);
    }
    // Float Division Operator Overload
    Vector3 operator/(const float& other) const
    {
        return Vector3(this->x / other, this->y / other, this->z / other);
    }
    float operator[](int index) const 
    {
        assert(index < 4);
        return (index == 0 ? x : index == 1 ? y : index == 2 ? z : 1); 
    }
    // Positional Variables
    float x;
    float y;
    float z;
};

