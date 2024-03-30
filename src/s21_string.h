#ifndef S_21_STRING_H
#define S_21_STRING_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define ERR_MIN 0
#define unsignedInt 4294967295
#define shortUnsignedInt 65535

typedef struct optStruct {
  short int shortD;
  int simpleD;
  long long int longD;
  int *nFunc;
  long int p;
  long long int h;
  long double longG;
  long double longF;
  short unsigned int shortH;
  unsigned int simpleH;
  long unsigned int longH;
  short int shortX;
  int simpleX;
  long int longX;
  double f, e, g;
  long double longE;
  char *strForS;
  long long int x;
} optStruct;

typedef struct flagCounter {
  int startStr;
  int zeroFlag;
  int strCounter;
  int hFlag;
  int lFlag;
  int bigLFlag;
  int plusFlag;
  int charCounter;
  int reshFlag;
  int acc;
  int startNumStr;
  int start;
  int finish;
  int shir;
  int defFlag;
  int spaceCounter;
  int registerLabel;
  char prevch;
  int minCounter;
} flagCounter;

typedef unsigned long int s21_size_t;
#define s21_NULL ((void *)0)

s21_size_t s21_strlen(const char *str);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
int s21_strstrHelper(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
// void init_errors();
char *s21_strerror(int errnum);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int s21_sprintf(char *str, const char *format, ...);
char *intToString(long int d, int acc, char *string);
char *doubleToString(double d, int gFlag, int acc, char *string,
                     flagCounter *flagCount);
char *intToHexadecimalInteger(long int d, int registerLabel, char *string,
                              int acc);
void reverseString(int j, char *string);
char switchRemaind(int remaind, int registerLabel);
char *doubleToE(long double e, int registerLabel, int gFlag, int acc,
                char *string, flagCounter *flagCount);
int numCounter(double g);
char *glueTwoString(char *string1, char *string2, int gFlag, int acc,
                    char *string, long int dInt, long int qInt);
char *deciToOctal(long int o, char *string, int acc);
int decideChar(char ch);
int output(char *str, char *str1, int plusCounter, int reshCounter, int shir,
           int zeroFlag, int defFlag, char ch, int spaceCounter, int minCount,
           int acc);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void initflagCount(flagCounter *flagCount);
void initOptStruct(optStruct *optStr);
int dAndICase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
              char ch, int outputCounter, va_list parametr);
char *outputStrCleaner(char *str, int outputCounter);
int floatCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
              char ch, int outputCounter, va_list parametr);
int charCase(flagCounter *flagCount, char *str, char ch, int outputCounter,
             va_list parametr);
int stringCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
               char ch, int outputCounter, va_list parametr);
int xCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr, char c);
int gCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr, char c, int gCounter);
int eCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr, char c);
int oCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr);
int pCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr);
int uCase(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
          char ch, int outputCounter, va_list parametr);
int percCase(flagCounter *flagCount, char *str, char ch, int outputCounter);
void strChange(char *str1, char *str2);
int switchSpec(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
               char ch, int outputCounter, va_list parametr, char c,
               int finalLenght, int gCounter);
int finalCycle(flagCounter *flagCount, optStruct *optStr, char *str, char *str1,
               char *str2, char ch, int outputCounter, va_list parametr,
               int finalLenght, int gCounter, int j, char *format);
char *specFarc(char *c, char *str2, flagCounter *flagCount, char *ch, int *j);
void flagOpt(char *str2, char c, int *j);
void charSpec(char *str2, char *ch, char c, int *j, flagCounter *flagCount);
void ifSpec(flagCounter *flagCount, char *str2, char c, int *j);
void forInFinalCycle(flagCounter *flagCount, char *str2, va_list parametr,
                     int j);
void decFlag(char *str2, int *i, flagCounter *flagCount, va_list parametr);
void accInInt(int acc, char *string, int *j);
void parseDouble(double *d, double e1, double e2, int gFlag, int acc,
                 double subt);
void workGFlaf(int gFlag, int *dIntLenght, char *string1, long int dInt,
               int acc);
void minInDouble(int *j, int minCount, char *string);
void workWithAcc(int *acc, double *d, int gFlag);
void bigFuncInDouble(long int dInt, long int qInt, char *string1, int acc,
                     int gFlag, char *string, int minCount, int dIntLenght,
                     char *string2);
void elseInBigFunc(char *string1, int gFlag, int dIntLenght, char *string,
                   char *string2, int acc, long int qInt);
void twoIfInDouble(char *string, double dForG, int acc, int gFlag,
                   char *string1);
void workWithE(long double *e, int *counter, int *plusCounter, int acc);
void registerInE(int registerLabel, char *string1, int plusCounter);
void firstFuncInOutput(char *str1, int *minCounter, char ch, int plusCounter,
                       int reshCounter, int *j, int acc);
void secFuncInOutput(char ch, char *str1, int reshCounter, int *j);
void thirdFuncInOutput(char ch, int reshCounter, char *str1, int *j,
                       int spaceCounter, int minCounter);
int startwith(const char *src, const char *totrim, int offset);
int endwith(const char *src, const char *totrim, int offset);
void fourthFuncInOutput(int *outputCounter, char *str, int zeroFlag, int shir,
                        int strLenght, char *str1, int minCount);
void whileInDouble(double *newQ, double *q, int *counter, int gFlag, int acc,
                   int counterGE, int *gCounterFlag);
char *ifsInDouble(char *string2, int gFlag, flagCounter *flagCount, int acc);
void workWithGCounter(long int dInt, long int qInt, int gFlag, int acc,
                      int *gCounter);

#endif  // S_21_STRING_H
