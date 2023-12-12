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

void FetchData();

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