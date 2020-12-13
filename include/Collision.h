#pragma once
#include <SDL2/SDL.h>
#include "Rectangle.h"

// Checks if two Entities are colliding. If so, returns 0, If not returns 1
int IsColliding(Rect a, Rect b)
{
    return SDL_HasIntersection(&a.rect, &b.rect);
}