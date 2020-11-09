#include "C:/MinGW/include/PikoEngine/include/Piko.h"

Game OnGameStart()
{
    Game gameObj = InitWindow(1280, 720, pkINIT_VIDEO);
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