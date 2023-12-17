#pragma once

#include <Common.h>

typedef struct { //emu_context typedef is a struct that contains data about the running emulator
    bool paused; //boolean saying whether emulator is paused or not
    bool running; //boolean saying whether emulator is running or not
    bool die; //boolean saying whether the window closes 
    u64 ticks; //number of processor timer ticks
} EMUContext;

int runEmu(int argc, char **argv);

EMUContext *GetEMUContext(); //get current emulator context

void EMUCycles(int cycles);