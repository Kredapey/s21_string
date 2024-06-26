#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      return (char *)str1;
    } else {
      str1++;
    }
  }
  return s21_NULL;
}