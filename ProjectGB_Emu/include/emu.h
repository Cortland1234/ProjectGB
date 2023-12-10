#pragma once

#include <Common.h>

typedef struct { //emu_context typedef is a struct that contains data about the running emulator
    bool paused; //boolean saying whether emulator is paused or not
    bool running; //boolean saying whtehr emulator is running or not
    u64 ticks; //number of processor timer ticks
} emu_context;

int runEmu(int argc, char **argv);

emu_context *emu_get_context(); //get current emulator context