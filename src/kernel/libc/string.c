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

// internal...
int divide(int dividend, int divisor, int* remainder) {
  int quotient = 0;
  *remainder = dividend;  // Initialize remainder to dividend

  while (*remainder >= divisor) {
    *remainder -= divisor;
    quotient++;
  }

  return quotient;
}

// Function to convert an integer to a string in a given base
char* itoa(int num, int base) {
  static char str[50];
  int i = 0;
  bool isNegative = false;
  int remainder;

  if (num == 0) return "0";

  if (num < 0 && base == 10) {
    isNegative = true;
    num = -num;
  }

  while (num != 0) {
    int quotient = divide(num, base, &remainder);
    str[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';  // Convert digit to character
    num = quotient;  // Continue with the quotient for the next iteration
  }

  if (isNegative) str[i++] = '-';

  str[i] = '\0';

  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }

  return str;
}