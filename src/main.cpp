#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#define nl '\n'

#include "RenderWindow.hpp"
#include "Vector3.hpp"
#include "Injection.hpp"

int main(int argc, char* args[]) {
     
    if (SDL_Init(SDL_INIT_VIDEO)) 
        std::cout << "SDL_INIT HAS FAILED. SDL_ERROR: " << SDL_GetError() << nl; 
    
    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << nl;
   
    SDL_Renderer* renderer;
    SDL_Window* window;
    int WINDOW_HEIGHT = 720, WINDOW_WIDTH = 1280;
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    
    RenderWindow canvas("tester", 1280, 720, renderer, window);    
    Injection inject(WINDOW_WIDTH, WINDOW_HEIGHT);

    bool isRunning = true;
    SDL_Event e;
    
    float lastRenderTime = SDL_GetTicks();
    
    Object test("trumpet.obj");
    inject.addObject(test);
    
    while (isRunning) {
        const Uint8* keyboardStates = SDL_GetKeyboardState(NULL);  
        
        Vector3 dl(0, 0, 0); 
        float tx = 0, ty = 0, tz = 0;
        if (keyboardStates[SDL_SCANCODE_LSHIFT])
            dl.y -= 0.05;
        if (keyboardStates[SDL_SCANCODE_S])
            dl.z -= 0.05;
        if (keyboardStates[SDL_SCANCODE_W])
            dl.z -= -0.05;
        if (keyboardStates[SDL_SCANCODE_A]) 
            dl.x -= -0.05;
        if (keyboardStates[SDL_SCANCODE_D]) 
            dl.x -= 0.05;
        if (keyboardStates[SDL_SCANCODE_SPACE]) 
            dl.y -= -0.05;
        if (keyboardStates[SDL_SCANCODE_I])
            tx += 0.015;
        if (keyboardStates[SDL_SCANCODE_K])
            tx -= 0.015;
        if (keyboardStates[SDL_SCANCODE_J])
            ty -= 0.015;
        if (keyboardStates[SDL_SCANCODE_L])
            ty += 0.015;
        if (keyboardStates[SDL_SCANCODE_U])
            tz += 0.015;
        inject.moveCamera(dl);
        inject.rotCamera(tx, ty, tz);

        while (SDL_PollEvent(&e))
            switch(e.type) {
                case SDL_QUIT:
                      isRunning = false;
                      break;
            }
        
        inject.render(renderer);

        float curTime = SDL_GetTicks();
        float delayTime = std::max((float)0.0f, (float((1000.0f*(1.0f/60.0)) - (curTime - lastRenderTime)))); 
        if (delayTime)
            SDL_Delay(delayTime);

        lastRenderTime = curTime; 
        
        canvas.display(); 
        canvas.clear();
    }
}

