#include <Bus.h>
#include <Cartridge.h>
#include <Ram.h>
#include <Cpu.h>
#include <IO.h>

//Pasted below are the Memory Maps
//For each section of the memory that you want to access, it will go to different peripherals listed below

// 0x0000 - 0x3FFF : ROM Bank 0
// 0x4000 - 0x7FFF : ROM Bank 1 - Switchable
// 0x8000 - 0x97FF : CHR RAM
// 0x9800 - 0x9BFF : BG Map 1
// 0x9C00 - 0x9FFF : BG Map 2
// 0xA000 - 0xBFFF : Cartridge RAM
// 0xC000 - 0xCFFF : RAM Bank 0
// 0xD000 - 0xDFFF : RAM Bank 1-7 - switchable - Color only
// 0xE000 - 0xFDFF : Reserved - Echo RAM
// 0xFE00 - 0xFE9F : Object Attribute Memory
// 0xFEA0 - 0xFEFF : Reserved - Unusable
// 0xFF00 - 0xFF7F : I/O Registers
// 0xFF80 - 0xFFFE : Zero Page

u8 ReadBus(u16 address)
{
    if (address < 0x8000) // if the address is less than 0x8000 (so the rom data banks above), then it will return readCartidge at that address
    {
        return ReadCartridge(address);
    }
    else if (address < 0xA000) //if address is less than 0xA000 (which is the Char/Map data),  
    {
        printf("UNSUPPORTED ReadBus(%04X)\n", address);
        NO_IMPL
    }

    else if (address < 0xC000) // if the address is less than 0xC000 (which is the Cartridge RAM), then it will return ReadCartridge at that address
    {
        return ReadCartridge(address);
    }

    else if (address < 0xE000) // < 0xE000 is the working RAM, or switchable ram banks. Returns ReadWRAM at that address
    {
        return ReadWRAM(address);
    }

    else if (address < 0xFE00) // < 0xFE00 is the reserved/echo RAM. we will not need it so return 0.
    {
        return 0;
    }

    else if (address < 0xFEA0) // Object Attribute Memory
    {
        printf("UNSUPPORTED ReadBus(%04X)\n", address);
        return 0x0;
    }

    else if (address < 0xFF00) // Another unusable reserved RAM section, returns 0.
    {
        return 0;
    } 

    else if (address < 0xFF80) // I/O Registers
    {
        
        return ReadIO(address);
    }

    else if (address == 0xFFFF) //CPU Enable Register
    {
        return GetCPUIERegister();
    }
    
    return ReadHRAM(address);
    
}

void WriteBus(u16 address, u8 value)
{
    if (address < 0x8000) //ROM data banks
    {
        WriteCartridge(address, value);
    }

    else if (address < 0xA000) // Char/Map Data
    {
        printf("UNSUPPORTED WriteBus(%04X)\n", address);
        //NO_IMPL 
    }

    else if (address < 0xC000) // Cartridge RAM (AKA EXT RAM)
    {
        WriteCartridge(address, value);
    }

    else if (address < 0xE000) //WRAM
    {
        WriteWRAM(address, value);
    }

    else if (address < 0xFE00) //Echo RAM / reserved RAM
    {

    }

    else if (address < 0xFEA0) //Object Attribute Memory
    {
        printf("Hello UNSUPPORTED WriteBus(%04X)\n", address);
        //NO_IMPL
    }

    else if (address < 0xFF00) // Unusable/reserved RAM section
    {

    }

    else if (address < 0xFF80) // I/O Registers
    {
        return WriteIO(address, value);
    }

    else if (address == 0xFFFF) //CPU Enable Register
    {
        SetCPUIERegister(value);
    }
    else
    {
        WriteHRAM(address, value);
    }
    
}

u16 ReadBus16Bit(u16 address)
{
    u16 low = ReadBus(address); //reads low byte of 16bit
    u16 high = ReadBus(address + 1); //reads the high bit of 16bit

    return low | (high << 8); //returns the low byte OR the high byte shifted 8 to the left
}

void WriteBus16Bit(u16 address, u16 value)
{
    WriteBus(address + 1, (value >> 8) & 0xFF); //writes the high byte by going to the high byte, shifting the value 8 to the right
    WriteBus(address, value & 0xFF); //writes the low byte
}

