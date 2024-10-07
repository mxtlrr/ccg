#pragma once

#include <stdint.h>

#include "libc/stdio.h"

#include "fs/fs-op.h"

enum SCALL_VEC {
  // TODO: i dont know... fkin something
  TMPFS_VEC = 0x01
};

__attribute__((interrupt("SWI")))
void swi_handler(uint32_t r0, uint32_t r1, uint32_t r2,
                uint32_t r3);