#pragma once
#include <SDL2/SDL.h>

const char *kn_GetError()
{
    return SDL_GetError();
}