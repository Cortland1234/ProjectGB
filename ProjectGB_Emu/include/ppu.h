#pragma once

#include <Common.h>

static const int LINES_PER_FRAME = 154; //154 lines in a single frame
static const int TICKS_PER_LINE = 456; //456 ticks per line
static const int YRES = 144; //Y Resolution
static const int XRES = 160; //X Resolution

typedef enum {
    FS_TILE,
    FS_DATA0,
    FS_DATA1,
    FS_IDLE,
    FS_PUSH
} FetchState; //enum for the different states of the pixel FIFO

typedef struct {
    struct _fifoEntry *next;
    u32 value; //color of the pixel
} fifoEntry;

typedef struct {
    fifoEntry *head;
    fifoEntry *tail;
    u32 size;
} FIFO;

typedef struct {
    FetchState currentState;
    FIFO pixelFIFO;
    u8 lineX; // x value of current line
    u8 pushedX; // x value that was pushed
    u8 fetchX; //x value that is currently being fetched
    u8 backgroundFetchData[3]; // pixel tiles that are being fetched temporarily
    u8 fetchEntryData[6]; // temp OAM data for sprites
    u8 mapY;
    u8 mapX;
    u8 tileY;
    u8 fifoX;
} PixelFIFOContext;

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
    OAMEntry entry;
    struct OAMLineEntry *next;

} OAMLineEntry;

typedef struct {
    OAMEntry oamRam[40];
    u8 vram[0x2000]; //video ram, defines the data for 386 tiles (16 bytes per tile)

    u8 lineSpriteCount; //0 to 10 sprites on a line
    OAMLineEntry *lineSprites; //linked list of current sprites on the line
    OAMLineEntry lineEntryArray[10]; //pointers for the memory of the linked list so malloc is not needed every time

    u8 fetchEntryCount;
    OAMEntry fetchEntries[3]; //entries fetched during pipeline

    PixelFIFOContext pfc;

    u32 currentFrame;
    u32 lineTicks;
    u32 *vidBuffer; // buffer where we draw the pixels
} PPUContext;

void InitializePPU();
void PPUTick();

PPUContext *GetPPUContext();

void WritePpuOam(u16 address, u8 value);
u8 ReadPpuOam(u16 address);

void WritePpuVram(u16 address, u8 value);
u8 ReadPpuVram(u16 address);
