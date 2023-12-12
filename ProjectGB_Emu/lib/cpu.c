#include <Cpu.h>
#include <Bus.h>
#include <Emu.h>

CPUContext context = {0};

void InitializeCPU()
{
    context.regs.progCounter = 0x100; //sets program counter to the entry point
    context.regs.a = 0x01; //sets a register to 0x01
}

static void FetchInstruction()
{
    context.currentOpCode = ReadBus(context.regs.progCounter++); //read the current opcode for the CPU context from the Bus from the context's register program counter. Increment the program counter in the process 
    context.curInstruction = InstructionByOpcode(context.currentOpCode); //current instance for context from instructionByOpcode

}

static void FetchData()
{
    context.memDestination = 0; //setting mem destination at 0
    context.destinationIsMem = false; 

    if (context.curInstruction == NULL)
    {
        return;
    }
    
    switch(context.curInstruction->mode)
    {
        case AM_IMP: return; //address is implied, nothing needs to be returned

        case AM_R: 
            context.fetchData = CPUReadReg(context.curInstruction->reg1); //if simple register, then read the CPU's current instance register #1
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
            printf("Unknown Addressing Mode! %d (%02X)\n", context.curInstruction->mode, context.currentOpCode);
            exit(-7);
            return;
    }
}

static void executeInstruc()
{
    IN_PROC proc = InstGetProcessor(context.curInstruction->type); //getting either a function pointer or 0

    if (!proc) //if proc if null, then exits the application
    {
        NO_IMPL
    }

    proc(&context); //otherwise if function is found, then pass the pointer into the current context to execute that function
}

bool CPUStep() 
{
    if (!context.halted) // if CPU context is not halted
    {
        u16 pc = context.regs.progCounter;

        FetchInstruction(); //fetch instructions
        FetchData(); //fetch the data for that instruction

        printf("%04X: %-7s (%02X %02X %02X) A: %02X B: %02X C: %02X\n", 
        pc, InstrucName(context.curInstruction->type), context.currentOpCode,
        ReadBus(pc + 1), ReadBus(pc + 2), context.regs.a, context.regs.b, context.regs.c);

        executeInstruc(); //execute that instruction
    }

    return true;
}