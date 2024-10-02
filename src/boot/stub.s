.global _start
_start:
  ldr sp, =STACK_TOP /* Setup stack, 1000 bytes (1kb) */
  bl start
1:
  b 1b
.size _start, . - _start
