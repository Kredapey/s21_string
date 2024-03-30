#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *a = (char *)dest;
  char *b = (char *)src;
  while (n--) {
    *a = *b;
    a++;
    b++;
  }
  return dest;
}