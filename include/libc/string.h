#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

// Copy N bytes of SRC to DEST
void memcpy(void* dest, void* src, size_t n);

// Set n bytes of S to C
void memset(void* s, int c, size_t n);

// Copy str2 (src) to str1 (dest)
void strcpy(char* str1, char* str2);

char* itoa(int num, int base);
