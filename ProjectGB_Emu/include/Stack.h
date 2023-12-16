#pragma once

#include <Common.h>

void PushStack(u8 data); //pushes an 8 bit value to the stack
void PushStack16Bit(u16 data); //pushes a 16 bit value to the stack

u8 PopStack(); //pops 8 bit value from the stack
u16 PopStack16Bit(); //pops 16 bit value from the stack