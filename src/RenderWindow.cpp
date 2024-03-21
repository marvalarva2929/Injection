#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <iostream>
#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h, SDL_Renderer * p_renderer, SDL_Window * p_window) 
    :window(p_window), renderer(p_renderer), WINDOW_WIDTH(p_w), WINDOW_HEIGHT(p_h) {
    if (window == NULL)
        std::cout << "Window failed to INIT. Error: " << SDL_GetError() << '\n';
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

void RenderWindow::cleanup() {
    SDL_DestroyWindow(window);
}

void RenderWindow::clear() {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
}
