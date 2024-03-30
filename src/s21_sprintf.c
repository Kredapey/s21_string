#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  optStruct optStr = {0};
  initOptStruct(&optStr);
  flagCounter flagCount = {0};
  initflagCount(&flagCount);
  int finalLenght = 0;
  char str1[1000] = "\0";
  char str2[1000] = "\0";
  char ch = '\'';
  int gCounter = 0, j = 0, outputCounter = 0;
  va_list parametr = {0};
  va_start(parametr, format);
  finalLenght =
      finalCycle(&flagCount, &optStr, str, str1, str2, ch, outputCounter,
                 parametr, finalLenght, gCounter, j, (char *)format);
  return finalLenght;
}

char *intToString(long int d, int acc, char *string) {
  int zeroCounter = 0;
  if (acc == 0) {
    zeroCounter = 1;
  }
  if (acc == -1) {
    acc = 0;
  }
  int j = 0;
  int minCount = 0;
  if (d < 0) {
    d = d * (-1);
    minCount = 1;
  }
  while (d > 9) {
    string[j] = (d % 10) + '0';
    d = d / 10;
    j += 1;
  }
  string[j] = d + '0';
  string[j + 1] = '\0';
  j += 1;
  reverseString(j, string);
  accInInt(acc, string, &j);
  if (minCount == 1) {
    s21_size_t i = s21_strlen(string);
    do {
      string[i + 1] = string[i];
    } while (i--);
    string[0] = '-';
    j += 1;
  }
  if (zeroCounter == 1 && d == 0) {
    string[0] = '\0';
  }
  return (string);
}

char *doubleToString(double d, int gFlag, int acc, char *string,
                     flagCounter *flagCount) {
  int x = 0, counterGQ = 0, counterGE = 0, gCounterFlag = 0, summaryCounter = 0;
  if (d < 0) {
    flagCount->minCounter = 1;
    d = d * (-1);
  }
  long long int eInt = 0, qInt = 0;
  while (x < 100) {
    string[x] = '\0';
    x++;
  }
  workWithAcc(&acc, &d, gFlag);
  char string1[1000] = "\0", string2[1000] = "\0";
  double q = 0, e = 0, newQ = -1;
  if (gFlag == 1 && flagCount->reshFlag == 0) {
    float workWithGQ = d, workWithGE = d;
    int someIntQ = 0;
    while (someIntQ != workWithGQ) {
      workWithGQ *= 10;
      someIntQ = workWithGQ;
      counterGQ++;
    }
    while (workWithGE >= 1) {
      counterGE += 1;
      workWithGE /= 10;
    }
    summaryCounter = counterGQ + counterGE;
    if (summaryCounter < acc && summaryCounter <= 6) {
      acc = summaryCounter;
    }
  }
  q = modf(d, &e);
  int counter = 0;
  whileInDouble(&newQ, &q, &counter, gFlag, acc, counterGE, &gCounterFlag);
  if (e == 0) {
    string1[0] = '0';
  } else {
    eInt = e;
    intToString(eInt, 0, string1);
  }
  qInt = newQ;
  if (gCounterFlag == 1) {
    intToString(qInt, acc - counterGE, string2);
  } else {
    intToString(qInt, acc, string2);
  }
  ifsInDouble(string2, gFlag, flagCount, acc);
  glueTwoString(string2, string1, gFlag, acc, string, qInt, eInt);
  return (string);
}

char *intToHexadecimalInteger(long int d, int registerLabel, char *string,
                              int acc) {
  long int remD = d;
  int accCounter = 0;
  if (acc == 0) {
    accCounter = 1;
  }
  if (acc == -1) {
    acc = 0;
  }
  char temp = '\0';
  int remaind = 0, j = 0;
  int e = 0;
  while (e < 100) {
    string[e] = '\0';
    e++;
  }
  if (d == 0) {
    string[0] = '0';
  }
  while (d) {
    remaind = d % 16;
    if (remaind > 9) {
      temp = switchRemaind(remaind, registerLabel);
    } else {
      temp = remaind + '0';
    }
    string[j] = temp;
    j += 1;
    d = d / 16;
  }
  int accCount = acc - j;
  reverseString(j, string);
  if (accCounter != 1 && acc > j) {
    if (remD != 0) {
      for (int i = j; i >= 0; i--) {
        string[i + accCount] = string[i];
      }
    }
    for (int g = 0; g < accCount; g++) {
      string[g] = '0';
    }
  }
  return (string);
}

