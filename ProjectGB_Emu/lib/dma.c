#include <Dma.h>
#include <PPU.h>
#include <Bus.h>

typedef struct //context for the Direct Memory Transfer
{
    bool active; 
    u8 byte; //current byte
    u8 value;
    u8 startDelay;
} DMAContext;

static DMAContext context;

void StartDMA(u8 start) //invoked when the DMA register is written to (0xFF46)
{
    context.active = true; //making DMA active
    context.byte = 0;
    context.startDelay = 2;
    context.value = start;
}

void DMATick() //everytime this is called
{
    if (!context.active) //if not active, then return
    {
        return;
    }

    if (context.startDelay) //if there is a start delay value
    {
        context.startDelay--; //decrement the value
        return; //return
    }

    WritePpuOam(context.byte, ReadBus((context.value * 0x100) + context.byte)); 

    context.byte++;

    context.active = context.byte < 0xA0; //considered active when byte reaches 0xA0
}

bool TransferringDMA() 
{
    return context.active;
}

