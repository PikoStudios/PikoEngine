#pragma once
#include <SDL2/SDL.h>
#include "Vector.h"
#include <stdio.h>

typedef struct 
{

    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 alpha;
    SDL_Rect rect;

} Rect;

Rect Rectangle(const int x, int y, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 alpha)
{
    Rect rectangleObj;
    rectangleObj.r = r;
    rectangleObj.g = g;
    rectangleObj.b = b;
    rectangleObj.alpha = alpha;
    rectangleObj.rect.x = x;
    rectangleObj.rect.y = y;
    rectangleObj.rect.h = height;
    rectangleObj.rect.w = width;
    

    return rectangleObj;

}

void DrawRectangleOutline(SDL_Renderer * renderer, const Rect rectangle)
{
    SDL_SetRenderDrawColor(renderer, rectangle.r, rectangle.g, rectangle.b, rectangle.alpha);
    SDL_RenderDrawRect(renderer, &rectangle.rect);

    
}

void FillRectangle(SDL_Renderer * renderer, const Rect rectangle)
{
    SDL_SetRenderDrawColor(renderer, rectangle.r, rectangle.g, rectangle.b, rectangle.alpha);
    SDL_RenderFillRect(renderer, &rectangle.rect);
}