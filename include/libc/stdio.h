#pragma once

#include <stdint.h>
#include <stdarg.h>

#define UART0_BASE 0x1c090000

void putc(char c);
void puts(char* fmt);
void put_hex(uint32_t num);

void printf(char* fmt, ...);