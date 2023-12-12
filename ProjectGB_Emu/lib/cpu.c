#include <Cpu.h>
#include <Bus.h>
#include <Emu.h>

CPUContext context = {0};

void InitializeCPU()
{
    context.regs.progCounter = 0x100; //sets program counter to the entry point
}

static void fetchInstruction()
{
    context.currentOpCode = ReadBus(context.regs.progCounter++); //read the current opcode for the CPU context from the Bus from the context's register program counter. Increment the program counter in the process 
    context.curInstance = instructionByOpcode(context.currentOpCode); //current instance for context from instructionByOpcode

    if (context.curInstance == NULL)
    {
        printf("Unknown Instruction! %02X\n", context.currentOpCode);
        exit(-7);
    }
}

static void fetchData()
{
    context.memDestination = 0; //setting mem destination at 0
    context.destinationIsMem = false; 
    
    switch(context.curInstance->mode)
    {
        case AM_IMP: return; //address is implied, nothing needs to be returned

        case AM_R: 
            context.fetchData = CPUReadReg(context.curInstance->reg1); //if simple register, then read the CPU's current instance register #1
            return;

        case AM_R_D8: //take 8 bit value and transfer it into a register
            context.fetchData = ReadBus(context.regs.progCounter);
            EMUCycles(1); //1 CPU cycle for reading the Bus
            context.regs.progCounter++; //increment progcounter
            return;

        case AM_D16:
        {
            u16 low = ReadBus(context.regs.progCounter); //16 bit, but we can only read 8 bits at a time, so first we read the low value program counter
            EMUCycles(1); //syncing the emulator

            u16 high = ReadBus(context.regs.progCounter + 1); //reading the high value
            EMUCycles(1);

            context.fetchData = low | (high << 8); //fetched data is either the low value or the high value bit shifted over 8
            context.regs.progCounter += 2; //increment coutner by 2 because there are two 8 bit values

            return;
        }

        default:
            printf("Unknown Addressing Mode! %d\n", context.curInstance->mode);
            exit(-7);
            return;
    }
}

static void executeInstruc()
{
    printf("Not Executing yet\n");
}

bool CPUStep() 
{
    if (!context.halted) // if CPU context is not halted
    {
        u16 pc = context.regs.progCounter;
        
        fetchInstruction(); //fetch instructions
        fetchData(); //fetch the data for that instruction

        printf("Executing Instruction %02X     Program Counter: %04X\n", context.currentOpCode, context.regs.progCounter);

        executeInstruc(); //execute that instruction
    }

    return true;
}