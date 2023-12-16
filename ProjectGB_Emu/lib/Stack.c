#include <Stack.h>
#include <Cpu.h>
#include <Bus.h>

void PushStack(u8 data) //pushes an 8 bit value to the stack
{
    GetCPURegs()->stackPtr--; //decrement the stack pointer from the cpu register
    WriteBus(GetCPURegs()->stackPtr, data); //writing current data parameter to the stack pointer
}
void PushStack16Bit(u16 data) //pushes a 16 bit value to the stack
{
    PushStack((data >> 8) & 0xFF); //pushing the top byte of that 16 bit data param
    PushStack(data & 0xFF); //pushing the bottom byte of the 16 bit param
}

u8 PopStack() //pops 8 bit value from the stack
{
  return ReadBus(GetCPURegs()->stackPtr++); //returns a ReadBus at the incremented stack pointer  
}
u16 PopStack16Bit() //pops 16 bit value from the stack
{
    u16 low = PopStack();
    u16 high = PopStack();

    return (high << 8) | low; //returns the high byte shifted left by 8 or return the low byte
}