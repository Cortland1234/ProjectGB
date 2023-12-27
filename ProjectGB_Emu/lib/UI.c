#include <UI.h>
#include <Emu.h>
#include <Bus.h>
#include <PPU.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Window *sdlWindow; //objects for the emulator window, rendering, etc
SDL_Renderer *sdlRenderer;
SDL_Texture *sdlTexture;
SDL_Surface *screen;

SDL_Window *sdlDebugWindow; //objects for the debug window
SDL_Renderer *sdlDebugRenderer;
SDL_Texture *sdlDebugTexture;
SDL_Surface *debugScreen;

static int scale = 4;

void InitializeUI() {
    
    SDL_Init(SDL_INIT_VIDEO); //initialize SDL graphics/video
    printf("SDL Initialized.\n");
    TTF_Init(); //initializes fonts
    printf("TTF INIT\n");

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &sdlWindow, &sdlRenderer); //initialize the screen/window for emulator

    screen = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32,
                                            0x00FF0000,
                                            0x0000FF00,
                                            0x000000FF,
                                            0xFF000000);
    sdlTexture = SDL_CreateTexture(sdlRenderer,
                                                SDL_PIXELFORMAT_ARGB8888,
                                                SDL_TEXTUREACCESS_STREAMING,
                                                SCREEN_WIDTH, SCREEN_HEIGHT);    

    SDL_CreateWindowAndRenderer(16 * 8 * scale, 32 * 8 * scale, 0,  //creating debug window
        &sdlDebugWindow, &sdlDebugRenderer);

    debugScreen = SDL_CreateRGBSurface(0, (16 * 8 * scale) + (16 * scale),  //code for the debug screen
                                            (32 * 8 * scale) + (64 * scale), 32,
                                            0x00FF0000,
                                            0x0000FF00,
                                            0x000000FF,
                                            0xFF000000);

    sdlDebugTexture = SDL_CreateTexture(sdlDebugRenderer,
                                            SDL_PIXELFORMAT_ARGB8888,
                                            SDL_TEXTUREACCESS_STREAMING,
                                            (16 * 8 * scale) + (16 * scale), 
                                            (32 * 8 * scale) + (64 * scale));

    int x, y;
    SDL_GetWindowPosition(sdlWindow, &x, &y); //getting position of main emulator window
    SDL_SetWindowPosition(sdlDebugWindow, x + SCREEN_WIDTH + 10, y); //setting debug window to the right of the main window
}

void delay(u32 ms) {
    SDL_Delay(ms);
}

u32 getTicks() //getting the number of ticks since program started
{
    return SDL_GetTicks();
}

static unsigned long tileColors[4] = {0xFFFFFFFF, 0xFFAAAAAA, 0xFF555555, 0xFF000000}; //all color codes for the original GameBoy

void DisplayTile(SDL_Surface *surface, u16 startLoc, u16 tileNum, int x, int y) {
    SDL_Rect rect;

    for (int tileY = 0; tileY < 16; tileY += 2) //each tile is 16bit, so two bytes. hence the += 2
    {
        u8 byte1 = ReadBus(startLoc + (tileNum * 16) + tileY); //reading the first byte for the tile
        u8 byte2 = ReadBus(startLoc + (tileNum * 16) + tileY + 1); //second byte 

        for (int bit = 7; bit >= 0; bit--) //looping through each bit backwards
        {
            u8 hi = !!(byte1 & (1 << bit)) << 1;
            u8 lo = !!(byte2 & (1 << bit));

            u8 color = hi | lo;

            //data for drawing a particular pixel
            rect.x = x + ((7 - bit) * scale); //x loc of the pixel
            rect.y = y + (tileY / 2 * scale); //y loc
            rect.w = scale; //width
            rect.h = scale; //height

            SDL_FillRect(surface, &rect, tileColors[color]); //drawing the pixel
        }
    }
}

void UpdateDebugWindow() //displaying all tiles that are loaded into the OAM
{
    int xDraw = 0;
    int yDraw = 0;
    int tileNum = 0;

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = debugScreen->w;
    rect.h = debugScreen->h;
    SDL_FillRect(debugScreen, &rect, 0xFF111111); //filling whole dbug screen with a dark grey color

    u16 address = 0x8000; //start of VRAM tile data

    //384 tiles in VRAM, ordered in a 24 x 16 matrix (y = 24, x = 16)

    for (int y=0; y<24; y++) 
    {
        for (int x=0; x<16; x++) 
        {
            DisplayTile(debugScreen, address, tileNum, xDraw + (x * scale), yDraw + (y * scale)); //dispalying current tile
            xDraw += (8 * scale); //updating tile location
            tileNum++; //going to next tile
        }

        yDraw += (8 * scale);
        xDraw = 0;
    }

	SDL_UpdateTexture(sdlDebugTexture, NULL, debugScreen->pixels, debugScreen->pitch);
	SDL_RenderClear(sdlDebugRenderer);
	SDL_RenderCopy(sdlDebugRenderer, sdlDebugTexture, NULL, NULL);
	SDL_RenderPresent(sdlDebugRenderer);
}

void UpdateUI() 
{
    SDL_Rect rc;

    rc.x = rc.y = 0;
    rc.w = rc.h = 2048;

    u32 *vidBuffer = GetPPUContext()->vidBuffer;

    for (int lineNum = 0; lineNum < YRES; lineNum++) {
        for (int x = 0; x < XRES; x++) {
            rc.x = x * scale;
            rc.y = lineNum * scale;
            rc.w = scale;
            rc.h = scale;

            SDL_FillRect(screen, &rc, vidBuffer[x + (lineNum * XRES)]);
        }
    }

    SDL_UpdateTexture(sdlTexture, NULL, screen->pixels, screen->pitch);
    SDL_RenderClear(sdlRenderer);
    SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
    SDL_RenderPresent(sdlRenderer);


    UpdateDebugWindow();
}

void HandleUIEvents() 
{
    SDL_Event e;
    while (SDL_PollEvent(&e) > 0) //when there is an event
    {
        if (e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE) //if the SDL event type is Window and the event == close
        {

            GetEMUContext()->die = true;
        }
    }
}

