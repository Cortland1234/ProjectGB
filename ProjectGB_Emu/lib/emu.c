#include <stdio.h>
#include <Emu.h>
#include <Cartridge.h>
#include <CPU.h>
#include <UI.h>
#include <Timer.h>
#include <Dma.h>
#include <pthread.h>
#include <unistd.h>
#include <PPU.h>

/* 
  Emu components:

  |Cart|
  |CPU|
  |Address Bus|
  |PPU|
  |Timer|

*/

static EMUContext context;

EMUContext *GetEMUContext()  //returns current emulator context object
{
    return &context;
}

void *RunCPU(void *p) //this will be the main thread running for the CPU
{
    InitializeTimer();
    InitializeCPU(); //initializing CPU
    InitializePPU();

    context.running = true; //setting context variables
    context.paused = false;
    context.ticks = 0;

    while(context.running) //infinite game loop
    {
        if (context.paused) 
        {
            delay(10);
            continue;
        }

        if (!CPUStep()) //if CPU fails, then program terminates
        {
            printf("ERROR: CPU Stopped. Program Stopping.\n");
            return 0;
        }
    }

    return 0;
}

int RunEMU(int argc, char **argv) //function for running the emulator with error checks
{
    if (argc < 2) //if wrong file is passed as an arg, print error and stop program
    {
        printf("Usage: emu <rom_file>\n");
        return -1;
    }

    if (!LoadCartridge(argv[1])) //CartridgeLoad loads the rom file; if it fails, then an error is printed and program stops
    {
        printf("Failed to load ROM file: %s\n", argv[1]);
        return -2;
    }

    printf("Cartridge Accepted. Loading...\n");

    InitializeUI(); //self explanatory
    
    pthread_t thread1;

    if (pthread_create(&thread1, NULL, RunCPU, NULL)) //if cpu thread cannot be started, return -1
    {
        fprintf(stderr, "FAILED TO START MAIN CPU THREAD!\n");
        return -1;
    }

    u32 prevFrame = 0;

    while(!context.die) //while emu window is not dead (closed)
    {
        usleep(1000); //sleep for 1000 ms
        HandleUIEvents(); //call event handler for UI

        if(prevFrame != GetPPUContext()->currentFrame) //if the frame is not synced to the PPU, call UpdateUI
        {
            UpdateUI();
        }

        prevFrame = GetPPUContext()->currentFrame;
        
    }

    return 0;
}

void EMUCycles(int cycles) 
{
    
    for (int i = 0; i < cycles; i++) 
    {
        for (int n = 0; n < 4; n++) 
        {
            context.ticks++;
            TimerTick();
            PPUTick();
        }

        DMATick();
    }
}
