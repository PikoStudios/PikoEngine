#pragma once

typedef struct
{
    float x;
    float y;
} Vec2;

Vec2 Vector2(float x, float y)
{
    Vec2 vecObj;
    vecObj.x = x;
    vecObj.y = y;
    return vecObj;
}