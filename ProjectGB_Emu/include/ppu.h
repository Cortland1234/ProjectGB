#pragma once

#include <Common.h>

typedef struct {
    u8 y; //y position for object on the screen
    u8 x; //x position for object on the screen
    u8 tile; //tile index 
    u8 cgbPNFlag : 3; //color game boy palette number 
    u8 cgbVRAMBankFlag : 1;
    u8 paletteNumFlag : 1;
    u8 xFlipFlag : 1;
    u8 yFlipFlag : 1;
    u8 bgPriorityFlag : 1;
} OAMEntry;

/*
 Bit7   BG and Window over OBJ (0=No, 1=BG and Window colors 1-3 over the OBJ)
 Bit6   Y flip          (0=Normal, 1=Vertically mirrored)
 Bit5   X flip          (0=Normal, 1=Horizontally mirrored)
 Bit4   Palette number  **Non CGB Mode Only** (0=OBP0, 1=OBP1)
 Bit3   Tile VRAM-Bank  **CGB Mode Only**     (0=Bank 0, 1=Bank 1)
 Bit2-0 Palette number  **CGB Mode Only**     (OBP0-7)
 */

typedef struct {
    OAMEntry oamRam[40];
    u8 vram[0x2000]; //video ram, defines the data for 386 tiles (16 bytes per tile)
} PPUContext;

void InitializePPU();
void PPUTick();

void WritePpuOam(u16 address, u8 value);
u8 ReadPpuOam(u16 address);

void WritePpuVram(u16 address, u8 value);
u8 ReadPpuVram(u16 address);
