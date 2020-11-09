#pragma once
#include <SDL.h>
#include <stdbool.h>

typedef struct
{
    SDL_Event ___event;
    bool running;
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