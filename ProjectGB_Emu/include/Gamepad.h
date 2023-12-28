#pragma once

#include <Common.h>

typedef struct { //struct for buttons
    bool start;
    bool select;
    bool a;
    bool b;
    bool up;
    bool down; 
    bool left;
    bool right;
} GamePadState;

void InitializeGamepad();
bool GamepadButtonSelect();
bool GamepadDirSelect();
void GamepadSetSelect(u8 value);

GamePadState *GetGamepadState();
u8 GamepadGetOutput();