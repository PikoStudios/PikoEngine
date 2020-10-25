#pragma once
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>
#include "OS.h"
#define CHAR_CONST_NULL "0"
#define pkBrowserDefault CHAR_CONST_NULL

void ErrorMsg(const char* err, ...)
{
    fprintf(stderr, "%s", err);
    exit(1);
}

int LengthOfArrayChar(char** arr)
{
    return (int)(sizeof(arr) / sizeof(arr[0]));
}

int LengthOfArraySDL_Texture(SDL_Texture* arr[])
{
    return (int)(sizeof(arr) / sizeof(arr[0]));
}

// Opens A website, Example: OpenURL("https://example.com", pkBrowserDefault)
// -------
// Only Works on Windows, MacOS, and Linux/GNU+Linux. BSD and QNX are not yet supported.
int OpenURL(const char link)
{
    

    char *cmd;
    if (pkGetCurrentOS() == "WIN32")
        sprintf(cmd, "start %s", link);
    else if (pkGetCurrentOS() == "LINUX") 
        sprintf(cmd, "xdg-open '%s'", link);
    else if (pkGetCurrentOS() == "DARWIN/MACOS")
        sprintf(cmd, "open '%s'", link);
    
    system(cmd);
}