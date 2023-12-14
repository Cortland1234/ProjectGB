#include <Ram.h>

typedef struct { // two types of ram
    u8 wram[0x2000];
    u8 hram[0x80];
} RamContext;

static RamContext context;

u8 ReadWRAM(u16 address) //subtracts address by 0xC000, Checks if address is valid WRAM, and then returns the address of the WRAM 
{
    address -= 0xC000; //WRAM starts at 0xC000, so we subtract it from the address

    if (address >= 0x2000)
    {
        printf("Address Out of Bounds for WRAM");
        exit(-1);
    }

    return context.wram[address];
}

void WriteWRAM(u16 address, u8 value) //again subtracts address by 0xC000, and then sets the context's WRAM address to the value param
{
    address -= 0xC000;

    context.wram[address] = value;
}

u8 ReadHRAM(u16 address) //subtracts address by 0xFF80, and then returns the address of the HRAM 
{
    address -= 0xFF80; //HRAM starts at 0xFF80, so we subtract it from the address

    return context.hram[address];
}

void WriteHRAM(u16 address, u8 value) //same as WriteWRAM()
{
    address -= 0xFF80;

    context.hram[address] = value;
}

