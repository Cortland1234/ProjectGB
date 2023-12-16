#include <Cpu.h>
#include <Emu.h>
#include <Bus.h>
#include <Stack.h>

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

registerType regLookup[] =
{
    RT_B,
    RT_C,
    RT_D,
    RT_E,
    RT_H,
    RT_L,
    RT_HL,
    RT_A
};

registerType DecodeRegister(u8 reg)
{
    if (reg > 0b111)
    {
        return RT_NONE;
    }

    return regLookup[reg];
}

static void ProcCb(CPUContext *context)
{
    u8 op = context->fetchData;
    registerType reg = DecodeRegister(op & 0b111); //register decoded from op, AKA the fetchData
    u8 bit = (op >> 3) & 0b111; 
    u8 bitOp = (op >> 6) & 0b111;
    u8 regValue = CPUReadReg8(reg);

    EMUCycles(1);

    if (reg == RT_HL) //if HL, then we need 2 emu cycles to compensate/sync
    {
        EMUCycles(2);
    }

    switch(bitOp) //switch statement for all bit operations 
    {
        case 1:
            //BIT
            SetCPUFlags(context, !(regValue & (1 << bit)), 0, 1, -1);
            return;

        case 2:
            //RST
            regValue &= ~(1 << bit);
            CPUSetReg8(reg, regValue);
            return;

        case 3:
            //SET
            regValue |= (1 << bit);
            CPUSetReg8(reg, regValue);
            return;
    }

    bool flagC = CPU_FLAG_C;

    switch(bit) //switch statement for operating/moving a bit
    {
        case 0: 
        {
            //RLC
            bool setC = false;
            u8 result = (regValue << 1) & 0xFF;

            if ((regValue & (1 << 7)) != 0) {
                result |= 1;
                setC = true;
            }

            CPUSetReg8(reg, result);
            SetCPUFlags(context, result == 0, false, false, setC);
        } return;

        case 1: 
        {
            //RRC
            u8 old = regValue;
            regValue >>= 1;
            regValue |= (old << 7);

            CPUSetReg8(reg, regValue);
            SetCPUFlags(context, !regValue, false, false, old & 1);
        } return;

        case 2: 
        {
            //RL
            u8 old = regValue;
            regValue <<= 1;
            regValue |= flagC;

            CPUSetReg8(reg, regValue);
            SetCPUFlags(context, !regValue, false, false, !!(old & 0x80));
        } return;

        case 3:
         {
            //RR
            u8 old = regValue;
            regValue >>= 1;

            regValue |= (flagC << 7);

            CPUSetReg8(reg, regValue);
            SetCPUFlags(context, !regValue, false, false, old & 1);
        } return;

        case 4: 
        {
            //SLA
            u8 old = regValue;
            regValue <<= 1;

            CPUSetReg8(reg, regValue);
            SetCPUFlags(context, !regValue, false, false, !!(old & 0x80));
        } return;

        case 5: 
        {
            //SRA
            u8 u = (int8_t)regValue >> 1;
            CPUSetReg8(reg, u);
            SetCPUFlags(context, !u, 0, 0, regValue & 1);
        } return;

        case 6: 
        {
            //SWAP
            regValue = ((regValue & 0xF0) >> 4) | ((regValue & 0xF) << 4);
            CPUSetReg8(reg, regValue);
            SetCPUFlags(context, regValue == 0, false, false, false);
        } return;

        case 7: 
        {
            //SRL
            u8 u = regValue >> 1;
            CPUSetReg8(reg, u);
            SetCPUFlags(context, !u, 0, 0, regValue & 1);
        } return;
    }

    fprintf(stderr, "ERROR: INVALID CB: %02X", op);
    NO_IMPL
}

static void ProcRLCA(CPUContext *context)
{
    u8 u = context->regs.a;
    bool c = (u >> 7) & 1; //returns true if u is shifted over 7 AND 1
    u = (u << 1) | c;
    context->regs.a = u;  //sets reg A to new u value

    SetCPUFlags(context, 0, 0, 0, c);

}

static void ProcRRCA(CPUContext *context)
{
    u8 b = context->regs.a & 1;
    context->regs.a >>= 1;
    context->regs.a |= (b << 7);

    SetCPUFlags(context, 0, 0, 0, b);
}

