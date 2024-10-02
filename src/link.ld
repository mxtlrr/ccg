ENTRY(_start)

SECTIONS {
  /* Load exception handlers at 0x000. Should be right. */
  . = 0x000;
  .exceptions : { *(.exceptions) }

  /* Kernel code in flash memory. */
  . = 0x80010000;
  .stub   : { obj/stub.o(.text) }
  .text   : { *(.text) }
  .rodata : { *(.rodata) }
  .data   : { *(.data) }
  .bss    : { *(.bss COMMON) }

  STACK_BASE = .;
  . += 0x10000;
  STACK_TOP = .;
}