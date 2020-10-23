#include "piko-game-engine-location"
#include <stdio.h>

Game OnGameStart()
{
    Game gameObj = InitWindow("Hello, World", 420, 280, pkINIT_VIDEO);
    return gameObj;
}

void OnGameUpdate(Game app)
{
    ClearScreen(app.renderer);
}

int main(int argc, char** argv)
{
    EngineEvent event = pkEngineEvent();
    Game obj = StartGame(event);
    UpdateGame(event, obj);

    return 0;
}