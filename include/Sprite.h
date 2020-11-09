#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"


typedef struct
{
    Vec2 vector;
    int width;
    int height;
} SpriteObj;

SpriteObj SpriteObject(Vec2 vectorObj, int width, int height)
{
    SpriteObj obj;
    obj.vector = vectorObj;
    obj.width = width;
    obj.height = height;
    return obj;
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

SDL_Texture* LoadSprite(const char* p_filePath, SDL_Renderer* renderer)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    
    if (texture == NULL) 
    {
        fprintf(stderr, "Failed to load %s, Error: %s", p_filePath, SDL_GetError());
        exit(1);
    }
    return texture;

}