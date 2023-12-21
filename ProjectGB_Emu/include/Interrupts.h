
#pragma once

#include <CPU.h>

typedef enum { //type definition for the different types of Interrupts
    IT_VBLANK = 1,
    IT_LCD_STAT = 2,
    IT_TIMER = 4,
    IT_SERIAL = 8,
    IT_JOYPAD = 16
} InterType;

void RequestCPUInterrupts(InterType t);

void HandleCPUInterrupts(CPUContext *context);