char *doubleToE(long double e, int registerLabel, int gFlag, int acc,
                char *string, flagCounter *flagCount) {
  int x = 0, j = 0, counter = 0, plusCounter = 0;
  while (x < 100) {
    string[x] = '\0';
    x++;
  }
  if (acc == -1) {
    acc = 6;
  }
  char string1[1000], string2[1000];
  workWithE(&e, &counter, &plusCounter, acc);
  if (gFlag == 1) {
    doubleToString(e, 1, acc, string1, flagCount);
  } else {
    doubleToString(e, 0, acc, string1, flagCount);
  }
  registerInE(registerLabel, string1, plusCounter);
  intToString(counter, 0, string2);
  if (counter < 10) {
    int i = (int)s21_strlen(string2);
    do {
      string2[i + 1] = string2[i];
    } while (i--);
    string2[0] = '0';
    if (counter == 0) {
      string2[1] = '0';
      string2[2] = '\0';
    }
  }
  for (int i = 0; i < (int)(s21_strlen(string1)); i++) {
    string[j] = string1[i];
    j += 1;
  }
  for (int i = 0; i < (int)s21_strlen(string2); i++) {
    string[j] = string2[i];
    j += 1;
  }
  return string;
}

void reverseString(int j, char *string) {
  char temp = '\0';
  for (int i = 0; i < j / 2; i++) {
    temp = string[i];
    string[i] = string[j - 1 - i];
    string[j - 1 - i] = temp;
  }
}

char switchRemaind(int remaind, int registerLabel) {
  char temp = '\0';
  switch (remaind) {
    case 10:
      temp = registerLabel ? 'A' : 'a';
      break;
    case 11:
      temp = registerLabel ? 'B' : 'b';
      break;
    case 12:
      temp = registerLabel ? 'C' : 'c';
      break;
    case 13:
      temp = registerLabel ? 'D' : 'd';
      break;
    case 14:
      temp = registerLabel ? 'E' : 'e';
      break;
    case 15:
      temp = registerLabel ? 'F' : 'f';
      break;
    case 16:
      temp = 10 + '0';
      break;
    default:
      break;
  }
  return temp;
}

int numCounter(double g) {
  double q = 0;
  int counter = 0;
  g = modf(g, &q);
  if (q >= 1) {
    while (q > 9) {
      q = q / 10;
      counter++;
    }
    counter++;
  } else if (q <= -1) {
    while (q < -9) {
      q = q / 10;
      counter++;
    }
    counter++;
  } else if (g > -1 && g < 0 && q == 0) {
    while (g > -1 && g < 0) {
      g = g * 10;
      counter++;
    }
    counter += 2;
  } else {
    while (g < 1 && g > 0) {
      g = g * 10;
      counter++;
    }
    counter += 2;
  }
  return counter;
}

char *glueTwoString(char *string1, char *string2, int gFlag, int acc,
                    char *string, long int dInt, long int qInt) {
  int j = 0, gCounter = 0;
  workWithGCounter(dInt, qInt, gFlag, acc, &gCounter);
  for (int i = 0; i < (int)(s21_strlen(string2)); i++) {
    if (gFlag == 1) {
      if (gCounter <= acc) {
        string[j] = string2[i];
        j += 1;
        if (string2[0] != '0') {
          gCounter++;
        }
      }
    } else {
      string[j] = string2[i];
      j += 1;
    }
  }
  if (acc != 0) {
    if (gFlag == 1) {
      if (gCounter < acc) {
        string[j] = '.';
        j += 1;
        if ((qInt > 9 && qInt < 100) && (dInt % 100 == 0)) {
          gCounter++;
          gCounter--;
        }
      }
    } else {
      string[j] = '.';
      j += 1;
    }
    for (int i = 0; i < (int)s21_strlen(string1); i++) {
      if (gFlag == 1) {
        if (gCounter < acc) {
          string[j] = string1[i];
          j += 1;
          gCounter++;
        }
      } else {
        string[j] = string1[i];
        j += 1;
      }
    }
    string[j] = '\0';
  }
  if (string[(int)s21_strlen(string) - 1] == '.' && gFlag == 1) {
    string[(int)s21_strlen(string) - 1] = '\0';
  }
  return (string);
}

char *deciToOctal(long int o, char *string, int acc) {
  int e = 0;
  while (e < 100) {
    string[e] = '\0';
    e++;
  }
  int accCounter = 0;
  if (acc == 0) {
    accCounter = 1;
  }
  if (acc == -1) {
    acc = 0;
  }
  long int d = o;
  int lenght = 0;
  int counter = 0;
  int j = 0;
  while (d >= 8) {
    d = d / 8;
    counter++;
  }
  while (o >= 8) {
    string[j] = (o % 8) + '0';
    o = o / 8;
    j++;
  }
  string[j++] = o + '0';
  string[j] = '\0';
  lenght = (int)s21_strlen(string);
  reverseString(lenght, string);
  int accCount = acc - lenght;
  if (accCounter != 1 && acc > lenght) {
    for (int i = lenght; i >= 0; i--) {
      string[i + accCount] = string[i];
    }
    for (int g = 0; g < accCount; g++) {
      string[g] = '0';
    }
  }
  return string;
}

