#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t counter = 0;
  if (str1 == s21_NULL || str2 == s21_NULL) {
    return counter;
  }
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      return counter;
    } else {
      str1++;
      counter++;
    }
  }
  return counter;
}