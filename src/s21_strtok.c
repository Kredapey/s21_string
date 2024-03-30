#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *newGen;
  if (!str) {
    str = newGen;
  }
  if (!str) {
    return s21_NULL;
  }
  while (1) {
    if (s21_strchr(delim, *str)) {
      str++;
      continue;
    }
    if (*str == '\0') {
      return s21_NULL;
    }
    break;
  }
  char *ret = str;
  while (1) {
    if (*str == '\0') {
      newGen = str;
      return ret;
    }
    if (s21_strchr(delim, *str)) {
      *str = '\0';
      newGen = str + 1;
      return ret;
    }
    str++;
  }
  return ret;
}