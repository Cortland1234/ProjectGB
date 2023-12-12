#include <Instructions.h>
#include <CPU.h>


instruction instructions[0x100] = { //Assembly instructions for GB CPU, found at meganesu.github.io/generate-gb-opcodes
    [0x00] = {IN_NOP, AM_IMP}, //NoOp code, implied address

    [0x05] = {IN_DEC, AM_R, RT_B}, //Decrement B, simple Register addressing mode, Register type B

    [0x0E] = {IN_LD, AM_R_D8, RT_C}, //Load from C register, D8 to register addressing mode, Register Type C

    [0xAF] = {IN_XOR, AM_R, RT_A}, //XOR code, simple register, register type A

    [0xC3] = {IN_JP, AM_D16}, //Jump code, D16 to register addressing mode

    [0xF3] = {IN_DI} //Disables Interrupts
};


instruction *InstructionByOpcode(u8 opcode)
{
   return &instructions[opcode]; //returning the address of the instructions at "opcode"
}

char *instrucLookup[] = { //table of instruction types
    "<NONE>",
    "NOP",
    "LD",
    "INC",
    "DEC",
    "RLCA",
    "ADD",
    "RRCA",
    "STOP",
    "RLA",
    "JR",
    "RRA",
    "DAA",
    "CPL",
    "SCF",
    "CCF",
    "HALT",
    "ADC",
    "SUB",
    "SBC",
    "AND",
    "XOR",
    "OR",
    "CP",
    "POP",
    "JP",
    "PUSH",
    "RET",
    "CB",
    "CALL",
    "RETI",
    "LDH",
    "JPHL",
    "DI",
    "EI",
    "RST",
    "IN_ERR",
    "IN_RLC", 
    "IN_RRC",
    "IN_RL", 
    "IN_RR",
    "IN_SLA", 
    "IN_SRA",
    "IN_SWAP", 
    "IN_SRL",
    "IN_BIT", 
    "IN_RES", 
    "IN_SET"
};

char *InstrucName(instrucType t) { //returns the instruction type as a string
    return instrucLookup[t];
}