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

.global _start
_start:
  ldr sp, =STACK_TOP /* Setup stack, 1000 bytes (1kb) */

  /* Enforce running in Supervisor mode. We don't know if
   * some hardware will do that for us. */
  mov r0, #MODE_SVC
  and r0, r0, #(0x1f)
  msr cpsr, r0

  bl start
1:
  b 1b
.size _start, . - _start
