#include <Debug.h>
#include <Bus.h>

static char dbg_msg[1024] = {0};
static int msg_size = 0;

void DebugUpdate() 
{
    if (ReadBus(0xFF02) == 0x81) 
    {
        char c = ReadBus(0xFF01);

        dbg_msg[msg_size++] = c;

        WriteBus(0xFF02, 0); //reset the flags to prevent reading the same char over and over
    }
}

void DebugPrint() //printing debug info if needed
{
    if (dbg_msg[0]) 
    {
        printf("DBG: %s\n", dbg_msg);
    }
}
