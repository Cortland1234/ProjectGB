#include <Ppu.h>

static PPUContext context;

void InitializePPU()
{

}

void PPUTick() 
{

}

void WritePpuOam(u16 address, u8 value)
{
    if (address >= 0xFE00) //if address is greater than or equal to 0xFE00
    {
        address -= 0xFE00; //subtract 0xFE00 fro mthe address so we can only retain the offset value
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