#include "arch/swi.h"


void swi_handler(uint32_t r0, uint32_t r1, uint32_t r2,
                uint32_t r3){
	// Get interrupt vector number
	uint8_t int_vector = 0;
	asm("ldrb %0, [lr, #-2]" : "=r" (int_vector));


  printf("[SWI] I recieved SWI. Vector is %x | ", int_vector);
  printf("Register dump:\n");
	printf("[SWI] r0: %x | r1: %x | r2: %x | r3: %x\n", r0, r1, r2, r3);

	// TODO: something...
}