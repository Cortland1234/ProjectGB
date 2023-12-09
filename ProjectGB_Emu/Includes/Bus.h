#pragma once

#include <Common.h>

//Bus had a read and write data function

u8 ReadBus(u16 address); //8 bit data bus, and a 16 bit address bus. a 16 bit address is passed in and an 8 bit value is returned
void WriteBus(u16 address, u8 value);