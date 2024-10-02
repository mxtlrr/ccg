#pragma once

#include <stdint.h>

#include "libc/stdio.h"

void __c_svc_hdlr(uint32_t r0, uint32_t r1, uint32_t r2,
                uint32_t r3, uint32_t lr);