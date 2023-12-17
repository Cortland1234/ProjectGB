#include <Cpu.h>
#include <Interrupts.h>
#include <Stack.h>

void InterruptHandle(CPUContext *context, u16 address) //Handles Interrupts. Interrupts jump to a different address in memory.
{
    PushStack16Bit(context->regs.progCounter); //pushes current address onto the stack
    context->regs.progCounter = address; //sets the program counter to teh address we need to jump to
}

bool CheckInterrupt(CPUContext *context, u16 address, InterType type) //function checks if there is an interrupt to be processed
{
    if (context->interFlags & type && context->interruptEnableReg & type) //checks if any interrupt is set, which means an interrupt is waiting to be processed
    {
        InterruptHandle(context, address); //sets context to address where that specific interrupt needs to go
        context->interFlags &= ~type;
        context->halted = false; //set halt to false
        context->masterInterruptEnabled = false;

        return true; //returns true if there is an interrupt to be processed
    }

    return false;
}

void HandleCPUInterrupts(CPUContext *context)
{
    if (CheckInterrupt(context, 0x40, IT_VBLANK))
    {

    }
    else if (CheckInterrupt(context, 0x48, IT_LCD_STAT))
    {

    }
    else if (CheckInterrupt(context, 0x50, IT_TIMER))
    {
        
    }
    else if (CheckInterrupt(context, 0x58, IT_SERIAL))
    {
        
    }
     else if (CheckInterrupt(context, 0x60, IT_JOYPAD))
    {
        
    }
}

