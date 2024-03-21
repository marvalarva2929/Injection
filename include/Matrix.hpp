#include <vector>
#include "Vector3.hpp"
#include "assert.h"

class Matrix {
    private:
        std::vector<std::vector<float>> vals;
    
    public:
    
    Matrix();
    Matrix(std::vector<std::vector<float>> t);

    std::vector<float>* operator[](int index) {
        return &(vals[index]); 
    }

    friend Matrix operator*(Matrix& here, Matrix& other);
    friend Vector3 operator*(Matrix& here, Vector3& other);
};

