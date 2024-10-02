#pragma once

#include <stdint.h>
#define UART0_BASE 0x1c090000

void putc(char c);
void puts(char* fmt);