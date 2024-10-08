#include "libc/string.h"

void memcpy(void *dest, void *src, size_t n) {
  char *csrc = (char *)src;
  char *cdest = (char *)dest;

  for (size_t i=0; i<n; i++) cdest[i] = csrc[i];
}

void memset(void* s, int c, size_t n){
	char* cs = (char*)s;
	for(size_t i = 0; i < n; i++) cs[i] = c;
}

void strcpy(char* str1, char* str2){
  for(int i = 0; str2[i] != '\0'; i++)
    str1[i] = str2[i];
}

int strcmp(const char* a, const char* b){
  const unsigned char *s1 = (const unsigned char *)a;
  const unsigned char *s2 = (const unsigned char *)b;
  unsigned char c1, c2;
  do {
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
	  if (c1 == '\0') return c1 - c2;
  } while (c1 == c2);
  return c1 - c2;
}

int strlen(char* f){
	int ct = 0;
	for(int n = 0; f[n] != '\0'; n++) ct++;
	return ct;
}

// internal... TODO: move to a "math" file
int divide(int dividend, int divisor, int* remainder) {
  int quotient = 0;
  *remainder = dividend;  // Initialize remainder to dividend

  while (*remainder >= divisor) {
    *remainder -= divisor;
    quotient++;
  }

  return quotient;
}

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
