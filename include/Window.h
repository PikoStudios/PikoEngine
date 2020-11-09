#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"

#include "Sprite.h"
#include <switch.h>

// Kill Piko Engine Early
#define pkQuit() SDL_Quit()

typedef struct
{
    SDL_Window* win;
    SDL_Renderer* renderer;
} Game;


Game InitWindow(int m_width, int m_height, Uint32 flags)
{

    consoleInit(NULL);

    if (SDL_Init(flags) > 0) 
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
    obj.win = SDL_CreateWindow(".", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN);

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
