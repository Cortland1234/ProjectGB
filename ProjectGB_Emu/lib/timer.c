#include <Timer.h>
#include <Interrupts.h>

static TimerContext context = {0};

TimerContext *GetTimerContext()
{
    return &context;
}

void InitializeTimer()
{
    context.div = 0xAC00;
}

void TimerTick() 
{
    u16 prevDiv = context.div;

    context.div++;

    bool timerUpdate = false;

    switch(context.tac & (0b11))
    {
        case 0b00:
            timerUpdate = (prevDiv & (1 << 9)) && (!(context.div & (1 << 9)));
            break;
        case 0b01:
            timerUpdate = (prevDiv & (1 << 3)) && (!(context.div & (1 << 3)));
            break;
        case 0b10:
            timerUpdate = (prevDiv & (1 << 5)) && (!(context.div & (1 << 5)));
            break;
        case 0b11:
            timerUpdate = (prevDiv & (1 << 7)) && (!(context.div & (1 << 7)));
            break; 
    }

    if (timerUpdate && context.tac & (1 << 2)) {
        context.tima++;

        if (context.tima == 0xFF) {
            context.tima = context.tma;

            RequestCPUInterrupts(IT_TIMER);
        }    
    }
}

void WriteTimer(u16 address, u8 value)
{
    switch (address)
    {
    case 0xFF04:
        context.div = 0; //if address is 0xFF04, div is reset to 0
        break;
    case 0xFF05:
        context.tima = value; 
        break; 
    case 0xFF06:
        context.tima = value; 
        break;
    case 0xFF07:
        context.tima = value; 
        break;   
    default:
        break;
    }
}

u8 ReadTimer(u16 address)
{
    switch (address)
    {
    case 0xFF04:
        return context.div >> 8;
    case 0xFF05:
        return context.tima; 
    case 0xFF06:
        return context.tma;
    case 0xFF07:
        return context.tac;
    }    
}