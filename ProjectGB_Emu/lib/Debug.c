#include <Debug.h>
#include <Bus.h>

static char debugMsg[1024] = {0};
static int msgSize = 0;


void DebugUpdate()
{
    if (ReadBus(0xFF02) == 0x81)
    {
        char c = ReadBus(0xFF01);

        debugMsg[msgSize++] = c;

        WriteBus(0xFF02, 0); //reset the flags to prevent reading the same char over and over
    }

}

void DebugPrint() //printing debug info if needed
{
    if (debugMsg[0])
    {
        printf("DBG: %s\n", debugMsg);
    }
}