int decideChar(char ch) {
  switch (ch) {
    case ('c'):
    case ('d'):
    case ('i'):
    case ('e'):
    case ('E'):
    case ('f'):
    case ('g'):
    case ('G'):
    case ('o'):
    case ('s'):
    case ('u'):
    case ('x'):
    case ('X'):
    case ('p'):
    case ('n'):
    case ('%'):
      return 1;
      break;
    default:
      return 0;
      break;
  }
}

int output(char *str, char *str1, int plusCounter, int reshCounter, int shir,
           int zeroFlag, int defFlag, char ch, int spaceCounter, int minCount,
           int acc) {
  int outputCounter = 0, strLenght = 0, minCounter = 0,
      j = (int)s21_strlen(str1);
  if (minCount == 1) {
    for (int i = (int)s21_strlen(str1); i >= 0; i--) {
      str1[i + 1] = str1[i];
    }
    str1[0] = '-';
  }
  firstFuncInOutput(str1, &minCounter, ch, plusCounter, reshCounter, &j, acc);
  secFuncInOutput(ch, str1, reshCounter, &j);
  thirdFuncInOutput(ch, reshCounter, str1, &j, spaceCounter, minCounter);
  for (s21_size_t i = 0; i < s21_strlen(str1); i++) {
    strLenght++;
  }
  // strLenght = strLenght + minCount;
  if (shir == 0) {
    for (int i = 0; i < strLenght; i++) {
      *str++ = str1[i];
      outputCounter++;
    }
  }
  if (shir != 0) {
    if (defFlag == 1) {
      for (int i = 0; i < strLenght; i++) {
        *str++ = str1[i];
        outputCounter++;
      }
      for (int i = 0; i < shir - strLenght; i++) {
        *str++ = ' ';
        outputCounter++;
      }
    } else {
      fourthFuncInOutput(&outputCounter, str, zeroFlag, shir, strLenght, str1,
                         minCount);
    }
  }
  return outputCounter;
}

void initOptStruct(optStruct *optStr) {
  optStr->shortD = 0;
  optStr->simpleD = 0;
  optStr->longD = 0;
  optStr->nFunc = s21_NULL;
  optStr->p = 0;
  optStr->h = 0;
  optStr->longG = 0;
  optStr->longF = 0;
  optStr->shortH = 0;
  optStr->simpleH = 0;
  optStr->longH = 0;
  optStr->shortX = 0;
  optStr->simpleX = 0;
  optStr->longX = 0;
  optStr->f = 0;
  optStr->e = 0;
  optStr->g = 0;
  optStr->longE = 0;
  optStr->strForS = "\0";
  optStr->x = 0;
}

void initflagCount(flagCounter *flagCount) {
  flagCount->startStr = 0;
  flagCount->zeroFlag = 0;
  flagCount->strCounter = 0;
  flagCount->hFlag = 0;
  flagCount->lFlag = 0;
  flagCount->bigLFlag = 0;
  flagCount->plusFlag = 0;
  flagCount->charCounter = 0;
  flagCount->reshFlag = 0;
  flagCount->acc = -1;
  flagCount->startNumStr = 0;
  flagCount->start = 0;
  flagCount->finish = 0;
  flagCount->shir = 0;
  flagCount->defFlag = 0;
  flagCount->spaceCounter = 0;
  flagCount->registerLabel = 0;
  flagCount->prevch = '\'';
}

