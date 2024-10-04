# CCG
32-bit Cortex-A15 operating system / kernel. Written in C + ARM assembly.

# Compilation
You'll need the arm-none-eabi toolchain. You can get this with
- `arm-none-eabi-gcc` and `arm-none-eabi-binutils` on Arch-based distros,
- and `gcc-arm-none-eabi` and `binutils-arm-none-eabi` on Debian-based 
distros.

Once you have that, you should be good to go. You can then just run `make`
and it'll compile. The resulitng ELF will be `bin/kernel.elf`.

## QEMU
Run `make qemu`. It opens QEMU with the serial (where the output is
directed to via UART) as the terminal, as well as interrupts turned on,
so you know what's happening.

## Real Hardware
I dunno. Don't have a ARM board

# Roadmap / Stuff To Do
- [ ] write to some machine registers to enable some features
- [ ] put the machine in EL1
- [ ] parse a device tree to see what hardware is availbale
- [ ] set up a page table and enable the MMU
- [X] install interrupt handlers in the exception vector table
- [ ] interact with the interrupt controller to make it direct the interrupts to specific cores.
- [ ] Support PL110
- [ ] Actual bootloader!