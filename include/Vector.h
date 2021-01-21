#pragma once

typedef struct
{
    float x;
    float y;
} Vec2;

typedef struct
{
    float x;
    float y;
    float z;
} Vec3;


Vec2 Vector2(float x, float y)
{
    Vec2 vecObj;
    vecObj.x = x;
    vecObj.y = y;
    return vecObj;
}
Vec3 Vector3(float x, float y, float z)
{
    Vec3 vec;
    vec.x = x;
    vec.y = y;
    vec.z = z;
    return vec;
}