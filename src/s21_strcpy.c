#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  if (dest == s21_NULL) {
    return s21_NULL;
  }
  char *point = dest;
  while (*src != '\0') {
    *dest++ = *src++;
    // printf("%c", *src);
  }
  *dest = '\0';
  return point;
}