int dAndICase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
              char ch, int outputCounter, va_list parametr) {
  if (flagCount->hFlag == 1) {
    optStr->shortD = va_arg(parametr, int);
    intToString(optStr->shortD, flagCount->acc, str1);
  } else if (flagCount->lFlag == 1) {
    optStr->longD = va_arg(parametr, long int);
    intToString(optStr->longD, flagCount->acc, str1);
  } else {
    optStr->simpleD = va_arg(parametr, int);
    intToString(optStr->simpleD, flagCount->acc, str1);
  }
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

char *outputStrCleaner(char *str, int outputCounter) {
  while (outputCounter > 0) {
    str++;
    outputCounter--;
  }
  return str;
}

int floatCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
              char ch, int outputCounter, va_list parametr) {
  if (flagCount->bigLFlag == 1) {
    if ((optStr->longF = va_arg(parametr, long double))) {
      doubleToString(optStr->longF, 0, flagCount->acc, str1, flagCount);
    }
  } else {
    optStr->f = va_arg(parametr, double);
    doubleToString(optStr->f, 0, flagCount->acc, str1, flagCount);
  }
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

int charCase(flagCounter *flagCount, char *str, char ch, int outputCounter,
             va_list parametr) {
  outputCounter = 0;
  ch = va_arg(parametr, int);
  if (flagCount->shir != 0) {
    if (flagCount->defFlag == 1) {
      *str++ = ch;
      outputCounter++;
      for (int i = 0; i < flagCount->shir - 1; i++) {
        *str++ = ' ';
        outputCounter++;
      }
    } else {
      for (int i = 0; i < flagCount->shir - 1; i++) {
        if (flagCount->zeroFlag == 1) {
          *str++ = '0';
          outputCounter++;
        } else {
          *str++ = ' ';
          outputCounter++;
        }
      }
      *str++ = ch;
      outputCounter++;
    }
  } else {
    *str++ = ch;
    outputCounter++;
  }
  return outputCounter;
}

int stringCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
               char ch, int outputCounter, va_list parametr) {
  optStr->strForS = va_arg(parametr, char *);
  int qwert = 0;
  while (qwert < 100) {
    str1[qwert] = '\0';
    qwert++;
  }
  if (flagCount->acc != -1) {
    s21_strncpy(str1, optStr->strForS, flagCount->acc);
  } else {
    s21_strcpy(str1, optStr->strForS);
  }
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

int xCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr, char c) {
  flagCount->registerLabel = (c == 'x') ? 0 : 1;
  if (flagCount->hFlag == 1) {
    optStr->shortX = va_arg(parametr, int);
    optStr->x = optStr->shortX;
    if (optStr->shortX < 0) {
      (optStr->x = shortUnsignedInt + 1 + optStr->x);
      intToHexadecimalInteger(optStr->x, flagCount->registerLabel, str1,
                              flagCount->acc);
    } else {
      intToHexadecimalInteger(optStr->shortX, flagCount->registerLabel, str1,
                              flagCount->acc);
    }
  } else if (flagCount->lFlag == 1) {
    optStr->longX = va_arg(parametr, long int);
    optStr->x = optStr->longX;
    if (optStr->longX < 0) {
      (optStr->x = unsignedInt + 1 + optStr->x);
      intToHexadecimalInteger(optStr->x, flagCount->registerLabel, str1,
                              flagCount->acc);
      for (int w = (int)s21_strlen(str1); w >= 0; w--) {
        str1[w + 8] = str1[w];
      }
      for (int q = 0; q < 8; q++) {
        if (flagCount->registerLabel == 0) {
          str1[q] = 'f';
        } else {
          str1[q] = 'F';
        }
      }
    } else {
      intToHexadecimalInteger(optStr->longX, flagCount->registerLabel, str1,
                              flagCount->acc);
    }
  } else {
    optStr->simpleX = va_arg(parametr, int);
    optStr->x = optStr->simpleX;
    if (optStr->simpleX < 0) {
      (optStr->x = unsignedInt + 1 + optStr->x);
      intToHexadecimalInteger(optStr->x, flagCount->registerLabel, str1,
                              flagCount->acc);
    } else {
      intToHexadecimalInteger(optStr->simpleX, flagCount->registerLabel, str1,
                              flagCount->acc);
    }
  }
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

int gCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr, char c, int gCounter) {
  if (flagCount->bigLFlag == 1) {
    flagCount->registerLabel = (c == 'g') ? 0 : 1;
    optStr->longG = va_arg(parametr, long double);
    gCounter = numCounter(optStr->longG);
    if (flagCount->acc == -1) {
      flagCount->acc = 6;
    }
    if (flagCount->acc == 0) {
      gCounter = -1;
    }
    if (flagCount->acc <= 6) {
      gCounter = gCounter - 1;
    }
    if (gCounter > flagCount->acc) {
      doubleToE(optStr->longG, flagCount->registerLabel, 1, flagCount->acc,
                str1, flagCount);
    } else {
      doubleToString(optStr->longG, 1, flagCount->acc, str1, flagCount);
    }
  } else {
    flagCount->registerLabel = (c == 'g') ? 0 : 1;
    optStr->g = va_arg(parametr, double);
    gCounter = numCounter(optStr->g);
    if (flagCount->acc == -1) {
      flagCount->acc = 6;
    }
    if (flagCount->acc == 0) {
      gCounter = -1;
    }
    if (flagCount->acc <= 6) {
      gCounter = gCounter - 1;
    }
    if (gCounter > flagCount->acc) {
      doubleToE(optStr->g, flagCount->registerLabel, 1, flagCount->acc, str1,
                flagCount);
    } else {
      doubleToString(optStr->g, 1, flagCount->acc, str1, flagCount);
    }
  }
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

int eCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr, char c) {
  flagCount->registerLabel = (c == 'e') ? 0 : 1;
  if (flagCount->bigLFlag == 1) {
    optStr->longE = va_arg(parametr, long double);
    doubleToE(optStr->longE, flagCount->registerLabel, 0, flagCount->acc, str1,
              flagCount);
  } else {
    optStr->e = va_arg(parametr, double);
    doubleToE(optStr->e, flagCount->registerLabel, 0, flagCount->acc, str1,
              flagCount);
  }
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

int oCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr) {
  if (flagCount->hFlag == 1) {
    optStr->shortX = va_arg(parametr, int);
    optStr->x = optStr->shortX;
    if (optStr->shortX < 0) {
      (optStr->x = unsignedInt + 1 + optStr->x);
      deciToOctal(optStr->x, str1, flagCount->acc);
    } else {
      deciToOctal(optStr->shortX, str1, flagCount->acc);
    }
  } else if (flagCount->lFlag == 1) {
    optStr->longX = va_arg(parametr, long int);
    optStr->x = optStr->longX;
    if (optStr->longX < 0) {
      (optStr->x = unsignedInt + 1 + optStr->x);
      deciToOctal(optStr->x, str1, flagCount->acc);
    } else {
      deciToOctal(optStr->longX, str1, flagCount->acc);
    }
  } else {
    optStr->simpleX = va_arg(parametr, int);
    optStr->x = optStr->simpleX;
    if (optStr->simpleX < 0) {
      (optStr->x = unsignedInt + 1 + optStr->x);
      deciToOctal(optStr->x, str1, flagCount->acc);
    } else {
      deciToOctal(optStr->simpleX, str1, flagCount->acc);
    }
  }
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

int pCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr) {
  optStr->p = va_arg(parametr, long int);
  intToHexadecimalInteger(optStr->p, 0, str1, flagCount->acc);
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

int uCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr) {
  optStr->h = va_arg(parametr, long long int);
  if (optStr->h < 0) {
    optStr->h = unsignedInt + 1 + optStr->h;
    intToString(optStr->h, flagCount->acc, str1);
  } else {
    if (flagCount->hFlag == 1) {
      optStr->shortH = optStr->h;
      intToString(optStr->shortH, flagCount->acc, str1);
    } else if (flagCount->lFlag == 1) {
      optStr->longH = optStr->h;
      intToString(optStr->longH, flagCount->acc, str1);
    } else {
      optStr->simpleH = optStr->h;
      intToString(optStr->simpleH, flagCount->acc, str1);
    }
  }
  outputCounter =
      output(str, str1, flagCount->plusFlag, flagCount->reshFlag,
             flagCount->shir, flagCount->zeroFlag, flagCount->defFlag, ch,
             flagCount->spaceCounter, flagCount->minCounter, flagCount->acc);
  return outputCounter;
}

