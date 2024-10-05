#include "libc/stdio.h"
#include "arch/pe.h"

void start() {
  printf("[ccg] Hello World!\n");

	// Get current execution level
  uint8_t pe_mode = get_mode();
  if(pe_mode == 0){
		printf("[ccg] CCG is in user mode..\n");
	} else printf("[ccg] CCG is in %s mode..\n", pe_modes[pe_mode]);


  // TODO: devicetree...
}
