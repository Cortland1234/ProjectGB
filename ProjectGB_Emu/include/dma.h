#pragma once

#include <Common.h>

//Direct Memory Access

void StartDMA(u8 start); 
void DMATick();

bool TransferringDMA(); 
