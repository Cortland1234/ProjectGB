#include <dma.h>
#include <PPU.h>
#include <Bus.h>

typedef struct 
{
    bool active;
    u8 byte;
    u8 value;
    u8 startDelay;
} DMAContext;

static DMAContext context;

void StartDMA(u8 start) 
{
    context.active = true;
    context.byte = 0;
    context.startDelay = 2;
    context.value = start;
}

void DMATick() 
{
    if (!context.active) 
    {
        return;
    }

    if (context.startDelay) 
    {
        context.startDelay--;
        return;
    }

    WritePpuOam(context.byte, ReadBus((context.value * 0x100) + context.byte));

    context.byte++;

    context.active = context.byte < 0xA0;

    if (!context.active) 
    {
        printf("DMA DONE!\n");
        sleep(2);
    }
}

bool TransferringDMA() 
{
    return context.active;
}

