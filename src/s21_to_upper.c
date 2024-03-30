#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *str1;
  if ((str1 = (char *)calloc(s21_strlen(str) + 1, sizeof(char))) == NULL) {
    return NULL;
  } else {
    for (int i = 0; i < (int)s21_strlen(str); i++) {
      if (str[i] < 'a' || str[i] > 'z') {
        str1[i] = str[i];
      } else {
        str1[i] = str[i] - 32;
      }
    }
  }
  return (void *)str1;
}