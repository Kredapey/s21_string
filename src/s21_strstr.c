#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }
  while (*haystack != '\0') {
    if (*haystack == *needle && s21_strstrHelper(haystack, needle)) {
      return (char *)haystack;
    }
    haystack++;
  }
  return s21_NULL;
}

int s21_strstrHelper(const char *haystack, const char *needle) {
  int counter = (int)s21_strlen(needle);
  int count = 0;
  while (*haystack && *needle) {
    if (*haystack != *needle) {
      return 0;
    }
    haystack++;
    needle++;
    count++;
  }
  if (count == counter) {
    return 1;
  } else {
    return 0;
  }
}