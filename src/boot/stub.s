/* Vector table */
.section exceptions
_VectorTable:
  b .         /* 0x00: Reset vector */
  b .         /* 0x04: Undefined instruction */
  ldr pc, =svc_hdlr  /* 0x08: SVC (software), funny long jump */
  b .         /* 0x0C: Prefetch */
  b .         /* 0x10: Data abort */
  b .         /* 0x14: Reserved */
  b .         /* 0x18: IRQ */
  b .         /* 0x1C: FIQ */


.section .text
.global _start
_start:
  ldr sp, =STACK_TOP /* Setup stack, 1000 bytes (1kb) */
  bl start
1:
  b 1b
.size _start, . - _start

svc_hdlr:
  mrs r0, spsr
  stmdb sp!, {r0-r3, lr} /* Save caller-saved registers */

  bl __c_svc_hdlr

  ldmia sp!, {r0-r3, lr} /* Restore */
  subs pc, lr, #4
