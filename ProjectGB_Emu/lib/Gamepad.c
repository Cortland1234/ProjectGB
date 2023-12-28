#include <Gamepad.h>
#include <string.h>

typedef struct {
    bool buttonSelect; //buttons
    bool dirSelect; // direction buttons

    GamePadState controller;
} GamepadContext;

static GamepadContext context = {0};

bool GamepadButtonSelect() //returns the button the user has selected
{
    return context.buttonSelect;
}

bool GamepadDirSelect()
{
    return context.dirSelect;
}

void GamepadSetSelect(u8 value)
{
    context.buttonSelect = value & 0x20; //if 0x20 is set, then we know a button was selected
    context.dirSelect = value & 0x10; //if 0x10 is set, we know a direction was selected
}

GamePadState *GetGamepadState()
{
    return &context.controller;
}

u8 GamepadGetOutput() //getting which button was selected
{
    u8 output = 0xCF; 

    if (!GamepadButtonSelect()) //buttons
    {
        if (GetGamepadState()->start)
        {
            output &= ~(1 << 3);
        }
        if (GetGamepadState()->select)
        {
            output &= ~(1 << 2);
        }
        if (GetGamepadState()->a)
        {
            output &= ~(1 << 0);
        }
        if (GetGamepadState()->b)
        {
            output &= ~(1 << 1);
        }            
    }

    if (!GamepadDirSelect()) //direction buttons
    {
        if (GetGamepadState()->left)
        {
            output &= ~(1 << 1);
        }
        if (GetGamepadState()->right)
        {
            output &= ~(1 << 0);
        }
        if (GetGamepadState()->up)
        {
            output &= ~(1 << 2);
        }
        if (GetGamepadState()->down)
        {
            output &= ~(1 << 3);
        }        
    }

    return output;
}