#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t b = s21_strlen(dest);
  for (s21_size_t i = b; i < n + b; i++) {
    *(dest + i) = *src++;
  }
  return dest;
}