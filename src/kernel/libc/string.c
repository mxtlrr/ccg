#include "libc/string.h"

void memcpy(void *dest, void *src, size_t n) {
  char *csrc = (char *)src;
  char *cdest = (char *)dest;

  for (size_t i=0; i<n; i++) cdest[i] = csrc[i];
}

void strcpy(char* str1, char* str2){
  for(int i = 0; str2[i] != '\0'; i++)
    str1[i] = str2[i];
}