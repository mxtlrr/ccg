#include "libc/stdio.h"
#include "arch/pe.h"

void start() {
  puts("Hello, World!\n");
  
  /* Get processing element (PE) mode - the processor mode */
  uint8_t pe_mode = get_mode();
  printf("[debug] PE mode is %x\n", pe_mode);
}