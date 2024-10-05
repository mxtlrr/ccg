OUTPUT_FORMAT(elf32-littlearm)
ENTRY(_start)

/* This should be loaded first */
STARTUP(obj/stub.o)

SECTIONS {
  /* Kernel code in flash memory. */
  . = 0x80010000;
  .text   : { *(.text) }
  .rodata : { *(.rodata*) }
  .data   : { *(.data) }
  .bss    : { *(.bss COMMON) }

  STACK_BASE = .;
  . += 0x10000;
  STACK_TOP = .;

  . = 0;
  .exceptions : {
    *(.exceptions*)
  }


  /* Discard stuff we don't want */
  /DISCARD/ : {
    *(.comment)
  }
}
