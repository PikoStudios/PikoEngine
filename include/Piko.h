#pragma once
#include "Sprite.h"
#include "Vector.h"
#include "Window.h"
#include "Error.h"
#include "Event.h"
#include "Loop.h"
#include "Input.h"

#define pkINIT_VIDEO 0x00000020u
// Right now no Piko Module Exists for Timer
#define pkINIT_TIMER 0x00000001u



// TODO: - Build UI Function
// TODO: - Take all the code out of the header files and into C files.
// TODO: - compile into dll.
// TODO: - Fix the input wrapper