int percCase(flagCounter *flagCount, char *str, char ch, int outputCounter) {
  outputCounter = 0;
  if (flagCount->shir != 0) {
    if (flagCount->defFlag == 1) {
      *str++ = ch;
      outputCounter++;
      for (int i = 0; i < flagCount->shir - 1; i++) {
        *str++ = ' ';
        outputCounter++;
      }
    } else {
      for (int i = 0; i < flagCount->shir - 1; i++) {
        if (flagCount->zeroFlag == 1) {
          *str++ = '0';
          outputCounter++;
        } else {
          *str++ = ' ';
          outputCounter++;
        }
      }
      *str++ = ch;
      outputCounter++;
    }
  } else {
    *str++ = ch;
    outputCounter++;
  }
  return outputCounter;
}

void strChange(char *str1, char *str2) {
  int str2Count = 0;
  while (str2Count < (int)s21_strlen(str2)) {
    str2[str2Count] = '\0';
    str2Count++;
  }
  str2Count = 0;
  while (str2Count < (int)s21_strlen(str1)) {
    str1[str2Count] = '\0';
    str2Count++;
  }
}

int switchSpec(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
               char ch, int outputCounter, va_list parametr, char c,
               int finalLenght, int gCounter) {
  switch (ch) {
    case 'd':
    case 'i':
      outputCounter =
          dAndICase(flagCount, optStr, str, str1, ch, outputCounter, parametr);
      break;
    case 'f':
      outputCounter =
          floatCase(flagCount, optStr, str, str1, ch, outputCounter, parametr);
      break;
    case 'c':
      outputCounter = charCase(flagCount, str, ch, outputCounter, parametr);
      break;
    case 's':
      outputCounter =
          stringCase(flagCount, optStr, str, str1, ch, outputCounter, parametr);
      break;
    case 'x':
    case 'X':
      outputCounter =
          xCase(flagCount, optStr, str, str1, ch, outputCounter, parametr, c);
      break;
    case 'g':
    case 'G':
      outputCounter = gCase(flagCount, optStr, str, str1, ch, outputCounter,
                            parametr, c, gCounter);
      break;
    case 'e':
    case 'E':
      outputCounter =
          eCase(flagCount, optStr, str, str1, ch, outputCounter, parametr, c);
      break;
    case 'o':
      outputCounter =
          oCase(flagCount, optStr, str, str1, ch, outputCounter, parametr);
      break;
    case 'p':
      outputCounter =
          pCase(flagCount, optStr, str, str1, ch, outputCounter, parametr);
      break;
    case 'n':
      optStr->nFunc = va_arg(parametr, int *);
      *optStr->nFunc = finalLenght;
      break;
    case 'u':
      outputCounter =
          uCase(flagCount, optStr, str, str1, ch, outputCounter, parametr);
      break;
    case '%':
      outputCounter = percCase(flagCount, str, ch, outputCounter);
      break;
  }
  return outputCounter;
}

