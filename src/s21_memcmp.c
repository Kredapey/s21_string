#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *a = (char *)str1;
  char *b = (char *)str2;
  int counter = 0;
  for (s21_size_t i = 0; i < n; i++) {
    counter = (*a++ - *b++);
    if (counter != 0) {
      return counter;
    }
  }
  return counter;
}