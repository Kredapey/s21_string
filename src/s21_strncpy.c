#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  int srcLenght = (int)s21_strlen(src);
  int cpyLenght = (int)n > srcLenght ? (srcLenght + 1) : (int)n;
  for (int i = 0; i < cpyLenght; i++) {
    dest[i] = src[i];
  }
  return dest;
}