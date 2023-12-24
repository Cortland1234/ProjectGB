#include <CPU.h>
#include <Bus.h>
#include <Emu.h>
#include <Interrupts.h>
#include <Debug.h>
#include <Timer.h>

CPUContext context = {0};

#define CPU_DEBUG 0

void InitializeCPU() 
{
    context.regs.pc = 0x100;
    context.regs.sp = 0xFFFE;
    *((short *)&context.regs.a) = 0xB001;
    *((short *)&context.regs.b) = 0x1300;
    *((short *)&context.regs.d) = 0xD800;
    *((short *)&context.regs.h) = 0x4D01;
    context.interruptEnableReg = 0;
    context.interFlags = 0;
    context.masterInterruptEnabled = false;
    context.enablingIme = false;

    GetTimerContext()->div = 0xABCC;
}

static void FetchInstruction() 
{
    context.currentOpCode = ReadBus(context.regs.pc++); //read the current opcode for the CPU context from the Bus from the context's register program counter. Increment the program counter in the process 
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
        u16 pc = context.regs.pc;

        FetchInstruction(); //fetch instructions
        EMUCycles(1);
        FetchData(); //fetch the data for that instruction


#if CPU_DEBUG == 1 //with this constant we can switch debug mode on or off by changing this value to 0

        char flags[16];
        sprintf(flags, "%c%c%c%c", //getting flags set for debugging
            context.regs.f & (1 << 7) ? 'Z' : '-',
            context.regs.f & (1 << 6) ? 'N' : '-',
            context.regs.f & (1 << 5) ? 'H' : '-',
            context.regs.f & (1 << 4) ? 'C' : '-'
        );

        char inst[16]; //debugging for instructions
        InstructionToString(&context, inst);

        printf("%08lX - %04X: %-12s (%02X %02X %02X) A: %02X F: %s BC: %02X%02X DE: %02X%02X HL: %02X%02X\n", GetEMUContext()->ticks, //debugging output
            pc, inst, context.currentOpCode,
            ReadBus(pc + 1), ReadBus(pc + 2), context.regs.a, flags, context.regs.b, context.regs.c,
            context.regs.d, context.regs.e, context.regs.h, context.regs.l);
#endif
        if (context.curInstruction == NULL)
        {
            printf("Unknown Instruction! %02X\n", context.currentOpCode);
            exit(-7);
        }

        DebugUpdate();
        DebugPrint();

        executeInstruc(); //execute that instruction
    }

    else //if it is halted
    {
        EMUCycles(1);

        if (context.interFlags)
        {
            context.halted = false;
        }
    }

    if (context.masterInterruptEnabled)
    {
        HandleCPUInterrupts(&context);
        context.enablingIme = false;
    }

    if (context.enablingIme)
    {
        context.masterInterruptEnabled = true;
    }

    return true;
}

u8 GetCPUIERegister() //getting the Interrupt Enable Register from CPU
{
    return context.interruptEnableReg;
}
void SetCPUIERegister(u8 n) //setting the IE Register
{
    context.interruptEnableReg = n;
}

void RequestCPUInterrupts(InterType type)
{
    context.interFlags |= type;
}