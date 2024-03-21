#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <vector>
#include "Vector3.hpp"
#include <string>

class Object {
    public:
        Object(std::string filename);
        
        std::vector<Vector3> Points;
        std::vector<std::pair<int, int>> Edges;
        int getX();
        int getY();
        void addX(int toAdd);
        void addY(int toAdd);
        void setX(int toSet);
        void setY(int toSet);
};

