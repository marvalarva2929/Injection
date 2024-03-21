#pragma once
#include "Vector3.hpp"
#include "Matrix.hpp"
#include "Object.hpp"

class Injection {
    private:
    Matrix projection_matrix,
           rotate,
           viewport,
           translation;
    Vector3 camera;
    std::vector<Object> objects;
    float tx, ty, tz;
    float x, y, z;

    public:
    
    Injection(int p_v, int p_h);
    int WINDOW_WIDTH, WINDOW_HEIGHT;        
    void render(SDL_Renderer * renderer);
    void moveCamera(Vector3 dl);
    void rotCamera(float thetaX, float thetaY, float thetaZ);
    void addObject(Object& object);
};

