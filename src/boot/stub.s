/* Vector table, loaded at 0xFFFF0000 */
.section .exceptions,"a"
_VectorTable:
  b .         /* 0x00: Reset vector */
  b .         /* 0x04: Undefined instruction */
  ldr pc, =swi_handler/* 0x08: SVC (software), funny long jump */
  b .         /* 0x0C: Prefetch */
  b .         /* 0x10: Data abort */
  b .         /* 0x14: Reserved */
  b .         /* 0x18: IRQ */
  b .         /* 0x1C: FIQ */

.section .text

.set MODE_USR, 0x10
.set MODE_FIQ, 0x11
.set MODE_IRQ, 0x12
.set MODE_SVC, 0x13
.set MODE_MON, 0x16
.set MODE_ABT, 0x17
.set MODE_UND, 0x1B
.set MODE_SYS, 0x1F

.set NO_PAGING, 0b0000

.global _start
_start:
  ldr sp, =STACK_TOP /* Setup stack, 1000 bytes (1kb) */

  /* Enforce running in Supervisor mode. We don't know if
   * some hardware will do that for us. */
  mov r0, #MODE_SVC
  and r0, r0, #(0x1f)
  msr cpsr, r0

  // Setup page tables/paging

  /// Check if paging is supported.
  mrc p15, 0, r1, c1, c0, 0
  and r1, r1, #0xF
  cmp r1, #NO_PAGING
  beq .

  /// Paging is supported for this board!
  // Enable EL0/User mode

	// Set up user stack
	movw r0, #0x2000
	movt r0, #0x8002 // Weirdly can't load 32-bit vals into registers.
									 // oh well.
	msr sp_usr, r0

  cps #MODE_USR
  bl start
1:
  b 1b
.size _start, . - _start
