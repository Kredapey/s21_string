#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
  int counter = 0;
  s21_size_t a = 0;
  if (s21_strlen(str1) < s21_strlen(str2)) {
    a = s21_strlen(str2);
  } else {
    a = s21_strlen(str1);
  }
  for (s21_size_t i = 0; i < a; i++) {
    // #ifdef __linux__
    //     counter = counter + (*str1++ - *str2++);
    // #endif
    // #ifdef __APPLE__
    counter = *str1++ - *str2++;
    if (counter != 0) {
      break;
    }
    // #endif
  }
  // #ifdef __linux__
  //   if (counter > 0) {
  //     counter = 1;
  //   } else if (counter < 0) {
  //     counter = -1;
  //   } else {
  //     counter = 0;
  //   }
  // #endif
  return counter;
}