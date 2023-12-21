#pragma once

#include <Common.h>

typedef struct {
    u16 div; //divider register 
    u8 tima; //timer register
    u8 tma; //timer module
    u8 tac; //timer control
} TimerContext;

void InitializeTimer();
void TimerTick();

void WriteTimer(u16 address, u8 value);
u8 ReadTimer(u16 address);

TimerContext *GetTimerContext();
