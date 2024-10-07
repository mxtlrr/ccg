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
				// TODO: instead of writing to stdout, we should write it
				// to the buffer provided (this might just be kinda stupid).
				case FS_READ_FILE:
					fs_node_t file = tmpfs_readfile(r1);
					// Don't care about the permissions, it's either
					// readonly or read/write
					puts(file.buffer);
					break;
				case FS_WRITE_FILE:
					fs_node_t file_w = tmpfs_readfile(r1);
					if(file_w.permissions != PERMISSION_READWRITE){
						printf("[sys] File is not writeable. I can't do anything.\n");
						break;
					}

					// when we load the buffer into the register with ldr,
					// it's just the mem location. so read the physical bytes
					uint32_t mem_location = r2; uint32_t length = r3;
					char buffer[length];
					printf("[sys] reading %d bytes to node %x\n", r3, r1);
					for(uint32_t i = 0; i < length; i++){
						buffer[i] = *(uint8_t*)(mem_location+i);
					}

					// copy buffer to the nodes buffer
					// FIXME/TODO: this is gross. fix please!!
					strcpy(globl_tmpfs.nodes[r1].buffer, buffer);
					break;
			}
			break;
		default:
			printf("[sys] Unknown vector!\n");
			break;
	}
}