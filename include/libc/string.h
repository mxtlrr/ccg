#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

void memcpy(void *dest, void *src, size_t n);
void strcpy(char* str1, char* str2);

char* itoa(int num, int base);