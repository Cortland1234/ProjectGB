#pragma once

#include <Common.h>

//Defining instructions for CPU

typedef enum { //defines how data is loaded into a register
    AM_IMP,
    AM_R_D16, //D16 value to a register
    AM_R_R, //register to register 
    AM_MR_R, //register to the memory location OF a register 
    AM_R, //single register
    AM_R_D8,
    AM_R_MR,
    AM_R_HLI,
    AM_R_HLD,
    AM_HLI_R,
    AM_HLD_R,
    AM_R_A8,
    AM_A8_R,
    AM_HL_SPR,
    AM_D16,
    AM_D8,
    AM_D16_R,
    AM_MR_D8,
    AM_MR,
    AM_A16_R,
    AM_R_A16
} addressMode;

typedef enum { //Type of register
    RT_NONE, //No register needed
    //8 bit registers
    RT_A, 
    RT_F,
    RT_B,
    RT_C,
    RT_D,
    RT_E,
    RT_H,
    RT_L,
    //16 bit registers
    RT_AF,
    RT_BC,
    RT_DE,
    RT_HL,
    RT_SP,
    RT_PC
} registerType;

typedef enum { //instruction types for the CPU in Assembly. For example, if instruction is "LD C, d8" then it would load a value (d8) into a register (C).
    IN_NONE, //No instruction
    IN_NOP, //NoOpcode
    IN_LD, //Load
    IN_INC, //Increment
    IN_DEC, //Decrement
    IN_RLCA,
    IN_ADD,
    IN_RRCA,
    IN_STOP,
    IN_RLA,
    IN_JR,
    IN_RRA,
    IN_DAA,
    IN_CPL,
    IN_SCF,
    IN_CCF,
    IN_HALT,
    IN_ADC,
    IN_SUB,
    IN_SBC,
    IN_AND,
    IN_XOR,
    IN_OR,
    IN_CP,
    IN_POP,
    IN_JP, //Jump code
    IN_PUSH,
    IN_RET,
    IN_CB,
    IN_CALL,
    IN_RETI,
    IN_LDH,
    IN_JPHL,
    IN_DI,
    IN_EI,
    IN_RST,
    IN_ERR,
    //CB instructions...
    IN_RLC, 
    IN_RRC,
    IN_RL, 
    IN_RR,
    IN_SLA, 
    IN_SRA,
    IN_SWAP, 
    IN_SRL,
    IN_BIT, 
    IN_RES, 
    IN_SET
} instrucType;

typedef enum { //In most cases there will be no conditions in instructions, but some require it.
    CT_NONE, CT_NZ, CT_Z, CT_NC, CT_C //for example, NZ means if there is no Z Flag, NC means if there is no Carry flag, etc
} conditionType;

typedef struct {
    instrucType type; //type of Instruction
    addressMode mode; //Address's mode. fetches data depending on instruction type
    registerType reg1; //Possible Register #1
    registerType reg2; //Possible Register #2
    conditionType cond; //Possible Conditional statement
    u8 param; //Parameters
} instruction;

instruction *InstructionByOpcode(u8 opcode);

char *InstrucName(instrucType t);