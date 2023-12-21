#pragma once

#include <Common.h>

void StartDMA(u8 start);
void DMATick();

bool TransferringDMA();
