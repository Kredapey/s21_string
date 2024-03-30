#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *a = (char *)dest;
  char *b = (char *)src;
  char *temp = (char *)calloc(n, sizeof(char));
  if (temp == s21_NULL) {
    return s21_NULL;
  } else {
    s21_size_t i = 0;
    for (i = 0; i < n; i++) {
      *(temp + i) = *(b + i);
    }
    for (i = 0; i < n; i++) {
      *(a + i) = *(temp + i);
    }
    free(temp);
  }
  return dest;
}