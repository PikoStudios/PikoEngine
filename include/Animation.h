// defining the stuff first

#pragma once
#include "Sprite.h"
#include "util.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct
{
    SDL_Texture* p_AnimationArray[100];
    float m_fps;
    int isAnyPlaying;
    int whichFramePlaying;
    char* title;
    int m_width;
    int m_height;
} AnimationHandle;

// struct AnimationHandleArray { AnimationHandle handle [100]; };
AnimationHandle LoadAnimation(char* __title, float __m_fps, char** __arrayOfFilePaths, SDL_Renderer* renderer, int m_width, int m_height)
{
    AnimationHandle handle;
    handle.title = __title;
    handle.m_fps = __m_fps;
    handle.m_height = m_height;
    handle.m_width = m_width;
    for (int i = 0; i <= LengthOfArrayChar(__arrayOfFilePaths); i++)
    {
        handle.p_AnimationArray[i] = LoadSprite(__arrayOfFilePaths[i], renderer);
    }

    return handle;
}

void PlayAnimation(AnimationHandle handle, SDL_Renderer* renderer)
{
    for (int i = 0; i <= LengthOfArraySDL_Texture(handle.p_AnimationArray); i++)
    {
        
    }
}