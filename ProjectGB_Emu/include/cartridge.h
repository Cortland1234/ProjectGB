#pragma once

#include <common.h>

//cartridge info from "Cartridge Header" on gbdev.io

typedef struct {
    u8 entryPoint[4]; //entry point after cartridge boots
    u8 logo[0x30]; //nintendo logo

    char title[16]; //title of game
    u16 newLicenseCode; //license of the publisher
    u8 sgbFlag; //byte that specifies whether SGB is supported
    u8 type; 
    u8 romSize; //indicates how large the ROM is
    u8 ramSize; //indicates how much RAM is on the cartridge
    u8 destinationCode; //indicates whether cartridge is sold in Japan or elsewhere
    u8 licenseCode; //Older license code
    u8 version; //version of the ROM
    u8 checksum; //byte containing an 8-bit checksum for the ROM to verify
    u16 globalChecksum; //sum of all bytes of the cartridge ROM
} rom_header;

bool LoadCartridge(char *cart);