#pragma once

#include <Common.h>

u8 ReadWRAM(u16 address);
void WriteWRAM(u16 address, u8 value);

u8 ReadHRAM(u16 address);
void WriteHRAM(u16 address, u8 value);
