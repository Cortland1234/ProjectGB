#pragma once

#include <Common.h>

typedef struct { //emu_context typedef is a struct that contains data about the running emulator
    bool paused; //boolean saying whether emulator is paused or not
    bool running; //boolean saying whtehr emulator is running or not
    u64 ticks; //number of processor timer ticks
} EMUContext;

int runEmu(int argc, char **argv);

EMUContext *GetEMUContext(); //get current emulator context

void EMUCycles(int cycles);