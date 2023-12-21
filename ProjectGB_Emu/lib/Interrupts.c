#include <CPU.h>
#include <Stack.h>
#include <Interrupts.h>

void HandleInterrupts(CPUContext *context, u16 address) //Handles Interrupts. Interrupts jump to a different address in memory.
{
    PushStack16(context->regs.pc); //pushes current address onto the stack
    context->regs.pc = address; //sets the program counter to teh address we need to jump to
}

bool CheckInterrupt(CPUContext *context, u16 address, InterType type) //function checks if there is an interrupt to be processed
{
    if (context->interFlags & type && context->interruptEnableReg & type) //checks if any interrupt is set, which means an interrupt is waiting to be processed
    {
        HandleInterrupts(context, address); //sets context to address where that specific interrupt needs to go
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
    else if (CheckInterrupt(context, 0x60, IT_JOYPAD)) {

    } 
}

