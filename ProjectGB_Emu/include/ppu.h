#pragma once

#include <Common.h>

//Header for Pixel Processing Unit

typedef struct {
    u8 y; //y position for object on the screen
    u8 x; //x position for object on the screen
    u8 tile; //tile index 
    unsigned cgbPNFlag : 3; //color game boy palette number 
    unsigned cgbVRAMBankFlag : 1;
    unsigned paletteNumFlag : 1;
    unsigned xFlipFlag : 1;
    unsigned yFlipFlag : 1;
    unsigned bgPriorityFlag : 1;
} OAMEntry;


typedef struct {
    OAMEntry oamRam[40];
    u8 vram[0x2000]; //video ram
} PPUContext;

void InitializePPU();
void PPUTick();

void WritePpuOam(u16 address, u8 value);
void ReadPpuOam(u16 address);

void WritePpuVram(u16 address, u8 value);
void ReadPpuVram(u16 address);