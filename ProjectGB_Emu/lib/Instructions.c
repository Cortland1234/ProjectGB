#include <Instructions.h>
#include <CPU.h>


instruction instructions[0x100] = { //Assembly instructions for GB CPU, found at meganesu.github.io/generate-gb-opcodes
    [0x00] = {IN_NOP, AM_IMP}, //NoOp code, implied address
    [0x01] = {IN_LD, AM_R_D16, RT_BC}, //Load from BC Register, D16 to Register addressing mode, register BC
    [0x02] = {IN_LD, AM_MR_R, RT_BC, RT_A}, //Load, Register to Memory addressing, Register types BC and A

    [0x05] = {IN_DEC, AM_R, RT_B}, //Decrement B, simple Register addressing mode, Register type B
    [0x06] = {IN_LD, AM_R_D8, RT_C}, //Load from C Register, D8 to register, register type C

    [0x08] = {IN_LD, AM_A16_R, RT_NONE, RT_SP}, //load, Register to A16 mode, register types NONE and SP

    [0x0A] = {IN_LD, AM_R_MR, RT_A, RT_BC},

    [0x0E] = {IN_LD, AM_R_D8, RT_C}, //Load from C register, D8 to register addressing mode, Register Type C

    //0x1X
    [0x11] = {IN_LD, AM_R_D16, RT_DE},
    [0x12] = {IN_LD, AM_MR_R, RT_DE, RT_A},
    [0x15] = {IN_DEC, AM_R, RT_D},
    [0x16] = {IN_LD, AM_R_D8, RT_D},
    [0x18] = {IN_JR, AM_D8},
    [0x1A] = {IN_LD, AM_R_MR, RT_A, RT_DE},
    [0x1E] = {IN_LD, AM_R_D8, RT_E},

    //0x2X
    [0x20] = {IN_JR, AM_D8, RT_NONE, RT_NONE, CT_NZ},
    [0x21] = {IN_LD, AM_R_D16, RT_HL},
    [0x22] = {IN_LD, AM_HLI_R, RT_HL, RT_A},
    [0x25] = {IN_DEC, AM_R, RT_H},
    [0x26] = {IN_LD, AM_R_D8, RT_H},
    [0x28] = {IN_JR, AM_D8, RT_NONE, RT_NONE, CT_Z},
    [0x2A] = {IN_LD, AM_R_HLI, RT_A, RT_HL},
    [0x2E] = {IN_LD, AM_R_D8, RT_L},

    //0x3X
    [0x30] = {IN_JR, AM_D8, RT_NONE, RT_NONE, CT_NC},
    [0x31] = {IN_LD, AM_R_D16, RT_SP},
    [0x32] = {IN_LD, AM_HLD_R, RT_HL, RT_A},
    [0x35] = {IN_DEC, AM_R, RT_HL},
    [0x36] = {IN_LD, AM_MR_D8, RT_HL},
    [0x38] = {IN_JR, AM_D8, RT_NONE, RT_NONE, CT_C},
    [0x3A] = {IN_LD, AM_R_HLD, RT_A, RT_HL},
    [0x3E] = {IN_LD, AM_R_D8, RT_A},

    //0x4X
    [0x40] = {IN_LD, AM_R_R, RT_B, RT_B},
    [0x41] = {IN_LD, AM_R_R, RT_B, RT_C},
    [0x42] = {IN_LD, AM_R_R, RT_B, RT_D},
    [0x43] = {IN_LD, AM_R_R, RT_B, RT_E},
    [0x44] = {IN_LD, AM_R_R, RT_B, RT_H},
    [0x45] = {IN_LD, AM_R_R, RT_B, RT_L},
    [0x46] = {IN_LD, AM_R_MR, RT_B, RT_HL},
    [0x47] = {IN_LD, AM_R_R, RT_B, RT_A},
    [0x48] = {IN_LD, AM_R_R, RT_C, RT_B},
    [0x49] = {IN_LD, AM_R_R, RT_C, RT_C},
    [0x4A] = {IN_LD, AM_R_R, RT_C, RT_D},
    [0x4B] = {IN_LD, AM_R_R, RT_C, RT_E},
    [0x4C] = {IN_LD, AM_R_R, RT_C, RT_H},
    [0x4D] = {IN_LD, AM_R_R, RT_C, RT_L},
    [0x4E] = {IN_LD, AM_R_MR, RT_C, RT_HL},
    [0x4F] = {IN_LD, AM_R_R, RT_C, RT_A},

    //0x5X
    [0x50] = {IN_LD, AM_R_R,  RT_D, RT_B},
    [0x51] = {IN_LD, AM_R_R,  RT_D, RT_C},
    [0x52] = {IN_LD, AM_R_R,  RT_D, RT_D},
    [0x53] = {IN_LD, AM_R_R,  RT_D, RT_E},
    [0x54] = {IN_LD, AM_R_R,  RT_D, RT_H},
    [0x55] = {IN_LD, AM_R_R,  RT_D, RT_L},
    [0x56] = {IN_LD, AM_R_MR, RT_D, RT_HL},
    [0x57] = {IN_LD, AM_R_R,  RT_D, RT_A},
    [0x58] = {IN_LD, AM_R_R,  RT_E, RT_B},
    [0x59] = {IN_LD, AM_R_R,  RT_E, RT_C},
    [0x5A] = {IN_LD, AM_R_R,  RT_E, RT_D},
    [0x5B] = {IN_LD, AM_R_R,  RT_E, RT_E},
    [0x5C] = {IN_LD, AM_R_R,  RT_E, RT_H},
    [0x5D] = {IN_LD, AM_R_R,  RT_E, RT_L},
    [0x5E] = {IN_LD, AM_R_MR, RT_E, RT_HL},
    [0x5F] = {IN_LD, AM_R_R,  RT_E, RT_A},

    //0x6X
    [0x60] = {IN_LD, AM_R_R,  RT_H, RT_B},
    [0x61] = {IN_LD, AM_R_R,  RT_H, RT_C},
    [0x62] = {IN_LD, AM_R_R,  RT_H, RT_D},
    [0x63] = {IN_LD, AM_R_R,  RT_H, RT_E},
    [0x64] = {IN_LD, AM_R_R,  RT_H, RT_H},
    [0x65] = {IN_LD, AM_R_R,  RT_H, RT_L},
    [0x66] = {IN_LD, AM_R_MR, RT_H, RT_HL},
    [0x67] = {IN_LD, AM_R_R,  RT_H, RT_A},
    [0x68] = {IN_LD, AM_R_R,  RT_L, RT_B},
    [0x69] = {IN_LD, AM_R_R,  RT_L, RT_C},
    [0x6A] = {IN_LD, AM_R_R,  RT_L, RT_D},
    [0x6B] = {IN_LD, AM_R_R,  RT_L, RT_E},
    [0x6C] = {IN_LD, AM_R_R,  RT_L, RT_H},
    [0x6D] = {IN_LD, AM_R_R,  RT_L, RT_L},
    [0x6E] = {IN_LD, AM_R_MR, RT_L, RT_HL},
    [0x6F] = {IN_LD, AM_R_R,  RT_L, RT_A},

    //0x7X
    [0x70] = {IN_LD, AM_MR_R,  RT_HL, RT_B},
    [0x71] = {IN_LD, AM_MR_R,  RT_HL, RT_C},
    [0x72] = {IN_LD, AM_MR_R,  RT_HL, RT_D},
    [0x73] = {IN_LD, AM_MR_R,  RT_HL, RT_E},
    [0x74] = {IN_LD, AM_MR_R,  RT_HL, RT_H},
    [0x75] = {IN_LD, AM_MR_R,  RT_HL, RT_L},
    [0x76] = {IN_HALT},
    [0x77] = {IN_LD, AM_MR_R,  RT_HL, RT_A},
    [0x78] = {IN_LD, AM_R_R,  RT_A, RT_B},
    [0x79] = {IN_LD, AM_R_R,  RT_A, RT_C},
    [0x7A] = {IN_LD, AM_R_R,  RT_A, RT_D},
    [0x7B] = {IN_LD, AM_R_R,  RT_A, RT_E},
    [0x7C] = {IN_LD, AM_R_R,  RT_A, RT_H},
    [0x7D] = {IN_LD, AM_R_R,  RT_A, RT_L},
    [0x7E] = {IN_LD, AM_R_MR, RT_A, RT_HL},
    [0x7F] = {IN_LD, AM_R_R,  RT_A, RT_A},

    [0xAF] = {IN_XOR, AM_R, RT_A}, //XOR code, simple register, register type A

    [0xC0] = {IN_RET, AM_IMP, RT_NONE, RT_NONE, CT_NZ}, //Return code, implied addressing mode, nonetype reg, check type non zero
    [0xC1] = {IN_POP, AM_IMP, RT_BC}, //Pop code, addressing mode is Implied, register is BC
    [0xC2] = {IN_JP, AM_D16, RT_NONE, RT_NONE, CT_NZ},
    [0xC3] = {IN_JP, AM_D16}, //Jump code, D16 to register addressing mode
    [0xC4] = {IN_CALL, AM_D16, RT_NONE, RT_NONE, CT_NZ}, //call code, D16 addressing mode, Register type None, and check type is Not Zero
    [0xC5] = {IN_PUSH, AM_R, RT_BC}, //Push code, simple register, register BC
    [0xC8] = {IN_RET, AM_IMP, RT_NONE, RT_NONE, CT_Z},
    [0xC9] = {IN_RET},
    [0xCA] = {IN_JP, AM_D16, RT_NONE, RT_NONE, CT_Z},
    [0xCC] = {IN_CALL, AM_D16, RT_NONE, RT_NONE, CT_Z},
    [0xCD] = {IN_CALL, AM_D16},

    [0xD0] = {IN_RET, AM_IMP, RT_NONE, RT_NONE, CT_NC},
    [0xD1] = {IN_POP, AM_R, RT_DE}, //Pop code, simple register, register DE
    [0xD2] = {IN_JP, AM_D16, RT_NONE, RT_NONE, CT_NC},
    [0xD4] = {IN_CALL, AM_D16, RT_NONE, RT_NONE, CT_NC},
    [0xD5] = {IN_PUSH, AM_R, RT_BC}, //Push code, simple register, register BC
    [0xD8] = {IN_RET, AM_IMP, RT_NONE, RT_NONE, CT_C},
    [0xD9] = {IN_RETI},
    [0xDA] = {IN_JP, AM_D16, RT_NONE, RT_NONE, CT_C},
    [0xDC] = {IN_CALL, AM_D16, RT_NONE, RT_NONE, CT_Z},

    //0xEX
    [0xE0] = {IN_LDH, AM_A8_R, RT_NONE, RT_A},
    [0xE1] = {IN_POP, AM_R, RT_HL}, //Pop code, simple register, register is HL
    [0xE2] = {IN_LD, AM_MR_R, RT_C, RT_A},
    [0xE5] = {IN_PUSH, AM_R, RT_HL}, //push code, simple reg, reg is HL
    [0xE9] = {IN_JP, AM_MR, RT_HL},
    [0xEA] = {IN_LD, AM_A16_R, RT_NONE, RT_A},

    //0xFX
    [0xF0] = {IN_LDH, AM_R_A8, RT_A},
    [0xF1] = {IN_POP, AM_R, RT_AF}, //Pop code, simple register, register is AF
    [0xF2] = {IN_LD, AM_R_MR, RT_A, RT_C},
    [0xF3] = {IN_DI}, //Disables Interrupts
    [0xF5] = {IN_PUSH, AM_R, RT_AF}, //push code, simple reg, reg is AF
    [0xFA] = {IN_LD, AM_R_A16, RT_A},
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