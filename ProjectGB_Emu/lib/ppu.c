#include <PPU.h>
#include <LCD.h>
#include <string.h>
#include <PPUsm.h>

void PipelineFIFOReset(); //declaring functions for PPUPipeline.c
void PipelineProcess();

static PPUContext context;

PPUContext *GetPPUContext()
{
    return &context;
}

void InitializePPU() 
{
    context.currentFrame = 0;
    context.lineTicks = 0;
    context.vidBuffer = malloc(YRES * XRES * sizeof(32)); //allocating memory for the video buffer

    context.pfc.lineX = 0; //setting pixel FIFO values
    context.pfc.pushedX = 0;
    context.pfc.fetchX = 0;
    context.pfc.pixelFIFO.size = 0;
    context.pfc.pixelFIFO.head = context.pfc.pixelFIFO.tail = NULL;
    context.pfc.currentState = FS_TILE;

    context.lineSprites = 0;
    context.fetchEntryCount = 0;
    context.windowLine = 0;

    InitializeLCD();
    LCDS_MODE_SET(MODE_OAM);

    memset(context.oamRam, 0, sizeof(context.oamRam)); //zeroing out the OAM RAM
    memset(context.vidBuffer, 0, YRES * XRES * sizeof(u32)); //zeroing out the video buffer
}

void PPUTick() 
{
    context.lineTicks++; //for every PPU tick, we increment the line ticks

    switch(LCDS_MODE)
    {
        case MODE_OAM:
            PPUModeOAM();
            break;
        case MODE_XFER:
            PPUModeXFER();
            break;
        case MODE_VBLANK:
            PPUModeVBLANK();
            break;
        case MODE_HBLANK:
            PPUModeHBLANK();
            break;
    }        
}


void WritePpuOam(u16 address, u8 value) 
{
    if (address >= 0xFE00) 
    {
        address -= 0xFE00;
    }

    u8 *p = (u8 *)context.oamRam;
    p[address] = value;
}

u8 ReadPpuOam(u16 address) 
{
    if (address >= 0xFE00) 
    {
        address -= 0xFE00;
    }

    u8 *p = (u8 *)context.oamRam;
    return p[address];
}

void WritePpuVram(u16 address, u8 value) 
{
    context.vram[address - 0x8000] = value;
}

u8 ReadPpuVram(u16 address) 
{
    return context.vram[address - 0x8000];
}

