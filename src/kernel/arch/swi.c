#include "arch/swi.h"


void swi_handler(uint32_t r0, uint32_t r1, uint32_t r2,
                uint32_t r3){
	// Get interrupt vector number
	uint8_t int_vector = 0;
	__asm__("ldrb %0, [lr, #-4]" : "=r" (int_vector));


  printf("[sys] I recieved SWI. Vector is %x (r0: %x, r1: %x r2: %x, r3: %x)\n", int_vector,
			r0, r1, r2, r3);

	// TODO: something...
	switch(int_vector){
		case TMPFS_VEC:
			switch(r0){
				case FS_READ_FILE:
					fs_node_t file = tmpfs_readfile(r1);
					// Don't care about the permissions, it's either
					// readonly or read/write
					puts(file.buffer);
					break;
			}
			break;
		default:
			printf("[sys] Unknown vector!\n");
			break;
	}
}