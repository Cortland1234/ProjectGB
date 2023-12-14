#include <Cpu.h>
#include <Emu.h>
#include <Bus.h>

//Processing instructions from  CPU

void SetCPUFlags(CPUContext *context, char z, char n, char h, char c)
{
    if (z != -1) //if modifying a flag is not needed, then we pass in -1. So if -1 is NOT set we call BIT_SET 
    {
        BIT_SET(context->regs.f, 7, z); //setting the value "7" to z

    }

    if (n != -1) 
    {
        BIT_SET(context->regs.f, 6, n); //setting the value "6" to n
        
    }

    if (h != -1)  
    {
        BIT_SET(context->regs.f, 5, h); //setting the value "5" to h
        
    }

    if (c != -1) 
    {
        BIT_SET(context->regs.f, 4, c); //setting the value "4" to c
        
    }
}


static void ProcNone(CPUContext *context)
{
    printf("INVALID INSTRUCTIONS\n");
    exit(-7);
}

static void ProcNoOp(CPUContext *context)
{

}

static void ProcDi(CPUContext *context)
{
    context->masterInterruptEnabled = false; //disabling interrupts 
}

static void ProcLd(CPUContext *context)
{
    if (context->destinationIsMem) // if the context is in memory
    {
        if (context->curInstruction->reg2 >= RT_AF) // if it is a 16 bit register
        {
            EMUCycles(1);
            WriteBus16Bit(context->memDestination, context->fetchData);
        }
        else
        {
            WriteBus(context->memDestination, context->fetchData);
        }

        return;
    }

    if (context->curInstruction->mode == AM_HL_SPR) //special case
    {
        u8 hFlag = (CPUReadReg(context->curInstruction->reg2) & 0xF) + 
            (context->fetchData & 0xF) >= 0x10;

        u8 cFlag = (CPUReadReg(context->curInstruction->reg2) & 0xFF) + 
            (context->fetchData & 0xFF) >= 0x100;

        SetCPUFlags(context, 0, 0, hFlag, cFlag);
        CPUSetReg(context->curInstruction->reg1, 
            CPUReadReg(context->curInstruction->reg2) + (char)context->fetchData);

        return;
    }

    CPUSetReg(context->curInstruction->reg1, context->fetchData);
}

static void ProcLDH(CPUContext *context)
{
    if (context->curInstruction->reg1 == RT_A) //if the current register is A
    {
        CPUSetReg(context->curInstruction->reg1, ReadBus(0xFF00 | context->fetchData)); //we will set the register to the register from ReadBus
    }
    else
    {
        WriteBus(0xFF00 | context->fetchData, context->regs.a); //otherwise, we will write to HRAM by grabbing the data from regs.a
    }

    EMUCycles(1); //syncing
}

static void ProcXor(CPUContext *context)
{
    // ^= is XOR and =
    context->regs.a ^= context->fetchData & 0xFF; //0xFF because we only need the last byte of fetchData
    SetCPUFlags(context, context->regs.a == 0, 0, 0, 0);
}

static bool CheckCond(CPUContext *context) //checking condition
{
    bool z = CPU_FLAG_Z;
    bool c = CPU_FLAG_C;

    switch(context->curInstruction->cond)
    {
        case CT_NONE: return true;
        case CT_C: return c; //jumping if c is set
        case CT_NC: return !c; //jumping is c is not set
        case CT_Z: return z; //jumping if z is set
        case CT_NZ: return !z; 
    }

    return false;
}

static void ProcJp(CPUContext *context)
{
    if (CheckCond(context))
    {
        context->regs.progCounter = context->fetchData; //if check passes, then we will jump. We do this by setting the context prog counter to the context's fetch data
        EMUCycles(1); //syncing PPU and Timer
    }
}

static IN_PROC processors[] = { //mapping opCodes to processor functionality methods
    [IN_NONE] = ProcNone,
    [IN_NOP] = ProcNoOp,
    [IN_LD] = ProcLd,
    [IN_LDH] = ProcLDH,
    [IN_JP] = ProcJp,
    [IN_DI] = ProcDi,
    [IN_XOR] = ProcXor,

};

IN_PROC InstGetProcessor(instrucType type)
{
    return processors[type]; //returns the processor type that is mapped above
}