int finalCycle(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
               char *str2, char ch, int outputCounter, va_list parametr,
               int finalLenght, int gCounter, int j, char *format) {
  for (char *c = format; *c; c++) {
    outputCounter = 0;
    initflagCount(flagCount);
    initOptStruct(optStr);
    j = 0;
    if (*c != '%') {
      *str++ = *c;
      finalLenght++;
      continue;
    } else {
      if (*(c + 1) == '\0') {
        flagCount->finish = 1;
      } else {
        c++;
      }
      c = specFarc(c, str2, flagCount, &ch, &j);
    }
    if (flagCount->strCounter == 1) {
      for (int a = 0; a < j; a++) {
        *str++ = str2[a];
      }
      continue;
    }
    forInFinalCycle(flagCount, str2, parametr, j);
    outputCounter = switchSpec(flagCount, optStr, str, str1, ch, outputCounter,
                               parametr, *c, finalLenght, gCounter);
    finalLenght = finalLenght + outputCounter;
    str = outputStrCleaner(str, outputCounter);
    strChange(str1, str2);
  }
  *str = '\0';
  return finalLenght;
}

char *specFarc(char *c, char *str2, flagCounter *flagCount, char *ch, int *j) {
  while (flagCount->finish == 0) {
    if (*c == flagCount->prevch && ((*c < 48) || (*c > 57))) {
      ifSpec(flagCount, str2, *c, j);
      continue;
    }
    if (*c == '\0' || *c == '\n' || *c == ',') {
      flagCount->finish = 1;
      continue;
    } else if (*c == ' ') {
      if (flagCount->start == 0) {
        str2[*j] = *c;
        *j = *j + 1;
        if (*(c + 1) == '\0' || *(c + 1) == '\n' || *(c + 1) == ',') {
          flagCount->finish = 1;
          flagCount->start++;
          continue;
        }
      } else {
        flagCount->finish = 1;
        continue;
      }
    } else {
      flagCount->finish = decideChar(*c);
      if (flagCount->finish == 1) {
        charSpec(str2, ch, *c, j, flagCount);
        continue;
      }
      flagOpt(str2, *c, j);
    }
    if (*(c + 1) == '\0') {
      if (flagCount->charCounter == 1) {
        flagCount->strCounter = 1;
      }
      flagCount->finish = 1;
      continue;
    }
    flagCount->prevch = *c;
    c++;
  }
  return c;
}

void flagOpt(char *str2, char c, int *j) {
  if (c >= 48 && c <= 57) {
    str2[*j] = c;
    *j = *j + 1;
  }
  if (c == '.') {
    str2[*j] = c;
    *j = *j + 1;
  }
  if (c == '*') {
    str2[*j] = c;
    *j = *j + 1;
  }
  if (c == '-') {
    str2[*j] = c;
    *j = *j + 1;
  }
  if (c == '+') {
    str2[*j] = c;
    *j = *j + 1;
  }
  if (c == '#') {
    str2[*j] = c;
    *j = *j + 1;
  }
  if (c == 'h' || c == 'l' || c == 'L') {
    str2[*j] = c;
    *j = *j + 1;
  }
}

void charSpec(char *str2, char *ch, char c, int *j, flagCounter *flagCount) {
  flagCount->charCounter = 1;
  *ch = c;
  str2[*j] = c;
  *j = *j + 1;
}

void ifSpec(flagCounter *flagCount, char *str2, char c, int *j) {
  flagCount->strCounter = 1;
  flagCount->finish = 1;
  str2[*j] = c;
  *j = *j + 1;
}

void forInFinalCycle(flagCounter *flagCount, char *str2, va_list parametr,
                     int j) {
  for (int i = 0; i < j; i++) {
    int dotCounter = 0;
    if (str2[i] == '.') dotCounter = 1;
    if (str2[i] == ' ') flagCount->spaceCounter = 1;
    if (flagCount->startNumStr == 0 && str2[i] == '0') flagCount->zeroFlag = 1;
    if (str2[i] >= 48 && str2[i] <= 57 && dotCounter == 0) {
      while (str2[i] >= 48 && str2[i] <= 57) {
        flagCount->shir = (flagCount->shir * 10) + str2[i] - '0';
        i++;
        flagCount->startNumStr++;
        flagCount->startStr++;
      }
    }
    decFlag(str2, &i, flagCount, parametr);
    if (flagCount->startStr == 0) {
      if (str2[i] == '*') {
        flagCount->shir = va_arg(parametr, int);
      }
    } else {
      if (str2[i] == '*' && str2[i - 1] != '.') {
        flagCount->shir = va_arg(parametr, int);
      }
    }
    flagCount->startStr++;
  }
}

