#include "Matrix.hpp"

    
Matrix::Matrix() {
    vals = std::vector<std::vector<float>>(4, std::vector<float>(4, 0)); 
}

Matrix::Matrix(std::vector<std::vector<float>> t) {
    vals = t; 
}
    
Matrix operator*(Matrix& here, Matrix& other) {
    std::vector<std::vector<float>> ret(4, std::vector<float>(4, 0));
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                ret[i][j] += ((*here[i])[k]) * ((*other[k])[j]);
    return Matrix(ret); 
}
    
Vector3 operator*(Matrix& that, Vector3& other){
    std::vector<float> vals(4, 0);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            vals[i] += ((*that[i])[j]) * other[j];
    for (int i = 0; i < 3; i++)
        vals[i] /= vals[3];

    return Vector3(vals[0], vals[1], vals[2]);
}
