#pragma once

#include <stdint.h>

enum PE_MODES {
  USER       = 0b0000,
  FIQ        = 0b0001,
  IRQ        = 0b0010,
  SUPERVISOR = 0b0011,
  MONITOR    = 0b0110,
  ABORT      = 0b0111,
  HYPERVISOR = 0b1010,
  UNDEF      = 0b1011,
  SYSTEM     = 0b1111
};


extern char* pe_modes[];
uint8_t get_mode(void);