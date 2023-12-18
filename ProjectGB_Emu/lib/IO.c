#include <IO.h>

static char serialData[2];

u8 ReadIO(u16 address)
{
    if (address == 0xFF01)
    {
        return serialData[0];
    }

    if (address == 0xFF02)
    {
        return serialData[1];
    }

    printf("UNSUPPORTED ReadBus(%04X)\n", address);
    return 0;
}

void WriteIO(u16 address, u8 value)
{
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

    printf("UNSUPPORTED WriteBus(%04X)\n", address);
}