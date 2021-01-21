#pragma once
#include "Event.h"
#include "Window.h"
Game OnGameStart();
void OnGameUpdate(Game app);

Game StartGame(EngineEvent event)
{
    event.running = true;
    return OnGameStart();
}

void UpdateGame(EngineEvent event, Game appObj)
{
    while(event.running) 
    {

        SDL_GL_SwapWindow(appObj.window);
        //SDL_WaitEvent(&event.___event);
        while (SDL_PollEvent(&event.___event))
        {
            if (event.___event.type == SDL_QUIT) 
                event.running = false;
        }
        OnGameUpdate(appObj);
        
    }
    SDL_DestroyWindow(appObj.window);
    SDL_GL_DeleteContext(appObj.context);
    SDL_Quit();
}