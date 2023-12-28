#include <IO.h>
#include <Dma.h>
#include <LCD.h>
#include <Timer.h>
#include <CPU.h>
#include <Gamepad.h>

static char serialData[2];

u8 ReadIO(u16 address) 
{
    if (address == 0xFF00)
    {
        return GamepadGetOutput();
    }
    if (address == 0xFF01) 
    {
        return serialData[0];
    }

    if (address == 0xFF02) 
    {
        return serialData[1];
    }

    if (BETWEEN(address, 0xFF04, 0xFF07)) 
    {
        return ReadTimer(address);
    }

    if (address == 0xFF0F) 
    {
        return GetCPUIntFlags();
    }

    if (BETWEEN(address, 0xFF10, 0xFF3F)) 
    {
        //ignoring sound for now
        return 0;
    }

    if (BETWEEN(address, 0xFF40, 0xFF4B)) 
    {
        return ReadLCD(address);
    }

    printf("UNSUPPORTED ReadBus(%04X)\n", address);
    return 0;
}

void WriteIO(u16 address, u8 value) 
{
    if (address == 0xFF00)
    {
        GamepadSetSelect(value);
        return;
    }
    if (address == 0xFF01) 
    {
        serialData[0] = value;
        return;
    }

    if (address == 0xFF02) 
    {
        serialData[1] = value;
        return;
    }

    if (BETWEEN(address, 0xFF04, 0xFF07)) 
    {
        WriteTimer(address, value);
        return;
    }
    
    if (address == 0xFF0F) 
    {
        SetCPUIntFlags(value);
        return;
    }

    if (BETWEEN(address, 0xFF10, 0xFF3F)) 
    {
        //ignoring sound for now
        return;
    }

    if (BETWEEN(address, 0xFF40, 0xFF4B)) 
    {
        WriteLCD(address, value);
        return;
    }

    printf("UNSUPPORTED WriteBus(%04X)\n", address);
}
