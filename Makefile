ARCH ?= arm-none-eabi

CC      := $(ARCH)-gcc
CFLAGS  := -ffreestanding -Wall -Wextra \
           -Iinclude/

AS      := $(ARCH)-as
ASFLAGS := -march=armv7-a -mcpu=cortex-a15

LD      := $(ARCH)-ld
LDFLAGS := -Tsrc/link.ld


SRCDIR := src
OBJDIR := obj
BINDIR := bin

TARGET := $(BINDIR)/kernel.elf

C_SOURCES := $(shell find $(SRCDIR) -name '*.c')
ASM_SOURCES := $(shell find include/ -name '*.s')
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(C_SOURCES)) \
           $(patsubst include/%.s,$(OBJDIR)/%.o,$(ASM_SOURCES))

all: stub $(TARGET)

stub:
	@mkdir -p obj/ bin/
	@echo AS src/boot/stub.s
	@$(AS) $(ASFLAGS) src/boot/stub.s -o obj/stub.o

$(TARGET): $(OBJECTS) | bin
	@echo Linking to $(TARGET)
	@$(LD) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c | obj
	@echo CC $<
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: include/%.s | obj
	@echo AS $<
	@mkdir -p $(dir $@)
	@$(AS) $(ASFLAGS) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)


qemu: bin/kernel.elf
	qemu-system-arm -M vexpress-a15 -cpu cortex-a15 -d int -kernel $^ -serial stdio