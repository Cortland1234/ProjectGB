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
    instruction *curInstruction;

    bool halted; //is CPU halted? boolean
    bool stepping; //is CPU stepping? boolean

    bool masterInterruptEnabled;
    u8 interruptEnableReg;

} CPUContext;

CPURegisters *GetCPURegs(); //returns the registers for the CPU

void InitializeCPU();

bool CPUStep();

typedef void (*IN_PROC)(CPUContext *); //takes in a function pointer and a CPU Context pointer

IN_PROC InstGetProcessor(instrucType type); //getting function processor by the CPU instruction type

#define CPU_FLAG_Z BIT(context->regs.f, 7)
#define CPU_FLAG_N BIT(context->regs.f, 6)
#define CPU_FLAG_H BIT(context->regs.f, 5)
#define CPU_FLAG_C BIT(context->regs.f, 4)

u16 CPUReadReg(registerType rt); //reads register from CPU

void CPUSetReg(registerType rt, u16 value); //sets a register from the CPU

u8 GetCPUIERegister();
void SetCPUIERegister(u8 n);

u8 CPUReadReg8(registerType rt);
void CPUSetReg8(registerType rt, u8 value); 
