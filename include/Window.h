#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Vector.h"
#include "util.h"
#include "Sprite.h"


struct WinObject
{
    SDL_Window* win;
    SDL_Renderer* renderer;
};


WinObject InitWindow(const char* p_title, int m_width, int m_height)
{

    if (SDL_Init(SDL_INIT_VIDEO) > 0) ErrorMsg("Failed to run SDL_Init Error %s", SDL_GetError());
    if (!(IMG_Init(IMG_INIT_PNG))) ErrorMsg("Failed to Run IMG_INIT ERROR %s", SDL_GetError());

    WinObject obj;
    obj.win = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN);

    if (obj.win == NULL) ErrorMsg("Failed to Create Window: %s", SDL_GetError());
    obj.renderer = SDL_CreateRenderer(obj.win, -1, SDL_RENDERER_ACCELERATED);
    return obj;

    
}

SDL_Texture* LoadSprite(const char* p_filePath, SDL_Renderer* renderer)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    
    if (texture == NULL) ErrorMsg("Failed to load %s, Error: %s", p_filePath, SDL_GetError());
    return texture;

}

void kn_DestoryWindow(WinObject win)
{
    SDL_DestroyWindow(win.win);
}

void ClearScreen(SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
}

void RenderSprite(SDL_Renderer* renderer, SDL_Texture* p_texture, SpriteObj sprite)
{
    SDL_Rect m_Rect, dst;
    m_Rect.x = sprite.vector.x;
    m_Rect.y = sprite.vector.y;
    m_Rect.w = sprite.width;
    m_Rect.h = sprite.height;

    dst = m_Rect;

    SDL_RenderCopy(renderer, p_texture, &m_Rect, &dst);
}

void UpdateDisplay(SDL_Renderer* renderer)
{
    SDL_RenderPresent(renderer);
}