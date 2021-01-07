#pragma once
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include "Vector.h"
#include "util.h"





// Kill Piko Engine Early
#define pkQuit() SDL_Quit()

typedef struct
{
    SDL_Window* window;
    SDL_GLContext context;
} Game;


Game InitPiko(const char* p_title, int m_width, int m_height)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0) 
    {
        fprintf(stderr, "Failed to run SDL_Init Error %s", SDL_GetError());
        exit(1);
    }

    SDL_GL_LoadLibrary(NULL);

    // Request an OpenGL 4.5 context (should be core)
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    // Also request a depth buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);



    // Create Flags
    Game obj;
    Uint32 flags;
#ifdef PIKO_FULLSCREEN_ENABLED    
    flags = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL;
#else 
    flags = SDL_WINDOW_OPENGL;
#endif

    

    // Make Window
    obj.window = SDL_CreateWindow(
            p_title,
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            m_width, m_height,
            flags
            );

    // Get OpenGL Context
    obj.context = SDL_GL_CreateContext(obj.window);


    // Error Handling

    if (obj.context == NULL) printf("Failed to Create OpenGL Context: %s", SDL_GetError());
    if (obj.window == NULL) printf("Failed to Create Window: %s", SDL_GetError());

    printf("OpenGL loaded\n");
    gladLoadGLLoader(SDL_GL_GetProcAddress);
    printf("Vendor:   %s\n", glGetString(GL_VENDOR));
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("Version:  %s\n", glGetString(GL_VERSION));

    // Set V-Sync
#ifdef PIKO_VSYNC_ENABLED
    // Using V-Sync
    SDL_GL_SetSwapInterval(1);
#else
    // Not Using V-Sync
    SDL_GL_SetSwapInterval(0);
#endif

    // Disable depth test and face culling.
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);


#ifdef PIKO_FULLSCREEN_ENABLED
    int w,h;
    SDL_GetWindowSize(obj.window, &w, &h);
    glViewport(0,0,w,h);
#else 
    glViewport(0,0, m_width, m_height);
#endif

    return obj;

    
}



void pkDestroyWindow(Game win);
void ClearScreen()
{
    glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
}
void UpdateDisplay(Game obj)
{
    SDL_GL_SwapWindow(obj.window);
}
