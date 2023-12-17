#include <UI.h>
#include <Emu.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Window *sdlWin; //objects for the emulator window, rendering, etc
SDL_Renderer *sdlRender;
SDL_Texture *sdlTexture;
SDL_Surface *screen;

void InitializeUI()
{
    SDL_Init(SDL_INIT_VIDEO); //initialize SDL graphics/video
    printf("SDL Initialized.\n");
    TTF_Init(); //initializes fonts
    printf("TTF Initialized.\n");

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &sdlWin, &sdlRender); //initialize the screen/window for emulator
}

void Delay(u32 ms) 
{
    SDL_Delay(ms);
}

void HandleUIEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) > 0) //when there is an event
    {
        if (event.type = SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE) //if the SDL event type is Window and the event == close
        {
            GetEMUContext()->die = true;
        }
    }
}