void decFlag(char *str2, int *i, flagCounter *flagCount, va_list parametr) {
  if (str2[*i] == '-') flagCount->defFlag = 1;
  if (str2[*i] == '+') flagCount->plusFlag = 1;
  if (str2[*i] == '#') flagCount->reshFlag = 1;
  if (str2[*i] == '.') {
    flagCount->acc = 0;
    *i = *i + 1;
    flagCount->startStr++;
    if (str2[*i] == '*') {
      flagCount->acc = va_arg(parametr, int);
    }
    if (str2[*i] >= 48 && str2[*i] <= 57) {
      while (str2[*i] >= 48 && str2[*i] <= 57) {
        flagCount->acc = (flagCount->acc * 10) + str2[*i] - '0';
        *i = *i + 1;
        flagCount->startStr++;
      }
    }
  }
  if (str2[*i] == 'h') flagCount->hFlag = 1;
  if (str2[*i] == 'l') flagCount->lFlag = 1;
  if (str2[*i] == 'L') flagCount->bigLFlag = 1;
}

void accInInt(int acc, char *string, int *j) {
  if (acc != 0) {
    int accCounter = acc - *j;
    if (accCounter > 0) {
      while (accCounter != 0) {
        s21_size_t i = s21_strlen(string);
        do {
          string[i + 1] = string[i];
        } while (i--);
        string[0] = '0';
        *j += 1;
        accCounter--;
      }
    }
  }
}

void workWithAcc(int *acc, double *d, int gFlag) {
  if (*acc == -1) {
    *acc = 6;
  }
  if (*acc == 0 && gFlag != 1) {
    *d = round(*d);
  } else if (*acc == 0 && gFlag == 1 && *d > 0.1) {
    *acc = 1;
  } else if (*acc < 5 && gFlag == 1 && *d < 0.1) {
    *acc = 6;
  }
}

void workWithE(long double *e, int *counter, int *plusCounter, int acc) {
  if (*e > 0) {
    if (*e < 1) {
      while (*e < 1) {
        *e = *e * 10;
        *counter += 1;
        *plusCounter = 1;
      }
      if (*e < 10 && *e > 9 && acc <= 6) {
        *e = *e / 10;
        *counter = *counter - 1;
        *e = round(*e);
      }
    } else if (*e > 1) {
      while (*e >= 10) {
        *e = *e / 10;
        *counter += 1;
      }
    }
  } else if (*e < 0) {
    if (*e > -1) {
      while (*e > -1) {
        *plusCounter = 1;
        *e = *e * 10;
        *counter += 1;
      }
      if (*e > -10 && *e < -9 && acc <= 6) {
        *e = *e / 10;
        *counter = *counter - 1;
        *e = round(*e);
      }
    } else if (*e < -1) {
      while (*e <= -10) {
        *e = *e / 10;
        *counter += 1;
      }
    }
  }
}

void registerInE(int registerLabel, char *string1, int plusCounter) {
  s21_size_t lenght1 = s21_strlen(string1);
  if (registerLabel == 0) {
    string1[lenght1++] = 'e';
  } else {
    string1[lenght1++] = 'E';
  }
  if (plusCounter == 1) {
    string1[lenght1++] = '-';
  } else {
    string1[lenght1++] = '+';
  }
}

void firstFuncInOutput(char *str1, int *minCounter, char ch, int plusCounter,
                       int reshCounter, int *j, int acc) {
  for (int i = 0; i < (int)s21_strlen(str1); i++) {
    if (str1[i] == '-') *minCounter = 1;
  }
  if (ch == 'p') {
    for (int i = (int)s21_strlen(str1); i >= 0; i--) {
      str1[i + 2] = str1[i];
    }
    str1[0] = '0';
    str1[1] = 'x';
  }
  if ((ch == 'd' || ch == 'f' || ch == 'i' || ch == 'e' || ch == 'E' ||
       ch == 'g' || ch == 'G') &&
      plusCounter == 1) {
    if (str1[0] != '-') {
      for (int i = (int)s21_strlen(str1); i >= 0; i--) {
        str1[i + 1] = str1[i];
      }
      str1[0] = '+';
      *j += 1;
    }
  }
  if (acc == -1) {
    acc = 6;
  }
  if (ch == 'o' && reshCounter == 1 && acc == 6) {
    if (str1[0] == '0' && str1[1] == '\0') {
    } else {
      for (int i = (int)s21_strlen(str1); i >= 0; i--) {
        str1[i + 1] = str1[i];
      }
      str1[0] = '0';
      *j += 1;
    }
  }
}

