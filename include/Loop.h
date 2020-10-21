#pragma once
#include "Event.h"
void OnGameStart();
void OnGameUpdate();

void StartGame(EngineEvent event)
{
    event.running = true;
    OnGameStart();
}

void UpdateGame(EngineEvent event)
{
    while(event.running) OnGameUpdate();
}

bool OnGameUpdate(EngineEvent event)
{
    if (EnginePollEvent(event)) return true;
    return false;
}

