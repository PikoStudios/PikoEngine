#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector.h"
#include "util.h"
#include "Sprite.h"

#define pkINIT_VIDEO 0x00000020u
// Kill Piko Engine and SDL
#define pkQuit() SDL_Quit()

typedef struct
{
    SDL_Window* win;
    SDL_Renderer* renderer;
} Game;


Game InitWindow(const char* p_title, int m_width, int m_height, Uint32 flags)
{

    if (SDL_Init(SDL_INIT_VIDEO) > 0) 
    {
        fprintf(stderr, "Failed to run SDL_Init Error %s", SDL_GetError());
        exit(1);
    }
    if (!(IMG_Init(IMG_INIT_PNG))) 
    {
        fprintf(stderr, "Failed to Run IMG_INIT ERROR %s", SDL_GetError());
        exit(1);
    }

    Game obj;
    obj.win = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN);

    if (obj.win == NULL) printf("Failed to Create Window: %s", SDL_GetError());
    obj.renderer = SDL_CreateRenderer(obj.win, -1, SDL_RENDERER_ACCELERATED);
    return obj;

    
}



void pkDestroyWindow(Game win)
{
    SDL_DestroyWindow(win.win);
}

void ClearScreen(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
}

void UpdateDisplay(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
}
