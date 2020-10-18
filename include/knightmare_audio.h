// Knightmare Audio Module

#pragma once
#include <SDL2/SDL.h>
#include <SDL2/sdl_mixer.h>
#include "util.h"
#define knINIT_AUDIO 0x00000010u
#define knAudioDefaultFormat AUDIO_S16LSB
#define knAudioDefaultFrequency 44100
#define knAudioStero 2
#define knAudioDefaultChunkSize 2048
#define knLoadWAV(file)   Mix_LoadWAV_RW(SDL_RWFromFile(file, "rb"), 1)




int knOpenAudio(int frequency, Uint16 format, int channels, int chunksize)
{
    if(Mix_OpenAudio(frequency, format, channels, chunksize) > 0) ErrorMsg("Error %s", SDL_GetError());
}

extern DECLSPEC Mix_Music * SDLCALL knLoadMusic(const char* p_filePath)
{
    return Mix_LoadMUS(p_filePath);
}

void knCloseAudioModule() { Mix_Quit(); }

