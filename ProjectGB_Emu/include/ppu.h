#pragma once

#include <Common.h>

//Header for Pixel Processing Unit

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