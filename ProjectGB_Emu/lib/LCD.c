#include <LCD.h>
#include <PPU.h>
#include <Dma.h>

static LCDContext context;

static unsigned long defaultColors[4] = {0xFFFFFFFF, 0xFFAAAAAA, 0xFF555555, 0xFF000000}; //white, light grey, dark grey, black

void InitializeLCD()
{
    context.lcdc = 0x91; //initializing LCD (liquid crystal display), setting atributes and flags
    context.scrollX = 0;
    context.scrollY = 0;
    context.ly = 0;
    context.lyCompare = 0;
    context.bgPalette = 0xFC;
    context.objPalette[0] = 0xFF;
    context.objPalette[0] = 0xFF;
    context.winX = 0;
    context.winY = 0;

    for (int i = 0; i < 4; i++) //setting colors
    {
    context.bgColors[i] = defaultColors[i];
    context.spriteColors1[i] = defaultColors[i];
    context.spriteColors2[i] = defaultColors[i];
    }
}

LCDContext *GetLCDContext()
{
    return &context;
}

u8 ReadLCD(u16 address)
{
    u8 offset = (address - 0xFF40);
    u8 *p = (u8 *)&context; //turning context into byte array

    return p[offset]; //returning the byte array at the offset location
}

void UpdatePalette(u8 paletteData, u8 palette) 
{
    u32 *pColors = context.bgColors;

    switch(palette)
    {
        case 1:
            pColors = context.spriteColors1;
            break;
        case 2:
            pColors = context.spriteColors2;
            break;        
    }

    pColors[0] = defaultColors[paletteData & 0b11];
    pColors[1] = defaultColors[(paletteData >> 2) & 0b11];
    pColors[2] = defaultColors[(paletteData >> 4) & 0b11] ;
    pColors[3] = defaultColors[(paletteData >> 6) & 0b11];
}

void WriteLCD(u16 address, u8 value)
{
    u8 offset = (address - 0xFF40);
    u8 *p = (u8 *)&context; //turning context into byte array

    p[offset] = value;

    if (offset == 6) //if offset is at 6, we are at Direct Access Memory (0xFF46)
    {
        StartDMA(value); //start the DMA
    }



    if (address == 0xFF47) //if the address are in the ranges of the palettes, we need to execute special instructions
    {
        UpdatePalette(value, 0);
    }
    else if (address == 0xFF48)
    {
        UpdatePalette(value & 0b11111100, 1);
    }
    else if (address == 0xFF49)
    {
        UpdatePalette(value & 0b11111100, 2);
    }
}