#include <Instructions.h>
#include <CPU.h>


instruction instructions[0x100] = { //Assembly instructions for GB CPU, found at meganesu.github.io/generate-gb-opcodes
    [0x00] = {IN_NOP, AM_IMP}, //NoOp code, implied address

    [0x05] = {IN_DEC, AM_R, RT_B}, //Decrement B, simple Register addressing mode, Register type B

    [0x0E] = {IN_LD, AM_R_D8, RT_C}, //Load from C register, D8 to register addressing mode, Register Type C

    [0xAF] = {IN_XOR, AM_R, RT_A}, //XOR code, simple register, register type A

    [0xC3] = {IN_JP, AM_D16}, //Jump code, D16 to register addressing mode
};


instruction *instructionByOpcode(u8 opcode)
{
    if (instructions[opcode].type == IN_NONE) //if the opcode type is IN_NONE, then we know it's an error.
    {
        return NULL;
    }

   return &instructions[opcode]; //returning the address of the instructions at "opcode"
}