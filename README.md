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

# Roadmap / Stuff To Do
- [ ] Enable features that ARM lets me enable
  - [ ] TLB
  - [ ] MMU
  - [ ] Others I can't think of
- [X] Put machine in EL0, user mode
- [ ] Parse device tree
  - [ ] Would probably require a rootFS, meaning bootloader required
  here.
- [ ] Page table
  - [ ] Set up TLB
  - [ ] Encode all 4096 tables
  - [ ] Turn on the MMU and **not** get a prefetch abort :skull:
- [ ] Exceptions
  - [ ] Undefined instruction
  - [X] System calls
  - [ ] Prefetch
  - [ ] Data abort
  - [ ] IRQ/FIQ
- [ ] Bootloader
  - [ ] U-boot
- [ ] TmpFS
  - [ ] RW
  - [ ] Syscalls for reading/writing
- [ ] Enable/work on some peripherals
  - [X] UART0
  - [ ] Ethernet(?)

# The TmpFS: Technical Details
CCG uses a temporary read/write filesystem, meaning that
- You can read/write to every file on it.
- When the system is reset, all changes are lost.

## The Syscalls

|  Syscall name  |                Action                | Vector # | 
| -------------- | ------------------------------------ | -------- |
| FS_CREATE_FILE | Creates a file with an empty buffer. | `0x001`  |
| FS_REMOVE_FILE | Delete a file.                       | `0x001`  |
| FS_READ_FILE   | Reads the *entire* buffer of a file. | `0x001`  |