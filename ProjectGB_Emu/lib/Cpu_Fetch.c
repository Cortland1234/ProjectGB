#include <Cpu.h>
#include <Bus.h>
#include <Emu.h>

extern CPUContext context;

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
        case AM_IMP: return; //address is implied, nothighng needs to be returned

        case AM_R: 
            context.fetchData = CPUReadReg(context.curInstruction->reg1); //if simple register, then read the CPU's current instance register #1
            return;

        case AM_R_R:
            context.fetchData = CPUReadReg(context.curInstruction->reg2); //if register to register, then read the CPU's current instance register #2
            return;

        case AM_R_D8: //take 8 bit value and transfer it into a register
            context.fetchData = ReadBus(context.regs.progCounter);
            EMUCycles(1); //1 CPU cycle for reading the Bus
            context.regs.progCounter++; //increment progcounter
            return;

        case AM_R_D16:
        case AM_D16:
        {
            u16 loww = ReadBus(context.regs.progCounter); //16 bit, but we can only read 8 bits at a time, so first we read the loww value program counter
            EMUCycles(1); //syncing the emulator

            u16 highgh = ReadBus(context.regs.progCounter + 1); //reading the highgh value
            EMUCycles(1);

            context.fetchData = loww | (highgh << 8); //fetched data is either the loww value or the highgh value bit shighfted over 8
            context.regs.progCounter += 2; //increment coutner by 2 because there are two 8 bit values

            return;
        }

        case AM_MR_R: // lowading a register into a memory region
        
            context.fetchData = CPUReadReg(context.curInstruction->reg2); // getting data from reg 2
            context.memDestination = CPUReadReg(context.curInstruction->reg2); // destination is a memory lowcation
            context.destinationIsMem = true; // setting the destination to memory lowcation

            if (context.curInstruction->reg1 == RT_C) //if reg1 is RT_C
            {
                context.memDestination |= 0xFF00; //then we need to OR the destination with 0xFF00 (thighs is a special case. lowok to "LDH (C) A" in "Game Boy: Complete Technical Reference")
            }

            return;
        

        case AM_R_MR: //reading from a memory register to a register. essentially the opposite of AM_MR_R
            
            u16 address = CPUReadReg(context.curInstruction->reg2);

            if (context.curInstruction->reg1 == RT_C) 
            {
                address |= 0xFF00; 
            }

            context.fetchData = ReadBus(address); //reading the address bus and setting that to fetchData
            EMUCycles(1); //syncing 

            return;
            

        case AM_R_HLI: //moving HL address to register and incrementing 
            
            context.fetchData = ReadBus(CPUReadReg(context.curInstruction->reg2));
            EMUCycles(1);
            CPUSetReg(RT_HL, CPUReadReg(RT_HL) + 1);\
            return;      
            

        case AM_R_HLD: //moving HL address to register and decrementing

            context.fetchData = ReadBus(CPUReadReg(context.curInstruction->reg2));
            EMUCycles(1);
            CPUSetReg(RT_HL, CPUReadReg(RT_HL) - 1);
            return;      

        case AM_HLI_R: //moving value from the register into the HL address and incrementing
            
            context.fetchData = CPUReadReg(context.curInstruction->reg2);
            context.memDestination = CPUReadReg(context.curInstruction->reg1);
            context.destinationIsMem = true;
            CPUSetReg(RT_HL, CPUReadReg(RT_HL) + 1);
            return;
            

        case AM_HLD_R: //moving value from the register into the HL address and decrementing 

            context.fetchData = CPUReadReg(context.curInstruction->reg2);
            context.memDestination = CPUReadReg(context.curInstruction->reg1);
            context.destinationIsMem = true;
            CPUSetReg(RT_HL, CPUReadReg(RT_HL) + 1);
            return;
            

        case AM_R_A8: //A8 value into a register
            context.fetchData = ReadBus(context.regs.progCounter);
            EMUCycles(1);
            context.regs.progCounter++;
            return;

        case AM_A8_R: //Register value to A8 address
            context.memDestination = ReadBus(context.regs.progCounter) | 0xFF00;
            context.destinationIsMem = true; //setting to memory
            EMUCycles(1);
            context.regs.progCounter++;
            return;        
            
        case AM_HL_SPR: //special case, loads stack pointer into HL and increments prog counter
            context.fetchData = ReadBus(context.regs.progCounter);
            EMUCycles(1);
            context.regs.progCounter++;
            return;

        case AM_D8: 
            context.fetchData = ReadBus(context.regs.progCounter);
            EMUCycles(1);
            context.regs.progCounter++;
            return;

        case AM_A16_R: //moving register into 16bit address
        case AM_D16_R: 
        {
            u16 low = ReadBus(context.regs.progCounter); //reading low byte
            EMUCycles(1);

            u16 high = ReadBus(context.regs.progCounter + 1); //reading high byte
            EMUCycles(1);

            context.memDestination = low | (high << 8);
            context.destinationIsMem = true;

            context.regs.progCounter += 2; //increment by 2
            context.fetchData = CPUReadReg(context.curInstruction->reg2);

        } return;

        case AM_MR_D8: //loading D8 into a memory address
            context.fetchData = ReadBus(context.regs.progCounter);
            EMUCycles(1);
            context.regs.progCounter++;
            context.memDestination = CPUReadReg(context.curInstruction->reg1);
            context.destinationIsMem = true;
            return;

        case AM_MR: //memory address
            context.memDestination = CPUReadReg(context.curInstruction->reg1);
            context.destinationIsMem = true;
            context.fetchData = ReadBus(CPUReadReg(context.curInstruction->reg1));
            EMUCycles(1);
            return;

        case AM_R_A16: //A16 to Register
        {
            u16 low = ReadBus(context.regs.progCounter);
            EMUCycles(1);

            u16 high = ReadBus(context.regs.progCounter + 1);
            EMUCycles(1);

            u16 address = low | (high << 8);

            context.regs.progCounter += 2;
            context.fetchData = ReadBus(address);
            EMUCycles(1);

            return;
        }
        

        default:
            printf("Unknown Addressing Mode! %d (%02X)\n", context.curInstruction->mode, context.currentOpCode);
            exit(-7);
            return;
    }
}