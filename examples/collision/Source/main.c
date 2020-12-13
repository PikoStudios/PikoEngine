#include "PikoEngine/include/Piko.h"
#include <stdio.h>



Game OnGameStart()
{
    Game gameObj = InitWindow("Hello, World", 1270, 720, pkINIT_VIDEO);
    return gameObj;
}

void OnGameUpdate(Game app)
{
    ClearScreen(app.renderer);
    Rect rect1 = Rectangle(10,10,300,300,255,255,255,255);
    FillRectangle(app.renderer, rect1);
}

int main(int argc, char** argv)
{
    EngineEvent event = pkEngineEvent();
    Game obj = StartGame(event);
    UpdateGame(event, obj);
    return 0;
}