#pragma once

#include <Common.h>
#include <Instructions.h>

typedef struct { //List of Registers from "CPU Registers and Flags" on GBDev.io
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
    u8 l;
    u16 progCounter;
    u16 stackPtr;
} CPURegisters;

typedef struct {
    CPURegisters regs; //state of the CPU's registers
    u16 fetchData; //Current data fetched while grabbing CPU registers
    u16 memDestination; 
    bool destinationIsMem;
    u8 currentOpCode; //OpCode: a machine language instruction that specifies the operation to be performed by the CPU
    instruction *curInstance;

    bool halted; //is CPU halted? boolean
    bool stepping; //is CPU stepping? boolean

} CPUContext;

void InitializeCPU();

bool CPUStep();