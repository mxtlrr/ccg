#pragma once

#include <stdint.h>

#include "libc/stdio.h"

__attribute__((interrupt("SWI")))
void swi_handler(uint32_t r0, uint32_t r1, uint32_t r2,
                uint32_t r3);