#include "arch/exceptions.h"


void __c_svc_hdlr(uint32_t r0, uint32_t r1, uint32_t r2,
                uint32_t r3, uint32_t lr){
  printf("r0: %x | r1: %x | r2: %x | r3: %x | lr: %x\n", r0, r1, r2,
      r3, lr);
}