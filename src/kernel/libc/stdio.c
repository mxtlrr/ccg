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