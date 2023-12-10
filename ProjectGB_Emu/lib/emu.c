#include <stdio.h>
#include <emu.h>
#include <cartridge.h>
#include <cpu.h>
#include <common.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

static emu_context context; 

emu_context *emu_get_context() //returns current emulator context object
{
    return &context;
}

void Delay(u32 ms) 
{
    SDL_Delay(ms);
}

int runEmu(int argc, char **argv) //function for running the emulator with error checks
{
    if (argc < 2) //if wrong file is passed as an arg, print error and stop program
    {
        printf("ERROR! Use: emu <rom file>\n");
        return -1;
    }

    if (!LoadCartridge(argv[1])) //CartridgeLoad loads the rom file; if it fails, then an error is printed and program stops
    {
        printf("Failed to load ROM file: %s\n", argv[1]);
        return -2;
    }

    printf("Cartridge Accepted. Loading...\n");

    SDL_Init(SDL_INIT_VIDEO); //initialize SDL graphics/video
    printf("SDL Initialized.\n");
    TTF_Init(); //initializes fonts
    printf("TTF Initialized.\n");

    InitializeCPU(); //self explanatory

    context.running = true; //setting context variables
    context.paused = false;
    context.ticks = 0;

    while(context.running) //infinite game loop
    {
        if (context.paused)
        {
            Delay(10);
            continue;
        }

        if (!CPUStep()) //if CPU fails, then program terminates
        {
            printf("ERROR: CPU Stopped. Program Stopping.\n");
            return -3;
        }

        context.ticks++;
    }
    return 0;
}