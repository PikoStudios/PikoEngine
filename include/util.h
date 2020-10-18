#pragma once
#include <stdio.h>
#include <stdlib.h>


void ErrorMsg(const char* err, ...)
{
    fprintf(stderr, "%s", err);
    exit(1);
}
