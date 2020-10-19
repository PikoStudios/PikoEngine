#pragma once
#include "../Vector.h"
#include "stdio.h"

Vec2 phy_SimpleMove(Vec2 obj)
{
    obj.x += 1.0f;
    return obj;
}

float phy_lerp(float a, float b, float amount)
{
    return (1 - amount) * a + b * amount;
}



void phy_MoveSlide(Vec2 obj, Vec2* dst, float amount, float initSpeed)
{
    for (float amountX = 0.0f; amountX < initSpeed; amountX += amount)
    {
        dst->x = phy_lerp(obj.x, obj.y, amountX);
    }
    
}