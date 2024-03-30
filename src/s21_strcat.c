#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t a = s21_strlen(src);
  s21_size_t b = s21_strlen(dest);
  for (s21_size_t i = b; i < a + b; i++) {
    *(dest + i) = *src++;
  }
  return dest;
}