#include "libc/stdio.h"
#include "arch/pe.h"
#include "fs/fs.h"
#include "shell.h"



void start() {
  printf("[ccg] Hello World!\n");

	// Get current execution level
  uint8_t pe_mode = get_mode();
  if(pe_mode == 0){
		printf("[ccg] CCG is in user mode..\n");
	} else printf("[ccg] CCG is in %s mode..\n", pe_modes[pe_mode]);

	// RW temporary filesystem
	printf("[fs] initializing tmpfs...");
	globl_tmpfs = init_fs();
	printf("done!\n");

  // TODO: devicetree...?

	// Small little shell.
	// TODO: Write a PL111 / better video driver so I don't have to use
	// serial, but for now serial is pretty neat.

	char buffer[256] = { 0 }; uint8_t index = 0;
	while(1){
		char c = uart0_getc();
		switch(c){
			case ENTER:
				printf("\n[uart]: buf is \"%s\"\n", buffer);

				// Get the parameter for the buffer
				shell_call_t p = get_param(buffer);
				if(p.params[0] != 0){
					printf("[shell] p->buffer = \"%s\"\n", p.params);
				
					char caller[20];
					for(int i = 0; buffer[i] != ' '; i++) {
						if(i >= 20){
							strcpy(caller, buffer);
							break;
						}
						caller[i] = buffer[i];
					}
					printf("[shell] p->caller = \"%s\"\n", caller);

					// TODO: fix this, and actually look up the caller
				}
				memset(buffer, 0, 256); // clear buffer
				index = 0;						  // reset index counter.
				break;
			// TODO: more special characters

			default:
				putc(c);
				buffer[index++] = c;
				break;
		}
	}
	
	for(;;);
}
