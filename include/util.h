#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>


void ErrorMsg(const char* err, ...)
{
    fprintf(stderr, "%s", err);
    exit(1);
}

int LengthOfArrayChar(char** arr)
{
    return (int)(sizeof(arr) / sizeof(arr[0]));
}

int LengthOfArraySDL_Texture(SDL_Texture* arr[])
{
    return (int)(sizeof(arr) / sizeof(arr[0]));
}