#pragma once
#include "Sprite.h"

typedef struct
{
    SpriteObj** obj;
    const char* name;
    int hitboxSize;
} SpriteGroup;

int LengthOfArrayObj(SpriteObj** arr)
{
    return (int)(sizeof(arr) / sizeof(arr[0]));
}

SpriteGroup New_SpriteGroup(SpriteObj** objSprite, const char* name)
{
    SpriteGroup group;
    group.name = name;
    if (LengthOfArrayObj(objSprite) > 100)
    {
        fprintf(stderr, "Piko Error: SpriteGroup of Sprites too big");
        exit(1);
    }
    group.obj = objSprite;
}
