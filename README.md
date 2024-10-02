experimental cortex-a15 (armv7) kernel. requires `arm-none-eabi-*`. run `make` to compile it.
# stuff to do
- write to some machine registers to enable the features you need
- put the machine in the "exception level" you want
- parse a device tree to see what hardware is available to you
- set up a page table and enable the mmu
- install your interrupt handlers in the exception vector table
- interact with the interrupt controller to make it direct the interrupts you want to the cores you want.