static void ProcRLA(CPUContext *context)
{
    u8 u = context->regs.a;
    u8 cFlag = CPU_FLAG_C;
    u8 c = (u >> 7) & 1;

    context->regs.a = (u << 1) | cFlag;
    SetCPUFlags(context, 0, 0, 0, c);
}

static void ProcRRA(CPUContext *context)
{
    u8 carry = CPU_FLAG_C;
    u8 newCarry = context->regs.a & 1;

    context->regs.a >>= 1;
    context->regs.a |= (carry << 7);

    SetCPUFlags(context, 0, 0, 0, newCarry);
}

static void ProcDAA(CPUContext *context)
{
    u8 u = 0;
    int fc = 0;

    if (CPU_FLAG_H || (!CPU_FLAG_N && (context->regs.a & 0xF) > 9)) // H Flag is set and NOT N flag AND the (A register AND the last bit of reg A) is greater than 9 
    {
        u = 6;
    }

    if (CPU_FLAG_C || (!CPU_FLAG_N && context->regs.a > 0x99)) 
    {
        u |= 0x60;
        fc = 1;
    }

    context->regs.a += CPU_FLAG_N ? -u : u;

    SetCPUFlags(context, context->regs.a == 0, -1, 0, fc);
}

static void ProcCPL(CPUContext *context)
{
    context->regs.a = ~context->regs.a;
    SetCPUFlags(context, -1, 1, 1, -1);
}

static void ProcSCF(CPUContext *context)
{
    SetCPUFlags(context, -1, 0, 0, -1);
}

static void ProcCCF(CPUContext *context)
{
    SetCPUFlags(context, -1, 0, 0, CPU_FLAG_C ^ 1);
}

static void ProcHalt(CPUContext *context) 
{
    fprintf(stderr, "STOPPING!\n");
    NO_IMPL
}

static void ProcStop(CPUContext *context) 
{
    context->halted = true;
}

static void ProcAnd(CPUContext *context)
{
    context->regs.a &= context->fetchData; 
    SetCPUFlags(context, context->regs.a == 0, 0, 1, 0);
}

static void ProcXor(CPUContext *context)
{
    // ^= is XOR and =
    context->regs.a ^= context->fetchData & 0xFF; //0xFF because we only need the last byte of fetchData
    SetCPUFlags(context, context->regs.a == 0, 0, 0, 0);
}

static void ProcOr(CPUContext *context)
{
    context->regs.a |= context->fetchData & 0xFF; 
    SetCPUFlags(context, context->regs.a == 0, 0, 0, 0);
}

static void ProcCp(CPUContext *context)
{
    int n = (int)context->regs.a - (int)context->fetchData;

    SetCPUFlags(context, n == 0, 1, ((int)context->regs.a & 0x0F) - ((int)context->fetchData & 0x0F) < 0, n < 0);
}

static void ProcDi(CPUContext *context)
{
    context->masterInterruptEnabled = false; //disabling interrupts 
}

static bool Is16Bit(registerType rt) //checks if register is 16 bit 
{
    return rt >= RT_AF;
}

