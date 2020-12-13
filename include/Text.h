#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>

TTF_Font *  LoadTTF(const char * fileName, int size)
{
    return TTF_OpenFont(fileName, size);
}

void RenderText(const char * text, TTF_Font * font, SDL_Color rgb, int x, int y, int width, int height, SDL_Renderer * renderer)
{

    SDL_Surface * surfaceMsg = TTF_RenderText_Solid(font, text, rgb);

    SDL_Texture * msg = SDL_CreateTextureFromSurface(renderer, surfaceMsg);

    SDL_Rect message_rect;
    message_rect.x = x;
    message_rect.y = y;
    message_rect.h = height;
    message_rect.w = width;

    SDL_RenderCopy(renderer, msg, NULL,&message_rect);
    
    // Free Surface and Texture
    SDL_FreeSurface(surfaceMsg);
    SDL_DestroyTexture(msg);
}