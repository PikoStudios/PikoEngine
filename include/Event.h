#pragma once
#include <SDL2/SDL.h>

typedef struct
{
    SDL_Event ___event;
} EngineEvent;


extern DECLSPEC int SDLCALL EnginePollEvent(EngineEvent event)
{
    return SDL_PollEvent(&event.___event);
}

EngineEvent pkEngineEvent()
{
    SDL_Event event;
    EngineEvent dst;
    dst.___event = event;
    return dst;
}