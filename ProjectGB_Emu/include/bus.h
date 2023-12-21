#pragma once

#include <Common.h>

//Bus has a read and write data function

u8 ReadBus(u16 address); //8 bit data bus, and a 16 bit address bus. a 16 bit address is passed in and an 8 bit value is returned
void WriteBus(u16 address, u8 value);


u16 ReadBus16(u16 address);
void WriteBus16(u16 address, u16 value);
   