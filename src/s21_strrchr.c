#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *ch = s21_NULL;
  if (str != s21_NULL) {
    do {
      if (*str == c) {
        ch = (char *)str;
      }
    } while (*str++);
  }
  return ch;
}