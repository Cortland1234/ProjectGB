#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t u8; //8 bit data type
typedef uint16_t u16; //16 bit data type
typedef uint32_t u32; //32 bit data type
typedef uint64_t u64; //64 bit data type

#define BIT(a, n) ((a & (1 << n)) ? 1 : 0) //getting a bit

#define BIT_SET(a, n ,on) (on ? a |= (1 << n) : a &= ~(1 << n)) //setting a bit

#define BETWEEN(a, b, c) ((a >= b) && (a <= c)) //checks if a number is in between two values

void Delay(u32 ms);