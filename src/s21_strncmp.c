#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int counter = 0;
  // #ifdef __linux__
  //   if (n > s21_strlen(str1) && n > s21_strlen(str2)) {
  //     if (s21_strlen(str1) > s21_strlen(str2)) {
  //       n = s21_strlen(str1);
  //     } else {
  //       n = s21_strlen(str2);
  //     }
  //   }
  //   for (s21_size_t i = 0; i < n; i++) {
  //     counter = counter + (*str1++ - *str2++);
  //   }
  //   if (counter) {
  //     counter = 1;
  //   } else if (!counter && counter != 0) {
  //     counter = -1;
  //   } else {
  //     counter = 0;
  //   }
  // #endif
  // #ifdef __APPLE__
  for (s21_size_t i = 0; i < n; i++) {
    counter = *str1++ - *str2++;
    if (counter != 0) {
      break;
    }
  }
  // #endif
  return counter;
}