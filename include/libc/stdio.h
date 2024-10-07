#pragma once

#include <stdint.h>
#include <stdarg.h>

#include "libc/string.h"

// UART stuff
#define UART0_BASE 0x1c090000
#define UART0DR    (*(volatile uint32_t*)(UART0_BASE     )) // data. 12 bits on read, 8 on write.
#define UART0RSR   (*(volatile uint32_t*)(UART0_BASE+0x04)) // recieve status register
#define UART0ECR   (*(volatile uint32_t*)(UART0_BASE+0x04)) // error clear reg, write only
#define UART0FR    (*(volatile uint32_t*)(UART0_BASE+0x18)) // flag register, read only
#define UART0CTRL  (*(volatile uint32_t*)(UART0_BASE+0x30)) // control register. r/w

// UART flag registers
enum UART_FLAG_REG_VAL {
  TXFF = (1<<4),    // Bit set when buffer is full.
  RXFE = (1<<5)     // Bit set when buffer is empty
};

void putc(char c);
void puts(char* fmt);
void put_hex(uint32_t num);

void printf(char* fmt, ...);