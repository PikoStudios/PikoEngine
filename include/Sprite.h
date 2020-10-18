#pragma once
#include "Vector.h"

typedef struct
{
    Vec2 vector;
    int width;
    int height;
} SpriteObj;

SpriteObj SpriteObject(Vec2 vectorObj, int width, int height)
{
    SpriteObj obj;
    obj.vector = vectorObj;
    obj.width = width;
    obj.height = height;
    return obj;
}