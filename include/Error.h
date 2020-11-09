#pragma once
#include <SDL.h>

const char *pk_GetError()
{
    return SDL_GetError();
}