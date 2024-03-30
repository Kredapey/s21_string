#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t a = 0;
  int countStart = 0;
  int prev = 0;
  do {
    if (s21_strchr(str2, *str1)) {
      if (prev == 0 && countStart != 0) {
        return a;
      }
      a++;
      prev = 1;
    } else {
      prev = 0;
    }
    countStart++;
  } while (*str1++);
  return a;
}