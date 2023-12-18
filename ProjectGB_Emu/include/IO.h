#pragma once

#include <Common.h>

u8 ReadIO(u16 address); //8 bit data bus, and a 16 bit address bus. a 16 bit address is passed in and an 8 bit value is returned

void WriteIO(u16 address, u8 value);