static void ProcLd(CPUContext *context)
{
    if (context->destinationIsMem) // if the context is in memory
    {
        if (Is16Bit(context->curInstruction->reg2)) // if it is a 16 bit register
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

static void GoToAddress(CPUContext *context, u16 address, bool PushPc) //generic jump code function. takes a context, an address, and a boolean checking whether the progCounter needs to be pushed
{
    if (CheckCond(context))
    {
        if (PushPc) //if pushpc is met
        {
            EMUCycles(2);
            PushStack16Bit(context->regs.progCounter); //pushes program counter
        }

        context->regs.progCounter = address; //if check passes, then we will jump. We do this by setting the context prog counter to the context's fetch data
        EMUCycles(1);//syncing PPU and Timer
    }    
}

static void ProcJp(CPUContext *context) //jump process
{
    GoToAddress(context, context->fetchData, false);
}

static void ProcJR(CPUContext *context) //jump relative process
{
    char relative = (char)(context->fetchData & 0xFF); //since the first byte in the u16 data may be negative
    u16 address = context->regs.progCounter + relative; //we set teh address to the progCounter + relative. RElative could be negative or positive
    GoToAddress(context, address, false);
}

static void ProcCall(CPUContext *context) // call process
{
    GoToAddress(context, context->fetchData, true);
}

static void ProcRST(CPUContext *context) // RST process
{
    GoToAddress(context, context->curInstruction->param, true);
}

static void ProcRet(CPUContext *context) //Return function
{
    if (context->curInstruction->cond != CT_NONE) //if check type if not NONE
    {
        EMUCycles(1);

    }

    if (CheckCond(context)) //if Cond is met
    {
       u16 low = PopStack();
       EMUCycles(1); 
       u16 high = PopStack();
       EMUCycles(1); 

       u16 n = (high << 8) | low;
       context->regs.progCounter = n;
       EMUCycles(1);
    }
}

static void ProcRetI(CPUContext *context) //Return function, but this returns from an Interrupt
{
    context->masterInterruptEnabled = true;
    ProcRet(context);
}

static void ProcPop(CPUContext *context) //stack pop process
{
    u16 low = PopStack(); //popping low value
    EMUCycles(1); //syncing
    u16 high = PopStack(); //popping high value
    EMUCycles(1);

    u16 n = (high << 8) | low;

    CPUSetReg(context->curInstruction->reg1, n); //setting the n value to the context's register #1

    if (context->curInstruction->reg1 == RT_AF) //if reg1 is AF
    {
        CPUSetReg(context->curInstruction->reg1, n & 0xFFF0); //only setting the reg1 to the bottom 1 1/2 bytes
    }
}

static void ProcPush(CPUContext *context) // stack push process
{
    u16 high = (CPUReadReg(context->curInstruction->reg1) >> 8) & 0xFF; //read reg1, shift to the right by 8, and grab the first byte
    EMUCycles(1);
    PushStack(high); //push value grabbed above

    u16 low = (CPUReadReg(context->curInstruction->reg2)) & 0xFF; //read reg1, grab low byte
    EMUCycles(1);
    PushStack(low); //push value grabbed above   

    EMUCycles(1); 

}

static void ProcInc(CPUContext *context) //increment function
{
    u16 value = CPUReadReg(context->curInstruction->reg1) + 1; //increment current reg by 1

    if (Is16Bit(context->curInstruction->reg1)) //if reg1 is 16 bit
    {
        EMUCycles(1);
    }

    if (context->curInstruction->reg1 == RT_HL && context->curInstruction->mode == AM_MR)
    {
        value = ReadBus(CPUReadReg(RT_HL)) + 1; //set value to the RT_HL reg + 1
        value &= 0xFF;
        WriteBus(CPUReadReg(RT_HL), value); //write bus to the value
    }
    else
    {
        CPUSetReg(context->curInstruction->reg1, value);
        value = CPUReadReg(context->curInstruction->reg1);
    }

    if ((context->currentOpCode & 0x03) == 0x03)
    {
        return;
    }

    SetCPUFlags(context, value == 0, 0, (value & 0x0F) == 0, -1);
}

static void ProcDec(CPUContext *context) //decrement function
{
    u16 value = CPUReadReg(context->curInstruction->reg1) - 1; //decrement current reg by 1

    if (Is16Bit(context->curInstruction->reg1)) //if reg1 is 16 bit
    {
        EMUCycles(1);
    }

    if (context->curInstruction->reg1 == RT_HL && context->curInstruction->mode == AM_MR)
    {
        value = ReadBus(CPUReadReg(RT_HL)) - 1; //set value to the RT_HL reg + 1
        WriteBus(CPUReadReg(RT_HL), value); //write bus to the value
    }
    else
    {
        CPUSetReg(context->curInstruction->reg1, value);
        value = CPUReadReg(context->curInstruction->reg1);
    }

    if ((context->currentOpCode & 0x0B) == 0x0B)
    {
        return;
    }

    SetCPUFlags(context, value == 0, 1, (value & 0x0F) == 0x0F, -1);
}

static void ProcSub(CPUContext *context) //subtraction function
{
    u16 value = CPUReadReg(context->curInstruction->reg1) - context->fetchData;

    int z = value == 0;
    int h = ((int)CPUReadReg(context->curInstruction->reg1) & 0xF) - (context->fetchData & 0xF) < 0;
    int c = ((int)CPUReadReg(context->curInstruction->reg1)) - (context->fetchData & 0xF) < 0;

    CPUSetReg(context->curInstruction->reg1, value);
    SetCPUFlags(context, z, 1, h, c);
}

static void ProcSbc(CPUContext *context)
{
    u8 value = context->fetchData + CPU_FLAG_C;

    int z = CPUReadReg(context->curInstruction->reg1) - value == 0;
    int h = ((int)CPUReadReg(context->curInstruction->reg1) & 0xF) - (context->fetchData & 0xF) - ((int)CPU_FLAG_C) < 0;
    int c = ((int)CPUReadReg(context->curInstruction->reg1)) - (context->fetchData & 0xF) - ((int)CPU_FLAG_C) < 0;

    CPUSetReg(context->curInstruction->reg1, CPUReadReg(context->curInstruction->reg1) - value);
    SetCPUFlags(context, z, 1, h, c);
}

static void ProcAdc(CPUContext *context)
{
    u16 u = context->fetchData;
    u16 a = context->regs.a;
    u16 c = CPU_FLAG_C;

    context->regs.a = (a + u + c);

    SetCPUFlags(context, context->regs.a == 0, 0, (a & 0xF) + (u & 0xF) + c > 0xF, a + u + c > 0xFF);
}

static void ProcAdd(CPUContext *context) //Addition function
{
    u32 value = CPUReadReg(context->curInstruction->reg1) + context->fetchData; //Read the value of reg 1 and add the value of fetchData

    bool is16Bit = Is16Bit(context->curInstruction->reg1);

    if (is16Bit)
    {
        EMUCycles(1);
    }

    if (context->curInstruction->reg1 == RT_SP) // if reg1 is stack pointer
    {
        value = CPUReadReg(context->curInstruction->reg1) + (char)context->fetchData; //set value to reg1 + fetchData
    }

    //handling 8 bit isntructions
    int z = (value & 0x0FF) == 0;  
    int h = (CPUReadReg(context->curInstruction->reg1) & 0xF) + (context->fetchData & 0xF) >= 0x10;
    int c = (int)(CPUReadReg(context->curInstruction->reg1) & 0xFF) + (int)(context->fetchData & 0xFF) >= 0x100;

    if (is16Bit) //handling 16 bit instructions
    {
        z = -1; 
        h = (CPUReadReg(context->curInstruction->reg1) & 0xFFF) + (context->fetchData & 0xFFF) >= 0x1000; 
        u32 n = ((u32)CPUReadReg(context->curInstruction->reg1)) + ((u32)context->fetchData);
        c = n >= 0x10000;
    }

    if (context->curInstruction->reg1 == RT_SP) //if reg1 is stack pointer
    {
        z = 0;
        h = (CPUReadReg(context->curInstruction->reg1) & 0xF) + (int)(context->fetchData & 0xF) >= 0x10;
        c = (int)(CPUReadReg(context->curInstruction->reg1) & 0xFF) + (int)(context->fetchData & 0xFF) >= 0x100;
    }

    CPUSetReg(context->curInstruction->reg1, value & 0xFFFF);
    SetCPUFlags(context, z, 0, h, c);
}




static IN_PROC processors[] = { //mapping opCodes to processor functionality methods
    [IN_NONE] = ProcNone,
    [IN_NOP] = ProcNoOp,
    [IN_LD] = ProcLd,
    [IN_LDH] = ProcLDH,
    [IN_JP] = ProcJp,
    [IN_DI] = ProcDi,
    [IN_POP] = ProcPop,
    [IN_PUSH] = ProcPush,
    [IN_JR] = ProcJR,
    [IN_CALL] = ProcCall,
    [IN_RET] = ProcRet,
    [IN_RST] = ProcRST,
    [IN_DEC] = ProcDec,
    [IN_INC] = ProcInc,
    [IN_ADD] = ProcAdd,
    [IN_ADC] = ProcAdc,
    [IN_SUB] = ProcSub,
    [IN_SBC] = ProcSbc,
    [IN_AND] = ProcAnd,
    [IN_OR] = ProcOr,
    [IN_CP] = ProcCp,
    [IN_CB] = ProcCb,
    [IN_RETI] = ProcRetI,
    [IN_RRCA] = ProcRRCA,
    [IN_RRA] = ProcRRA,
    [IN_RLCA] = ProcRLCA,
    [IN_RLA] = ProcRLA,
    [IN_STOP] = ProcStop,
    [IN_HALT] = ProcHalt,
    [IN_DAA] = ProcDAA,
    [IN_CPL] = ProcCPL,
    [IN_SCF] = ProcSCF,
    [IN_CCF] = ProcCCF,
    [IN_XOR] = ProcXor,

};

IN_PROC InstGetProcessor(instrucType type)
{
    return processors[type]; //returns the processor type that is mapped above
}