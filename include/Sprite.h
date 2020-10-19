#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
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
