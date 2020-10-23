// Piko Audio Module

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/sdl_mixer.h>
#include "util.h"
#define pkINIT_AUDIO 0x00000010u
#define pkAudioDefaultFormat AUDIO_S16LSB
#define pkAudioDefaultFrequency 44100
#define pkAudioStero 2
#define pkAudioDefaultChunkSize 2048
#define pkLoadWAV(file)   Mix_LoadWAV_RW(SDL_RWFromFile(file, "rb"), 1)




int pkOpenAudio(int frequency, Uint16 format, int channels, int chunksize)
{
    if(Mix_OpenAudio(frequency, format, channels, chunksize) > 0) 
    {
        fprintf(stderr, "Error %s", SDL_GetError());
        exit(1);
    }
}

extern DECLSPEC Mix_Music * SDLCALL pkLoadMusic(const char* p_filePath)
{
    return Mix_LoadMUS(p_filePath);
}

void pkCloseAudioModule() { Mix_Quit(); }
