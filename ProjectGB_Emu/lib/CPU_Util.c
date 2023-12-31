#include <CPU.h>
#include <Bus.h>

extern CPUContext context;

u16 Reverse(u16 n) //based on the register type passed as parameter
{
    return ((n & 0xFF00) >> 8) | ((n & 0x00FF) << 8); //returns the register and either shifts the high byte over to the left OR shifts the low byte over to the right by 8
}

u16 CPUReadReg(registerType rt) //reads CPU register
{
    switch(rt) {
        case RT_A: return context.regs.a; //returning the context's 8 bit register type depending on register type
        case RT_F: return context.regs.f;
        case RT_B: return context.regs.b;
        case RT_C: return context.regs.c;
        case RT_D: return context.regs.d;
        case RT_E: return context.regs.e;
        case RT_H: return context.regs.h;
        case RT_L: return context.regs.l;

        case RT_AF: return Reverse(*((u16 *)&context.regs.a)); //using Reverse to get the register type for the 16 bit
        case RT_BC: return Reverse(*((u16 *)&context.regs.b));
        case RT_DE: return Reverse(*((u16 *)&context.regs.d));
        case RT_HL: return Reverse(*((u16 *)&context.regs.h));

        case RT_PC: return context.regs.pc;
        case RT_SP: return context.regs.sp;
        default: return 0;
    }
}

void CPUSetReg(registerType rt, u16 val) //sets a CPU register
{
    switch(rt) {
        case RT_A: context.regs.a = val & 0xFF; break; //for 8 bit values, we end with 0xFF
        case RT_F: context.regs.f = val & 0xFF; break;
        case RT_B: context.regs.b = val & 0xFF; break;
        case RT_C: {
             context.regs.c = val & 0xFF;
        } break;
        case RT_D: context.regs.d = val & 0xFF; break;
        case RT_E: context.regs.e = val & 0xFF; break;
        case RT_H: context.regs.h = val & 0xFF; break;
        case RT_L: context.regs.l = val & 0xFF; break;

        case RT_AF: *((u16 *)&context.regs.a) = Reverse(val); break; //for 16 bit values, we Reverse
        case RT_BC: *((u16 *)&context.regs.b) = Reverse(val); break;
        case RT_DE: *((u16 *)&context.regs.d) = Reverse(val); break;
        case RT_HL: {
         *((u16 *)&context.regs.h) = Reverse(val); 
         break;
        }

        case RT_PC: context.regs.pc = val; break;
        case RT_SP: context.regs.sp = val; break;
        case RT_NONE: break;
    }
}


u8 CPUReadReg8(registerType rt) //CPUReadReg8 and CPUSetReg8 function the register operations for the bitwise functions
{
    switch(rt) {
        case RT_A: return context.regs.a;
        case RT_F: return context.regs.f;
        case RT_B: return context.regs.b;
        case RT_C: return context.regs.c;
        case RT_D: return context.regs.d;
        case RT_E: return context.regs.e;
        case RT_H: return context.regs.h;
        case RT_L: return context.regs.l;
        case RT_HL: {
            return ReadBus(CPUReadReg(RT_HL));
        }
        default:
            printf("**ERR INVALID REG8: %d\n", rt);
            NO_IMPL
    }
}

void CPUSetReg8(registerType rt, u8 val) 
{
    switch(rt) {
        case RT_A: context.regs.a = val & 0xFF; break;
        case RT_F: context.regs.f = val & 0xFF; break;
        case RT_B: context.regs.b = val & 0xFF; break;
        case RT_C: context.regs.c = val & 0xFF; break;
        case RT_D: context.regs.d = val & 0xFF; break;
        case RT_E: context.regs.e = val & 0xFF; break;
        case RT_H: context.regs.h = val & 0xFF; break;
        case RT_L: context.regs.l = val & 0xFF; break;
        case RT_HL: WriteBus(CPUReadReg(RT_HL), val); break;
        default:
            printf("**ERR INVALID REG8: %d\n", rt);
            NO_IMPL
    }
}

CPURegisters *GetCPURegs() 
{
    return &context.regs;
}

u8 GetCPUIntFlags() //getting CPU interrupt flags
{
    return context.interFlags;
}

void SetCPUIntFlags(u8 value) //setting CPU interrupt flags
{
    context.interFlags = value;
}
