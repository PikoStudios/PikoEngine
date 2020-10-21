#pragma once
#include <SDL2/SDL.h>

const char *pk_GetError()
{
    return SDL_GetError();
}