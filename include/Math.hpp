#pragma once
#include <vector>
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

class Matrix {
    private:
        std::vector<std::vector<float>> vals;
    
    public:
    
    Matrix() {
        vals = std::vector<std::vector<float>>(4, std::vector<float>(4, 0)); 
    }

    Matrix(std::vector<std::vector<float>> t) {
        vals = t; 
    }
    
    std::vector<float> operator[](int index) const {
        assert(index < 4); 
        return vals[index]; 
    }

    Matrix operator*(const Matrix& other) const {
        std::vector<std::vector<float>> ret(4, std::vector<float>(4, 0));
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 4; k++)
                    ret[i][j] += (this->vals[i][k]) * (other.vals[k][j]);
        return Matrix(ret); 
    }
    
    Vector3 operator*(const Vector3& other) const {
        std::vector<float> vals(4, 0);
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                vals[i] += (this->vals[i][j]) * other[j];
        for (int i = 0; i < 3; i++)
            vals[i] /= vals[3];

        return Vector3(vals[0], vals[1], vals[2]);
    }
};

class Math {
    private:

    Matrix projection_matrix,
           rotateX,
           rotateY,
           rotateZ,
           viewport,
           translation;
    Vector3 camera;
    float tx, ty, tz;

    public:

};


