#include <UI.h>
#include <Emu.h>
#include <Bus.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Window *sdlWin; //objects for the emulator window, rendering, etc
SDL_Renderer *sdlRender;
SDL_Texture *sdlTexture;
SDL_Surface *screen;

SDL_Window *sdlDebugWin; //objects for the debug window
SDL_Renderer *sdlDebugRender;
SDL_Texture *sdlDebugTexture;
SDL_Surface *debugScreen;

static int scale = 4;

void InitializeUI()
{
    SDL_Init(SDL_INIT_VIDEO); //initialize SDL graphics/video
    printf("SDL Initialized.\n");
    TTF_Init(); //initializes fonts
    printf("TTF Initialized.\n");

    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &sdlWin, &sdlRender); //initialize the screen/window for emulator

    SDL_CreateWindowAndRenderer(16 * 8 * scale, 32 * 8 * scale, 0, &sdlDebugWin, &sdlDebugRender); //creating debug window

    debugScreen = SDL_CreateRGBSurface(0, (16 * 8 * scale) + (16 * scale), //code for the debug screen
                                            (32 * 8 * scale) + (64 * scale), 32,
                                            0x00FF0000,
                                            0x0000FF00,
                                            0x000000FF,
                                            0xFF000000);

    sdlDebugTexture = SDL_CreateTexture(sdlDebugRender,
                                            SDL_PIXELFORMAT_ARGB8888,
                                            SDL_TEXTUREACCESS_STREAMING,
                                            (16 * 8 * scale) + (16 * scale), 
                                            (32 * 8 * scale) + (64 * scale));

    int x, y;
    SDL_GetWindowPosition(sdlWin, &x, &y); //getting position of main emulator window
    SDL_SetWindowPosition(sdlDebugWin, x + SCREEN_WIDTH + 10, y); //setting debug window to the right of the main window
}

void Delay(u32 ms) 
{
    SDL_Delay(ms);
}

static unsigned long tileColors[4] = {0xFFFFFFFF, 0xFFAAAAAA, 0xFF555555, 0xFF000000}; //all color codes for the original GameBoy

void DisplayTile(SDL_Surface *surface, u16 startLoc, u16 tileNum, int x, int y)
{
    SDL_Rect rect;

    for (int tileY = 0; tileY < 16; tileY += 2) //each tile is 16bit, so two bytes. hence the += 2
    {
        u8 byte1 = ReadBus(startLoc + (tileNum * 16) + tileY); //reading the first byte for the tile
        u8 byte2 = ReadBus(startLoc + (tileNum * 16) + tileY + 1); //second byte 

        for (int bit = 7; bit >= 0; bit--) //looping through each bit backwards
        {
            u8 high = !!(byte1 & (1 << bit)) << 1;
            u8 low = !!(byte2 & (1 << bit));

            u8 color = high | low;

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

    for (int y = 0; y < 24; y++)
    {
        for (int x = 0; x > 16; x++)
        {
            DisplayTile(debugScreen, address, tileNum, xDraw + (x * scale), yDraw + (y * scale)); //dispalying current tile
            xDraw += (8 * scale); //updating tile location
            tileNum++; //going to next tile
        }

        yDraw += (8 * scale);
        xDraw = 0;
    }

	SDL_UpdateTexture(sdlDebugTexture, NULL, debugScreen->pixels, debugScreen->pitch);
	SDL_RenderClear(sdlDebugRender);
	SDL_RenderCopy(sdlDebugRender, sdlDebugTexture, NULL, NULL);
	SDL_RenderPresent(sdlDebugRender);
}

void UpdateUI()
{
    UpdateDebugWindow();
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