void secFuncInOutput(char ch, char *str1, int reshCounter, int *j) {
  if (ch == 'x' && reshCounter == 1) {
    int zeroReshCounter = 0;
    for (int i = 0; i < (int)s21_strlen(str1); i++) {
      if (str1[i] != '0') {
        zeroReshCounter = 1;
        break;
      }
    }
    if (zeroReshCounter == 0) {
      str1[999] = '\0';
    } else {
      for (int i = (int)s21_strlen(str1); i >= 0; i--) {
        str1[i + 2] = str1[i];
      }
      str1[0] = '0';
      str1[1] = 'x';
      *j += 2;
    }
  }
  if (ch == 'X' && reshCounter == 1) {
    int zeroReshCounter = 1;
    for (int i = 0; i < (int)s21_strlen(str1); i++) {
      if (str1[i] != '0') {
        zeroReshCounter = 0;
        break;
      }
    }
    if (zeroReshCounter == 1) {
      str1[999] = '\0';
    } else {
      for (int i = (int)s21_strlen(str1); i >= 0; i--) {
        str1[i + 2] = str1[i];
      }
      str1[0] = '0';
      str1[1] = 'X';
      *j += 2;
    }
  }
}

void thirdFuncInOutput(char ch, int reshCounter, char *str1, int *j,
                       int spaceCounter, int minCounter) {
  if ((ch == 'e' || ch == 'E' || ch == 'f' || ch == 'g' || ch == 'G') &&
      reshCounter == 1) {
    int dec = 0;
    int dec1 = 0;
    int e = 0;
    for (int i = 0; i < (int)s21_strlen(str1); i++) {
      if (str1[i] == '.') {
        dec = 1;
      }
      if (str1[i] == 'E' || str1[i] == 'e') {
        dec1 = 1;
        e = i;
      }
    }
    if (dec == 0 && dec1 == 0) {
      str1[s21_strlen(str1)] = '.';
      *j += 1;
    }
    if (dec == 0 && dec1 == 1) {
      for (int i = s21_strlen(str1); i >= e; i--) {
        str1[i + 1] = str1[i];
      }
      str1[e] = '.';
      *j += 1;
    }
  }
  if (spaceCounter == 1 && minCounter == 0 && ch != 's' && ch != 'u') {
    for (int i = (int)s21_strlen(str1); i >= 0; i--) {
      str1[i + 1] = str1[i];
    }
    str1[0] = ' ';
    *j += 1;
  }
}

void fourthFuncInOutput(int *outputCounter, char *str, int zeroFlag, int shir,
                        int strLenght, char *str1, int minCount) {
  if (minCount == 1 && zeroFlag == 1) {
    *str++ = '-';
    for (int i = 0; i < shir - strLenght; i++) {
      if (zeroFlag == 1) {
        *str++ = '0';
        *outputCounter += 1;
      } else {
        *str++ = ' ';
        *outputCounter += 1;
      }
    }
    for (int i = 1; i < strLenght + 1; i++) {
      *str++ = str1[i];
      *outputCounter += 1;
    }
  } else {
    for (int i = 0; i < shir - strLenght; i++) {
      if (zeroFlag == 1) {
        *str++ = '0';
        *outputCounter += 1;
      } else {
        *str++ = ' ';
        *outputCounter += 1;
      }
    }
    for (int i = 0; i < strLenght; i++) {
      *str++ = str1[i];
      *outputCounter += 1;
    }
  }
}

void whileInDouble(double *newQ, double *q, int *counter, int gFlag, int acc,
                   int counterGE, int *gCounterFlag) {
  while (*newQ != *q) {
    *counter += 1;
    if (*counter == 1) {
      *newQ = *q;
    }
    *newQ = *newQ * 10;
    if (gFlag == 1) {
      if (*counter == acc - counterGE) {
        *newQ = round(*newQ);
        *gCounterFlag = 1;
        break;
      }
    } else {
      if (*counter >= acc) {
        *newQ = round(*newQ);
        break;
      }
    }
    if (*counter > 100 && gFlag == 1) {
      *newQ = *q;
      break;
    }
    if (*counter > 100 && gFlag == 0) {
      *newQ = *q;
    }
  }
}

char *ifsInDouble(char *string2, int gFlag, flagCounter *flagCount, int acc) {
  if (string2[0] == '\0' && gFlag == 0) {
    for (int i = 0; i < acc; i++) {
      string2[i] = '0';
    }
  }
  if (string2[0] == '0' && gFlag == 1 && flagCount->reshFlag == 0) {
    string2[0] = '\0';
  }
  if (gFlag == 1 && flagCount->reshFlag == 0) {
    for (int i = 0; i < (int)s21_strlen(string2); i++) {
      if (string2[i + 1] == '\0') {
        if (string2[i] == '0') {
          string2[i] = '\0';
          i -= 2;
        }
      }
    }
  }
  return string2;
}

void workWithGCounter(long int dInt, long int qInt, int gFlag, int acc,
                      int *gCounter) {
  if (dInt == 0 && qInt == 0 && gFlag == 1 && acc > 6) {
    *gCounter += 1;
  }
}