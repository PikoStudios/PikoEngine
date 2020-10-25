#pragma once
// Collision System for Piko
#include "Vector.h"
#include "ObjectGroups.h"
#include <stdbool.h>

int pkAmountOfCollisonLayer = 0;

typedef struct
{
    int layer;
    SpriteGroup group;
    const char* name;
} CollisionLayer;

CollisionLayer New_CollisionLayer(SpriteGroup group, const char* m_name)
{
    pkAmountOfCollisonLayer++;
    CollisionLayer layerObj;
    layerObj.group = group;
    layerObj.name = m_name;
    layerObj.layer = pkAmountOfCollisonLayer;
    return layerObj;
}

bool IsColliding(CollisionLayer obj)
{
    for (int x = 0; x < LengthOfArrayObj(obj.group.obj); x++)
    {
        if (obj.group.obj[x]->vector.x == obj.group.obj[x+1]->vector.x) return true;
        else return false;
    }
}

SpriteGroup WhoColliding(SpriteObj sprite, CollisionLayer)
{

}