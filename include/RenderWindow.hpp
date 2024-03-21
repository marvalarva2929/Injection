#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

class RenderWindow {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

    public:
        RenderWindow(const char* p_title, int p_v, int p_h, SDL_Renderer * p_renderer, SDL_Window * p_window);
        int WINDOW_WIDTH, WINDOW_HEIGHT;        
        void clear();
        void display();
        void cleanup();
};
   
