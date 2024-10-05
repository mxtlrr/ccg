#include "libc/stdio.h"


volatile int delay;
void putc(char c) {
  *(volatile uint32_t*)(UART0_BASE) = c;

  // This is really stupid. But it works.
  for (delay = 0; delay < 1; delay++);
}

void puts(char* fmt) {
  for (int i = 0; fmt[i] != '\0'; i++) putc(fmt[i]);
}

void put_hex(uint32_t num) {
  char* hex_digits = "0123456789abcdef";
  for (int i = 7; i >= 0; i--) {
    uint8_t nibble = (num >> (i * 4)) & 0xF;
    putc(hex_digits[nibble]);
  }
}

void printf(char* fmt, ...){
  va_list ap;
  va_start(ap, fmt);
  char* ptr;
  	for (ptr = fmt; *ptr != '\0'; ++ptr) {
		if (*ptr == '%') {
			++ptr;

      // Check through different control sequences
      switch(*ptr){
        case 's': // String
          puts(va_arg(ap, char*));
          break;

        case 'x':
          puts("0x");
          put_hex(va_arg(ap, uint32_t));
          break;
      }
    } else {
      putc(*ptr);
    }
  }
}

char uart0_getc(void){
  char c = 0;
  do {
    while ((UART0FR) & TXFF); // Poll flag register until buffer is empty
    c = (char)UART0DR;      // Read from the data register
  } while (c == 0);
  return c;
}