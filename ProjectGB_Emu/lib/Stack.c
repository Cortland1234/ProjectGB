#include <Stack.h>
#include <CPU.h>
#include <Bus.h>

void PushStack(u8 data) //pushes an 8 bit value to the stack
{
    GetCPURegs()->sp--; //decrement the stack pointer from the cpu register
    WriteBus(GetCPURegs()->sp, data); //writing current data parameter to the stack pointer
}
void PushStack16(u16 data) //pushes a 16 bit value to the stack
{
    PushStack((data >> 8) & 0xFF); //pushing the top byte of that 16 bit data param
    PushStack(data & 0xFF); //pushing the bottom byte of the 16 bit param
}

u8 PopStack() //pops 8 bit value from the stack
{
  return ReadBus(GetCPURegs()->sp++); //returns a ReadBus at the incremented stack pointer  
}

u16 PopStack16() //pops 16 bit value from the stack
{
    u16 lo = PopStack();
    u16 hi = PopStack();

    return (hi << 8) | lo; //returns the high byte shifted left by 8 or return the low byte
}
