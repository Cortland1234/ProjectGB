#pragma once

#include <Common.h>

//header for the LCD (covering the display)

typedef struct
{
   //registers 
   u8 lcdc; 
   u8 lcds;
   u8 scrollY;
   u8 scrollX;
   u8 ly;
   u8 lyCompare;
   u8 dma;
   u8 bgPalette; //background palette
   u8 objPalette[2]; //sprite palettes
   u8 winY;
   u8 winX;

   //other data
   u32 bgColors[4];
   u32 spriteColors1[4];
   u32 spriteColors2[4];

} LCDContext;

typedef enum {
   MODE_HBLANK,
   MODE_VBLAN,
   MODE_OAM,
   MODE_XFER
} LCDMode;

LCDContext *GetLCDContext();

#define LDCD_BGW_ENABLE (BIT(GetLCDContext()->lcdc, 0)) //lcd background enable
#define LCDC_OBJ_ENABLE (BIT(GetLCDContext()->lcdc, 1)) //sprites enable
#define LCDC_OBJ_HEIGHT (BIT(GetLCDContext()->lcdc, 2) ? 16 : 8) //sprite height
#define LCDC_BG_MAP_AREA (BIT(GetLCDContext()->lcdc, 3) ? 0x9C00 : 0x9800) 
#define LCDC_BGW_DATA_AREA (BIT(GetLCDContext()->lcdc, 4) ? 0x8000 : 0x8800)
#define LCDC_WIN_ENABLE (BIT(GetLCDContext()->lcdc, 5))
#define LCDC_WIN_MAP_AREA (BIT(GetLCDContext()->lcdc, 6) ? 0x9C00 : 0x9800)
#define LCDC_LCD_ENABLE (BIT(GetLCDContext()->lcdc, 7))

#define LCDS_MODE ((lcd_mode)(GetLCDContext()->lcds & 0b11)) //flag for telling us what mode the LCD is currently in
#define LCDS_MODE_SET(mode) { GetLCDContext()->lcds &= ~0b11; GetLCDContext()->lcds |= mode; } // sets the mode for the LCD

#define LCDS_LYC (BIT(GetLCDContext()->lcds, 2)) //LYC flag, set if ly and lyCompare are equal
#define LCDS_LYC_SET(b) (BIT_SET(GetLCDContext()->lcds, 2, b)) 

typedef enum {
   SS_HBLANK = (1 << 3),
   SS_VBLANK = (1 << 4),
   SS_OAM = (1 << 5),
   SS_LYC = (1 << 6),
} statSrc;

#define LCDS_STAT_INT(src) (lcd_get_context()->lcds & src)

void InitializeLCD();

u8 ReadLCD(u16 address);
void WriteLCD(u16 address, u8 value);