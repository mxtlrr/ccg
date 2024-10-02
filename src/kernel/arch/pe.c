#include "arch/pe.h"

char* pe_modes[] = {
  "User", "FIQ",
  "IRQ",  "Supervisor", 0, 0,
  "Monitor", "Abort",   0, 0,
  "Hypervisor", "Undef", 0, 0, 0,
  "System"
};

uint8_t get_mode(void){
  uint32_t cspr;
  asm("MRS %0, cpsr" : "=r"(cspr));
  return (uint8_t)(cspr & 0xF);
}