#include <check.h>
#include <string.h>

#include "../s21_string.h"

START_TEST(spec_c) {
  const char ch = 'q';
  char res[10] = {'\0'};
  char myres[10] = {'\0'};
  int res111 = sprintf(res, "%c", ch);
  int res222 = s21_sprintf(myres, "%c", ch);
  ck_assert_int_eq(res111, res222);
  ck_assert_pstr_eq(res, myres);

  char res1[10] = {'\0'};
  char myres1[10] = {'\0'};
  ck_assert_int_eq(sprintf(res1, "%c%c", ch, ch),
                   s21_sprintf(myres1, "%c%c", ch, ch));
  ck_assert_pstr_eq(res1, myres1);

  char res2[10] = {'\0'};
  char myres2[10] = {'\0'};
  ck_assert_int_eq(sprintf(res2, "%c %c", ch, ch),
                   s21_sprintf(myres2, "%c %c", ch, ch));
  ck_assert_pstr_eq(res2, myres2);

  char res3[10] = {'\0'};
  char myres3[10] = {'\0'};
  ck_assert_int_eq(sprintf(res3, "%c     %c", ch, ch),
                   s21_sprintf(myres3, "%c     %c", ch, ch));
  ck_assert_pstr_eq(res3, myres3);

  const char ch1 = '\t';
  char res4[10] = {'\0'};
  char myres4[10] = {'\0'};
  ck_assert_int_eq(sprintf(res4, "%c", ch1), s21_sprintf(myres4, "%c", ch1));
  ck_assert_pstr_eq(res4, myres4);

  const char ch2 = '\0';
  char res5[10] = {'\0'};
  char myres5[10] = {'\0'};
  ck_assert_int_eq(sprintf(res5, "%c%c%c", ch, ch2, ch),
                   s21_sprintf(myres5, "%c%c%c", ch, ch2, ch));
  ck_assert_pstr_eq(res5, myres5);

  const char ch3 = 56;
  char res6[10] = {'\0'};
  char myres6[10] = {'\0'};
  ck_assert_int_eq(sprintf(res6, "%c", ch3), s21_sprintf(myres6, "%c", ch3));
  ck_assert_pstr_eq(res6, myres6);

  const char *ch4 = "r";
  char res7[10] = {'\0'};
  char myres7[10] = {'\0'};
  ck_assert_int_eq(sprintf(res7, "%c", *ch4), s21_sprintf(myres7, "%c", *ch4));
  ck_assert_pstr_eq(res7, myres7);

  const int ch5 = 56;
  char res8[10] = {'\0'};
  char myres8[10] = {'\0'};
  ck_assert_int_eq(sprintf(res8, "%c", ch5), s21_sprintf(myres8, "%c", ch5));
  ck_assert_pstr_eq(res8, myres8);

  const char ch6 = 0;
  char res9[10] = {'\0'};
  char myres9[10] = {'\0'};
  ck_assert_int_eq(sprintf(res9, "%c", ch6), s21_sprintf(myres9, "%c", ch6));
  ck_assert_pstr_eq(res9, myres9);

  const int ch7 = 1;
  char res10[10] = {'\0'};
  char myres10[10] = {'\0'};
  ck_assert_int_eq(sprintf(res10, "%c", ch7), s21_sprintf(myres10, "%c", ch7));
  ck_assert_pstr_eq(res10, myres10);
}
END_TEST

START_TEST(spec_d) {
  const int num = 5;
  char res[3] = {'\0'};
  char myres[3] = {'\0'};
  ck_assert_int_eq(sprintf(res, "%d", num), s21_sprintf(myres, "%d", num));
  ck_assert_pstr_eq(res, myres);

  const int num1 = 99;
  char res1[3] = {'\0'};
  char myres1[3] = {'\0'};
  ck_assert_int_eq(sprintf(res1, "%d", num1), s21_sprintf(myres1, "%d", num1));
  ck_assert_pstr_eq(res1, myres1);

  const int num2 = -1;
  char res2[3] = {'\0'};
  char myres2[3] = {'\0'};
  ck_assert_int_eq(sprintf(res2, "%d", num2), s21_sprintf(myres2, "%d", num2));
  ck_assert_pstr_eq(res2, myres2);

  const int num3 = -10;
  char res3[4] = {'\0'};
  char myres3[4] = {'\0'};
  ck_assert_int_eq(sprintf(res3, "%d", num3), s21_sprintf(myres3, "%d", num3));
  ck_assert_pstr_eq(res3, myres3);

  char res4[5] = {'\0'};
  char myres4[5] = {'\0'};
  ck_assert_int_eq(sprintf(res4, "%d%d", num, num2),
                   s21_sprintf(myres4, "%d%d", num, num2));
  ck_assert_pstr_eq(res4, myres4);

  char res5[7] = {'\0'};
  char myres5[7] = {'\0'};
  ck_assert_int_eq(sprintf(res5, "%d   %d", num, num),
                   s21_sprintf(myres5, "%d   %d", num, num));
  ck_assert_pstr_eq(res5, myres5);

  const char num4 = '8';
  char res6[7] = {'\0'};
  char myres6[7] = {'\0'};
  ck_assert_int_eq(sprintf(res6, "%d", num4), s21_sprintf(myres6, "%d", num4));
  ck_assert_pstr_eq(res6, myres6);

  const char num5 = 0;
  char res7[10] = {'\0'};
  char myres7[10] = {'\0'};
  ck_assert_int_eq(sprintf(res7, "%d", num5), s21_sprintf(myres7, "%d", num5));
  ck_assert_pstr_eq(res7, myres7);

  const int num6 = 0;
  char res8[10] = {'\0'};
  char myres8[10] = {'\0'};
  ck_assert_int_eq(sprintf(res8, "%d", num6), s21_sprintf(myres8, "%d", num6));
  ck_assert_pstr_eq(res8, myres8);

  const int num8 = 5;
  char res10[10] = {'\0'};
  char myres10[10] = {'\0'};
  ck_assert_int_eq(sprintf(res10, "%d", num8),
                   s21_sprintf(myres10, "%d", num8));
  ck_assert_pstr_eq(res10, myres10);

  const int num9 = 05;
  char res11[10] = {'\0'};
  char myres11[10] = {'\0'};
  ck_assert_int_eq(sprintf(res11, "%d", num9),
                   s21_sprintf(myres11, "%d", num9));
  ck_assert_pstr_eq(res11, myres11);

  const short int num10[] = {5, 32767, -32767};
  char res12[3][10] = {{'\0'}};
  char myres12[3][10] = {{'\0'}};
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(sprintf(res12[i], "%hd", num10[i]),
                     s21_sprintf(myres12[i], "%hd", num10[i]));
    ck_assert_pstr_eq(res12[i], myres12[i]);
  }
  const long int num11[] = {5, 32767, -32767, 2147483647, -2147483647};
  char res13[5][10] = {{'\0'}};
  char myres13[5][10] = {{'\0'}};
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(res13[i], "%ld", num11[i]),
                     s21_sprintf(myres13[i], "%ld", num11[i]));
    ck_assert_pstr_eq(res13[i], myres13[i]);
  }
}
END_TEST

START_TEST(spec_i) {
  const int num = 5;
  char res[3] = {0};
  char myres[3] = {0};
  ck_assert_int_eq(sprintf(res, "%i", num), s21_sprintf(myres, "%i", num));
  ck_assert_pstr_eq(res, myres);

  const int num1 = 99;
  char res1[3] = {0};
  char myres1[3] = {0};
  ck_assert_int_eq(sprintf(res1, "%i", num1), s21_sprintf(myres1, "%i", num1));
  ck_assert_pstr_eq(res1, myres1);

  const int num2 = -1;
  char res2[3] = {0};
  char myres2[3] = {0};
  ck_assert_int_eq(sprintf(res2, "%i", num2), s21_sprintf(myres2, "%i", num2));
  ck_assert_pstr_eq(res2, myres2);

  const int num3 = -10;
  char res3[4] = {0};
  char myres3[4] = {0};
  ck_assert_int_eq(sprintf(res3, "%i", num3), s21_sprintf(myres3, "%i", num3));
  ck_assert_pstr_eq(res3, myres3);

  char res4[5] = {0};
  char myres4[5] = {0};
  ck_assert_int_eq(sprintf(res4, "%i%i", num, num2),
                   s21_sprintf(myres4, "%i%i", num, num2));
  ck_assert_pstr_eq(res4, myres4);

  char res5[7] = {0};
  char myres5[7] = {0};
  ck_assert_int_eq(sprintf(res5, "%i   %i", num, num),
                   s21_sprintf(myres5, "%i   %i", num, num));
  ck_assert_pstr_eq(res5, myres5);

  const char num4 = '8';
  char res6[7] = {0};
  char myres6[7] = {0};
  ck_assert_int_eq(sprintf(res6, "%i", num4), s21_sprintf(myres6, "%i", num4));
  ck_assert_pstr_eq(res6, myres6);

  const char num5 = 0;
  char res7[10] = {0};
  char myres7[10] = {0};
  ck_assert_int_eq(sprintf(res7, "%i", num5), s21_sprintf(myres7, "%i", num5));
  ck_assert_pstr_eq(res7, myres7);

  const int num6 = 0;
  char res8[10] = {0};
  char myres8[10] = {0};
  ck_assert_int_eq(sprintf(res8, "%i", num6), s21_sprintf(myres8, "%i", num6));
  ck_assert_pstr_eq(res8, myres8);

  const int num8 = 5;
  char res10[10] = {0};
  char myres10[10] = {0};
  ck_assert_int_eq(sprintf(res10, "%i", num8),
                   s21_sprintf(myres10, "%i", num8));
  ck_assert_pstr_eq(res10, myres10);

  const int num9 = 0x4, num10 = 0xf, num11 = 0x64, num12 = 017, num13 = 0144,
            num14 = 30;
  char res11[10], res12[10], res13[10], res14[10], res15[10], res16[10];
  char myres11[10], myres12[10], myres13[10], myres14[10], myres15[10],
      myres16[10];
  ck_assert_int_eq(sprintf(res11, "%i", num9),
                   s21_sprintf(myres11, "%i", num9));
  ck_assert_int_eq(sprintf(res12, "%i", num10),
                   s21_sprintf(myres12, "%i", num10));
  ck_assert_int_eq(sprintf(res13, "%i", num11),
                   s21_sprintf(myres13, "%i", num11));
  ck_assert_int_eq(sprintf(res14, "%i", num12),
                   s21_sprintf(myres14, "%i", num12));
  ck_assert_int_eq(sprintf(res15, "%i", num13),
                   s21_sprintf(myres15, "%i", num13));
  ck_assert_pstr_eq(res11, myres11);
  ck_assert_pstr_eq(res12, myres12);
  ck_assert_pstr_eq(res13, myres13);
  ck_assert_pstr_eq(res14, myres14);
  ck_assert_pstr_eq(res15, myres15);
  ck_assert_int_eq(sprintf(res16, "%i%i%i", num9, num12, num14),
                   s21_sprintf(myres16, "%i%i%i", num9, num12, num14));
  ck_assert_pstr_eq(res16, myres16);

  const short int num_arr[] = {5, 32767, -32767, 3.2, 3.5666666666};
  char res_arr[5][10];
  char myres_arr[5][10];
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%hi", num_arr[i]),
                     s21_sprintf(myres_arr[i], "%hi", num_arr[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }
  const long int num_arr1[] = {5,           32767, -32767,      2147483647,
                               -2147483647, 3.2,   3.5666666666};
  char res_arr1[7][10];
  char myres_arr1[7][10];
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res_arr1[i], "%li", num_arr1[i]),
                     s21_sprintf(myres_arr1[i], "%li", num_arr1[i]));
    ck_assert_pstr_eq(res_arr1[i], myres_arr1[i]);
  }
}
END_TEST

START_TEST(spec_f) {
  const float num = 5;
  char res[30];
  char myres[30];
  ck_assert_int_eq(sprintf(res, "%f", num), s21_sprintf(myres, "%f", num));
  ck_assert_pstr_eq(res, myres);

  //  ck_assert_int_eq(sprintf(res, "%.f", 10.33333333),
  //                   s21_sprintf(myres, "%.f", 10.33333333));
  //  ck_assert_pstr_eq(res, myres);

  const float num1 = 99;
  char res1[30];
  char myres1[30];
  ck_assert_int_eq(sprintf(res1, "%f", num1), s21_sprintf(myres1, "%f", num1));
  ck_assert_pstr_eq(res1, myres1);

  const float num2 = -1;
  char res2[30];
  char myres2[30];
  ck_assert_int_eq(sprintf(res2, "%f", num2), s21_sprintf(myres2, "%f", num2));
  ck_assert_pstr_eq(res2, myres2);

  const float num3 = -10;
  char res3[30];
  char myres3[30];
  ck_assert_int_eq(sprintf(res3, "%f", num3), s21_sprintf(myres3, "%f", num3));
  ck_assert_pstr_eq(res3, myres3);

  char res4[50];
  char myres4[50];
  ck_assert_int_eq(sprintf(res4, "%f%f", num, num2),
                   s21_sprintf(myres4, "%f%f", num, num2));
  ck_assert_pstr_eq(res4, myres4);

  char res5[40];
  char myres5[40];
  ck_assert_int_eq(sprintf(res5, "%f   %f", num, num),
                   s21_sprintf(myres5, "%f   %f", num, num));
  ck_assert_pstr_eq(res5, myres5);

  const double num4 = 8;
  char res6[30];
  char myres6[30];
  ck_assert_int_eq(sprintf(res6, "%f", num4), s21_sprintf(myres6, "%f", num4));
  ck_assert_pstr_eq(res6, myres6);

  const double num5 = 0;
  char res7[30];
  char myres7[30];
  ck_assert_int_eq(sprintf(res7, "%f", num5), s21_sprintf(myres7, "%f", num5));
  ck_assert_pstr_eq(res7, myres7);

  const float num6 = 0;
  char res8[30];
  char myres8[30];
  ck_assert_int_eq(sprintf(res8, "%f", num6), s21_sprintf(myres8, "%f", num6));
  ck_assert_pstr_eq(res8, myres8);

  const float num9 = 0x4, num10 = 0xf, num11 = 0x64, num12 = 017, num13 = 0144,
              num14 = 30;
  char res11[40], res12[40], res13[40], res14[40], res15[40], res16[40];
  char myres11[40], myres12[40], myres13[40], myres14[40], myres15[40],
      myres16[40];
  ck_assert_int_eq(sprintf(res11, "%f", num9),
                   s21_sprintf(myres11, "%f", num9));
  ck_assert_int_eq(sprintf(res12, "%f", num10),
                   s21_sprintf(myres12, "%f", num10));
  ck_assert_int_eq(sprintf(res13, "%f", num11),
                   s21_sprintf(myres13, "%f", num11));
  ck_assert_int_eq(sprintf(res14, "%f", num12),
                   s21_sprintf(myres14, "%f", num12));
  ck_assert_int_eq(sprintf(res15, "%f", num13),
                   s21_sprintf(myres15, "%f", num13));
  ck_assert_pstr_eq(res11, myres11);
  ck_assert_pstr_eq(res12, myres12);
  ck_assert_pstr_eq(res13, myres13);
  ck_assert_pstr_eq(res14, myres14);
  ck_assert_pstr_eq(res15, myres15);
  ck_assert_int_eq(sprintf(res16, "%f%f%f", num9, num12, num14),
                   s21_sprintf(myres16, "%f%f%f", num9, num12, num14));
  ck_assert_pstr_eq(res16, myres16);

  const float num15 = 5.5, num16 = 2.0003, num17 = 3.00000005;
  char res19[30], res17[30], res18[30];
  char myres19[30], myres17[30], myres18[30];
  ck_assert_int_eq(sprintf(res19, "%f", num15),
                   s21_sprintf(myres19, "%f", num15));
  ck_assert_int_eq(sprintf(res17, "%f", num16),
                   s21_sprintf(myres17, "%f", num16));
  ck_assert_int_eq(sprintf(res18, "%f", num17),
                   s21_sprintf(myres18, "%f", num17));
  ck_assert_pstr_eq(res19, myres19);
  ck_assert_pstr_eq(res17, myres17);
  ck_assert_pstr_eq(res18, myres18);

  ck_assert_int_eq(sprintf(res19, "%#f", num15),
                   s21_sprintf(myres19, "%#f", num15));
  ck_assert_int_eq(sprintf(res19, "%#+-.15f", num15),
                   s21_sprintf(myres19, "%#+-.15f", num15));
  ck_assert_int_eq(sprintf(res19, "%#f", num17),
                   s21_sprintf(myres19, "%#f", num17));
  ck_assert_int_eq(sprintf(res19, "%#+-.15f", num17),
                   s21_sprintf(myres19, "%#+-.15f", num17));

  const long double nums[] = {5.5, 2.0003, 3.00000005};
  char res_arr[5][10];
  char myres_arr[5][10];
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%Lf", nums[i]),
                     s21_sprintf(myres_arr[i], "%Lf", nums[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }
  const long double nums1[] = {5, 32767, -32767, 2147483647, -2147483647};
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%Lf", nums1[i]),
                     s21_sprintf(myres_arr[i], "%Lf", nums1[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }
}
END_TEST

START_TEST(spec_s) {
  char str1[][100] = {"123456",
                      "qwerty",
                      "",
                      "ASDFGg",
                      "!@#$%^&*()",
                      "\\",
                      "End\0sfdgs",
                      "End\0\nsfdgs",
                      "End\0\tsfdgs",
                      "End\nsfdgs",
                      "Endsfdgs\0\0\0",
                      "Endsfdgs\\n\n",
                      "End\"sfdgs\"",
                      "Endsfdgs\n",
                      "Я программист",
                      "Я программист12324354",
                      "копирование выполнено успешно\n",
                      "копирован\nие",
                      "копирован%%ие",
                      "[0-9]",
                      "^int\\d",
                      "\33[0d\33[2j",
                      "\x1b\x5b\x48\x1b\x5b\x32\x4a\\c",
                      "|.[H.[J|",
                      "|.+|",
                      "|.&a0y0C.J|",
                      "|  .1        .1  |",
                      "\x1b[2J",
                      "\0\a\b\t\n\v\f\r\e",
                      "\0\a\b\t\n\v\f\r\esa",
                      "0xA8",
                      "a BS ^",
                      "\tasd"};

  for (size_t i = 0; i < 33; i++) {
    char str2[100] = "";
    char str22[100] = "";
    ck_assert_int_eq(sprintf(str2, "%.1s", str1[i]),
                     s21_sprintf(str22, "%.1s", str1[i]));
    ck_assert_pstr_eq(str2, str22);
    ck_assert_mem_eq(str2, str22, 100);

    char str3[100] = "";
    char str33[100] = "";
    ck_assert_int_eq(sprintf(str3, "%s", str1[i]),
                     s21_sprintf(str33, "%s", str1[i]));
    ck_assert_pstr_eq(str3, str33);
    ck_assert_mem_eq(str3, str33, 100);

    char str4[110] = "";
    char str44[110] = "";
    ck_assert_int_eq(sprintf(str4, "%s", str1[i]),
                     s21_sprintf(str44, "%s", str1[i]));
    ck_assert_pstr_eq(str4, str44);
    ck_assert_mem_eq(str4, str44, 110);
  }
  char str5[30] = "no";
  char str55[30] = "no";
  char str6[50] = "yes, i want succes!!!";
  char str66[50] = "yes, i want succes!!!";
  char str7[100] = "";
  char str77[100] = "";
  ck_assert_int_eq(sprintf(str7, "%s%s", str5, str6),
                   s21_sprintf(str77, "%s%s", str55, str66));
  ck_assert_pstr_eq(str7, str77);
  ck_assert_mem_eq(str7, str77, 50);
}
END_TEST

START_TEST(spec_u) {
  const int num = 5;
  char res[3];
  char myres[3];
  ck_assert_int_eq(sprintf(res, "%u", num), s21_sprintf(myres, "%u", num));
  ck_assert_pstr_eq(res, myres);

  const unsigned int num1 = 99;
  char res1[3];
  char myres1[3];
  ck_assert_int_eq(sprintf(res1, "%u", num1), s21_sprintf(myres1, "%u", num1));
  ck_assert_pstr_eq(res1, myres1);

  char res4[5];
  char myres4[5];
  ck_assert_int_eq(sprintf(res4, "%u%u", num, num1),
                   s21_sprintf(myres4, "%u%u", num, num1));
  ck_assert_pstr_eq(res4, myres4);

  char res5[7];
  char myres5[7];
  ck_assert_int_eq(sprintf(res5, "%u   %u", num, num),
                   s21_sprintf(myres5, "%u   %u", num, num));
  ck_assert_pstr_eq(res5, myres5);

  const char num5 = 0;
  char res7[10];
  char myres7[10];
  ck_assert_int_eq(sprintf(res7, "%u", num5), s21_sprintf(myres7, "%u", num5));
  ck_assert_pstr_eq(res7, myres7);

  const int num6 = 0;
  char res8[10];
  char myres8[10];
  ck_assert_int_eq(sprintf(res8, "%u", num6), s21_sprintf(myres8, "%u", num6));
  ck_assert_pstr_eq(res8, myres8);

  const unsigned int num8 = 5;
  char res10[10];
  char myres10[10];
  ck_assert_int_eq(sprintf(res10, "%u", num8),
                   s21_sprintf(myres10, "%u", num8));
  ck_assert_pstr_eq(res10, myres10);

  const int num9 = 05;
  char res11[10];
  char myres11[10];
  ck_assert_int_eq(sprintf(res11, "%u", num9),
                   s21_sprintf(myres11, "%u", num9));
  ck_assert_pstr_eq(res11, myres11);

  const unsigned long int num10 = 12;
  char res12[10];
  char myres12[10];
  ck_assert_int_eq(sprintf(res12, "%lu", num10),
                   s21_sprintf(myres12, "%lu", num10));
  ck_assert_pstr_eq(res12, myres12);

  const unsigned short int num_arr[] = {0, 5, 32767, 65535};
  char res_arr[4][10];
  char myres_arr[4][10];
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%hi", num_arr[i]),
                     s21_sprintf(myres_arr[i], "%hi", num_arr[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }
  const unsigned long int num_arr1[] = {0, 5, 32767, 2147483647, 4294967295};
  char res_arr1[5][10];
  char myres_arr1[5][10];
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(res_arr1[i], "%li", num_arr1[i]),
                     s21_sprintf(myres_arr1[i], "%li", num_arr1[i]));
    ck_assert_pstr_eq(res_arr1[i], myres_arr1[i]);
  }
}
END_TEST

START_TEST(spec_procent) {
  char res[10];
  char myres[10];
  ck_assert_int_eq(sprintf(res, "%%"), s21_sprintf(myres, "%%"));
  ck_assert_pstr_eq(res, myres);

  ck_assert_int_eq(sprintf(res, "%%%%"), s21_sprintf(myres, "%%%%"));
  ck_assert_pstr_eq(res, myres);
}
END_TEST

START_TEST(varia0) {
  const char ch = 'q';
  const int num = 5, num1 = -5, num2 = 0, num3 = -0;
  const int in = 0x4, in2 = 0144, in3 = -0144;
  const float fl1 = 3.2, fl2 = 4.000000006, fl3 = -3.2;
  const char *str = "text";

  char res[60][40] = {{'\0'}};
  char myres[60][40] = {{'\0'}};
  int i = 0;
  ck_assert_int_eq(sprintf(res[i], "%10s|", str),
                   s21_sprintf(myres[i], "%10s|", str));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%10c|", ch),
                   s21_sprintf(myres[i], "%10c|", ch));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%10d|", num),
                   s21_sprintf(myres[i], "%10d|", num));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%10f|", fl1),
                   s21_sprintf(myres[i], "%10f|", fl1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%10f|", fl2),
                   s21_sprintf(myres[i], "%10f|", fl2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%10u|", in),
                   s21_sprintf(myres[i], "%10u|", in));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;

  ck_assert_int_eq(sprintf(res[i], "%-10s|", str),
                   s21_sprintf(myres[i], "%-10s|", str));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10c|", ch),
                   s21_sprintf(myres[i], "%-10c|", ch));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10d|", num),
                   s21_sprintf(myres[i], "%-10d|", num));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10f|", fl1),
                   s21_sprintf(myres[i], "%-10f|", fl1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;

  ck_assert_int_eq(sprintf(res[i], "%-+10d|", num),
                   s21_sprintf(myres[i], "%-+10d|", num));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10d|", num1),
                   s21_sprintf(myres[i], "%-+10d|", num1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10d|", num2),
                   s21_sprintf(myres[i], "%-+10d|", num2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10d|", num3),
                   s21_sprintf(myres[i], "%-+10d|", num3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+5f|", fl1),
                   s21_sprintf(myres[i], "%-+5f|", fl1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+5f|", fl2),
                   s21_sprintf(myres[i], "%-+5f|", fl2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+5f|", fl3),
                   s21_sprintf(myres[i], "%-+5f|", fl3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%u|", in),
                   s21_sprintf(myres[i], "%u|", in));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%u|", in2),
                   s21_sprintf(myres[i], "%u|", in2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-u|", in3),
                   s21_sprintf(myres[i], "%-u|", in3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%10u|", in3),
                   s21_sprintf(myres[i], "%10u|", in3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;

  ck_assert_int_eq(sprintf(res[i], "% d|", num),
                   s21_sprintf(myres[i], "% d|", num));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "% d|", num1),
                   s21_sprintf(myres[i], "% d|", num1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "% d|", num2),
                   s21_sprintf(myres[i], "% d|", num2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "% d|", num3),
                   s21_sprintf(myres[i], "% d|", num3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "% f|", fl1),
                   s21_sprintf(myres[i], "% f|", fl1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "% f|", fl2),
                   s21_sprintf(myres[i], "% f|", fl2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "% f|", fl3),
                   s21_sprintf(myres[i], "% f|", fl3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%u|", in),
                   s21_sprintf(myres[i], "%u|", in));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%u|", in3),
                   s21_sprintf(myres[i], "%u|", in3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;

  ck_assert_int_eq(sprintf(res[i], "%-+10.3d|", num),
                   s21_sprintf(myres[i], "%-+10.3d|", num));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.3d|", num1),
                   s21_sprintf(myres[i], "%-+10.3d|", num1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.3d|", num2),
                   s21_sprintf(myres[i], "%-+10.3d|", num2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.3d|", num3),
                   s21_sprintf(myres[i], "%-+10.3d|", num3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.3f|", fl1),
                   s21_sprintf(myres[i], "%-+10.3f|", fl1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.3f|", fl2),
                   s21_sprintf(myres[i], "%-+10.3f|", fl2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.3f|", fl3),
                   s21_sprintf(myres[i], "%-+10.3f|", fl3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.3u|", in),
                   s21_sprintf(myres[i], "%-10.3u|", in));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.3u|", in2),
                   s21_sprintf(myres[i], "%-10.3u|", in2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.3u|", in3),
                   s21_sprintf(myres[i], "%-10.3u|", in3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.15d|", num),
                   s21_sprintf(myres[i], "%-+10.15d|", num));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.15d|", num1),
                   s21_sprintf(myres[i], "%-+10.15d|", num1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.15d|", num2),
                   s21_sprintf(myres[i], "%-+10.15d|", num2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.15d|", num3),
                   s21_sprintf(myres[i], "%-+10.15d|", num3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.15f|", fl1),
                   s21_sprintf(myres[i], "%-+10.15f|", fl1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.15f|", fl2),
                   s21_sprintf(myres[i], "%-+10.15f|", fl2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.15f|", fl3),
                   s21_sprintf(myres[i], "%-+10.15f|", fl3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.15u|", in),
                   s21_sprintf(myres[i], "%-10.15u|", in));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.15u|", in2),
                   s21_sprintf(myres[i], "%-10.15u|", in2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.15u|", in3),
                   s21_sprintf(myres[i], "%-10.15u|", in3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;

  ck_assert_int_eq(sprintf(res[i], "%-+10.*d|", 5, num),
                   s21_sprintf(myres[i], "%-+10.*d|", 5, num));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.*d|", 5, num1),
                   s21_sprintf(myres[i], "%-+10.*d|", 5, num1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.*d|", 5, num2),
                   s21_sprintf(myres[i], "%-+10.*d|", 5, num2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.*d|", 5, num3),
                   s21_sprintf(myres[i], "%-+10.*d|", 5, num3));
  ck_assert_pstr_eq(res[i], myres[i]);
}
END_TEST

START_TEST(varia) {
  const int num = 5, num1 = -5, num2 = 0, num3 = -0;
  const int in = 0x4, in2 = 0144, in3 = -0144;
  const float fl1 = 3.2, fl2 = 4.000000006, fl3 = -3.2;

  char res[60][40] = {{'\0'}};
  char myres[60][40] = {{'\0'}};
  int i = 0;

  ck_assert_int_eq(sprintf(res[i], "%-+10.*f|", 5, fl1),
                   s21_sprintf(myres[i], "%-+10.*f|", 5, fl1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.*f|", 5, fl2),
                   s21_sprintf(myres[i], "%-+10.*f|", 5, fl2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%.*f|", 5, fl3),
                   s21_sprintf(myres[i], "%.*f|", 5, fl3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.*u|", 5, in),
                   s21_sprintf(myres[i], "%-10.*u|", 5, in));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.*u|", 5, in2),
                   s21_sprintf(myres[i], "%-10.*u|", 5, in2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.*u|", 5, in3),
                   s21_sprintf(myres[i], "%-10.*u|", 5, in3));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.*d|", 0, num),
                   s21_sprintf(myres[i], "%-10.*d|", 0, num));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-+10.*d|", 0, num1),
                   s21_sprintf(myres[i], "%-+10.*d|", 0, num1));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%.*d", 0, num2),
                   s21_sprintf(myres[i], "%.*d", 0, num2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%*d|", 0, num2),
                   s21_sprintf(myres[i], "%*d|", 0, num2));
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%0*d|", 0, num3),
                   s21_sprintf(myres[i], "%0*d|", 0, num3));
  ck_assert_pstr_eq(res[i], myres[i]);
}
END_TEST

START_TEST(spec_g) {
  double nums[] = {1e16, -1e16,    1E16, -1E16,         0,
                   10,   15000100, 3.2,  5.66666666666, 123.12432527};
  char res[10][40] = {0};
  char myres[10][40] = {0};
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%g", nums[i]),
                     s21_sprintf(myres[i], "%g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "% g", nums[i]),
                     s21_sprintf(myres[i], "% g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%10g|", nums[i]),
                     s21_sprintf(myres[i], "%10g|", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10g|", nums[i]),
                     s21_sprintf(myres[i], "%-10g|", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-g", nums[i]),
                     s21_sprintf(myres[i], "%+-g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-.3g", nums[i]),
                     s21_sprintf(myres[i], "%+-.3g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+.15g", nums[i]),
                     s21_sprintf(myres[i], "%+.15g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#+-.15g", nums[i]),
                     s21_sprintf(myres[i], "%#+-.15g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%0g", nums[i]),
                     s21_sprintf(myres[i], "%0g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%015g", nums[i]),
                     s21_sprintf(myres[i], "%015g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%0#+.15g", nums[i]),
                     s21_sprintf(myres[i], "%0#+.15g", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%0#+*.15g", 3, nums[i]),
                     s21_sprintf(myres[i], "%0#+*.15g", 3, nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%G", nums[i]),
                     s21_sprintf(myres[i], "%G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "% G", nums[i]),
                     s21_sprintf(myres[i], "% G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%10G|", nums[i]),
                     s21_sprintf(myres[i], "%10G|", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10G|", nums[i]),
                     s21_sprintf(myres[i], "%-10G|", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-G", nums[i]),
                     s21_sprintf(myres[i], "%+-G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-.3G", nums[i]),
                     s21_sprintf(myres[i], "%+-.3G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-.15G", nums[i]),
                     s21_sprintf(myres[i], "%+-.15G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#+-.15G", nums[i]),
                     s21_sprintf(myres[i], "%#+-.15G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%0G", nums[i]),
                     s21_sprintf(myres[i], "%0G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%015G", nums[i]),
                     s21_sprintf(myres[i], "%015G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%0#+.15G", nums[i]),
                     s21_sprintf(myres[i], "%0#+.15G", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  long double num_long = 10.0;
  ck_assert_int_eq(sprintf(res[0], "%LG", num_long),
                   s21_sprintf(myres[0], "%LG", num_long));
  ck_assert_pstr_eq(res[0], myres[0]);

  float num_ = -0.1;
  ck_assert_int_eq(sprintf(res[0], "%G", num_),
                   s21_sprintf(myres[0], "%G", num_));
  ck_assert_pstr_eq(res[0], myres[0]);
}
END_TEST

START_TEST(spec_e) {
  float nums[] = {1e16, -1e16,      1E16, -1E16,         0,
                  10,   1500000000, 3.2,  5.66666666666, 123.12432523};
  char res[10][40] = {{'\0'}};
  char myres[10][40] = {{'\0'}};
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%e", nums[i]),
                     s21_sprintf(myres[i], "%e", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }

  ck_assert_int_eq(sprintf(res[0], "%.e", 10.33333333),
                   s21_sprintf(myres[0], "%.e", 10.33333333));
  ck_assert_pstr_eq(res[0], myres[0]);

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "% e", nums[i]),
                     s21_sprintf(myres[i], "% e", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%10e|", nums[i]),
                     s21_sprintf(myres[i], "%10e|", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10e|", nums[i]),
                     s21_sprintf(myres[i], "%-10e|", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-e", nums[i]),
                     s21_sprintf(myres[i], "%+-e", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-.3e", nums[i]),
                     s21_sprintf(myres[i], "%+-.3e", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-.15e", nums[i]),
                     s21_sprintf(myres[i], "%+-.15e", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#+-.15e", nums[i]),
                     s21_sprintf(myres[i], "%#+-.15e", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#e", nums[i]),
                     s21_sprintf(myres[i], "%#e", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }

  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%E", nums[i]),
                     s21_sprintf(myres[i], "%E", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "% E", nums[i]),
                     s21_sprintf(myres[i], "% E", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%10E|", nums[i]),
                     s21_sprintf(myres[i], "%10E|", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10E|", nums[i]),
                     s21_sprintf(myres[i], "%-10E|", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-E", nums[i]),
                     s21_sprintf(myres[i], "%+-E", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-.3E", nums[i]),
                     s21_sprintf(myres[i], "%+-.3E", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%+-.15E", nums[i]),
                     s21_sprintf(myres[i], "%+-.15E", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#+-.15E", nums[i]),
                     s21_sprintf(myres[i], "%#+-.15E", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#E", nums[i]),
                     s21_sprintf(myres[i], "%#E", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
}
END_TEST

START_TEST(spec_x) {
  int nums[] = {0xff, 1111, 0x1111, 0xca, 0x73, 4, 0, 0xFF, 0xCA};
  char res[9][40] = {{'\0'}};
  char myres[9][40] = {{'\0'}};

  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%x", nums[i]),
                     s21_sprintf(myres[i], "%x", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%10x", nums[i]),
                     s21_sprintf(myres[i], "%10x", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10x", nums[i]),
                     s21_sprintf(myres[i], "%-10x", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10x", nums[i]),
                     s21_sprintf(myres[i], "%-10x", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10.3x", nums[i]),
                     s21_sprintf(myres[i], "%-10.3x", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10.15x", nums[i]),
                     s21_sprintf(myres[i], "%-10.15x", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#x", nums[i]),
                     s21_sprintf(myres[i], "%#x", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#-10.15x", nums[i]),
                     s21_sprintf(myres[i], "%#-10.15x", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }

  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%X", nums[i]),
                     s21_sprintf(myres[i], "%X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%X", nums[i]),
                     s21_sprintf(myres[i], "%X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%10X", nums[i]),
                     s21_sprintf(myres[i], "%10X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10X", nums[i]),
                     s21_sprintf(myres[i], "%-10X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10X", nums[i]),
                     s21_sprintf(myres[i], "%-10X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10.3X", nums[i]),
                     s21_sprintf(myres[i], "%-10.3X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10.15X", nums[i]),
                     s21_sprintf(myres[i], "%-10.15X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#X", nums[i]),
                     s21_sprintf(myres[i], "%#X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#-10.15X", nums[i]),
                     s21_sprintf(myres[i], "%#-10.15X", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#-10.*X", 10, nums[i]),
                     s21_sprintf(myres[i], "%#-10.*X", 10, nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }

  char res_arr[9][10] = {{'\0'}};
  char myres_arr[9][10] = {{'\0'}};
  for (int i = 0; i < 9; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%hx", nums[i]),
                     s21_sprintf(myres_arr[i], "%hx", nums[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }

  const long int nums1[] = {5, 32767, -32767, 2147483647, -2147483647};
  const short int nums2[] = {5, 32767, -32767};
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%hx", nums2[i]),
                     s21_sprintf(myres_arr[i], "%hx", nums2[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%lx", nums1[i]),
                     s21_sprintf(myres_arr[i], "%lx", nums1[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }

  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%lX", nums1[i]),
                     s21_sprintf(myres_arr[i], "%lX", nums1[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }
  for (int i = 0; i < 3; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%hX", nums2[i]),
                     s21_sprintf(myres_arr[i], "%hX", nums2[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }
  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(res_arr[i], "%lX", nums1[i]),
                     s21_sprintf(myres_arr[i], "%lX", nums1[i]));
    ck_assert_pstr_eq(res_arr[i], myres_arr[i]);
  }
}
END_TEST

START_TEST(spec_o) {
  int nums[] = {077, 1111, 01111, 01, 4, 0, 100};
  char res[7][40];
  char myres[7][40];

  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%o", nums[i]),
                     s21_sprintf(myres[i], "%o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%o", nums[i]),
                     s21_sprintf(myres[i], "%o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%10o", nums[i]),
                     s21_sprintf(myres[i], "%10o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10o", nums[i]),
                     s21_sprintf(myres[i], "%-10o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10.3o", nums[i]),
                     s21_sprintf(myres[i], "%-10.3o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10.15o", nums[i]),
                     s21_sprintf(myres[i], "%-10.15o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#o", nums[i]),
                     s21_sprintf(myres[i], "%#o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%#-10.15o", nums[i]),
                     s21_sprintf(myres[i], "%#-10.15o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%0o", nums[i]),
                     s21_sprintf(myres[i], "%0o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%.15o", nums[i]),
                     s21_sprintf(myres[i], "%.15o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (int i = 0; i < 7; i++) {
    ck_assert_int_eq(sprintf(res[i], "%-10.15o", nums[i]),
                     s21_sprintf(myres[i], "%-10.15o", nums[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
}
END_TEST

START_TEST(spec_n) {
  const int num = 077;

  char res[5][40];
  int n = 0;
  char myres[5][40];
  int myn = 0;
  int i = 0;

  ck_assert_int_eq(sprintf(res[i], "Hello, %nworld!", &n),
                   s21_sprintf(myres[i], "Hello, %nworld!", &myn));
  ck_assert_int_eq(n, myn);
  ck_assert_pstr_eq(res[i], myres[i]);
  i++;
  ck_assert_int_eq(sprintf(res[i], "Hello, world!%c%n", '\0', &n),
                   s21_sprintf(myres[i], "Hello, world!%c%n", '\0', &myn));
  ck_assert_pstr_eq(res[i], myres[i]);
  ck_assert_int_eq(n, myn);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%nHello, world!", &n),
                   s21_sprintf(myres[i], "%nHello, world!", &myn));
  ck_assert_pstr_eq(res[i], myres[i]);
  ck_assert_int_eq(n, myn);
  i++;
  ck_assert_int_eq(sprintf(res[i], "%-10.15o%nsd", num, &n),
                   s21_sprintf(myres[i], "%-10.15o%nsd", num, &myn));
  ck_assert_pstr_eq(res[i], myres[i]);
  ck_assert_int_eq(n, myn);
  i++;
  ck_assert_int_eq(sprintf(res[i], "Hello,%n world!", &n),
                   s21_sprintf(myres[i], "Hello,%n world!", &myn));
  ck_assert_pstr_eq(res[i], myres[i]);
  ck_assert_int_eq(n, myn);
}
END_TEST

START_TEST(spec_p) {
  const char ch[] = {'q', '\t', '\0'};
  const int num[] = {5, -5, 0, -0, 150000000};
  const int in[] = {0x4, 0xf, 0144, -0144};
  const float fl[] = {2, 3.2, 4.000000006, -3.2};
  const char *str = "text";

  char res[9][40];
  char myres[9][40];
  int i = 0;

  for (i = 0; i < 3; i++) {
    ck_assert_int_eq(sprintf(res[i], "%p", &ch[i]),
                     s21_sprintf(myres[i], "%p", &ch[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (i = 0; i < 5; i++) {
    ck_assert_int_eq(sprintf(res[i], "%p", &num[i]),
                     s21_sprintf(myres[i], "%p", &num[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (i = 0; i < 4; i++) {
    ck_assert_int_eq(sprintf(res[i], "%p", &in[i]),
                     s21_sprintf(myres[i], "%p", &in[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  for (i = 0; i < 4; i++) {
    ck_assert_int_eq(sprintf(res[i], "%p", &fl[i]),
                     s21_sprintf(myres[i], "%p", &fl[i]));
    ck_assert_pstr_eq(res[i], myres[i]);
  }
  ck_assert_int_eq(sprintf(res[0], "%p", str),
                   s21_sprintf(myres[0], "%p", str));
  ck_assert_pstr_eq(res[0], myres[0]);
  ck_assert_int_eq(sprintf(res[0], "%p", &str),
                   s21_sprintf(myres[0], "%p", &str));
  ck_assert_pstr_eq(res[0], myres[0]);
}
END_TEST

START_TEST(s21_NULL1) {
  ck_assert_ptr_null(s21_NULL);
  char *arr = s21_NULL;
  ck_assert_ptr_null(arr);
}
END_TEST

START_TEST(s21_size_t1) {
  size_t i;
  s21_size_t j;
  ck_assert_uint_eq(sizeof(i), sizeof(j));

  size_t i1 = 10;
  s21_size_t j1 = 10;
  ck_assert_uint_eq(i1, j1);

  size_t i2 = -1;
  s21_size_t j2 = -1;
  ck_assert_uint_eq(i2, j2);
}
END_TEST

START_TEST(s21_strlen1) {
  char str[][100] = {"123456",
                     "qwerty",
                     "",
                     "ASDFGg",
                     "!@#$%^&*()",
                     "\\",
                     "End\0sfdgs",
                     "End\0\nsfdgs",
                     "End\0\tsfdgs",
                     "End\nsfdgs",
                     "Endsfdgs\0\0\0",
                     "Endsfdgs\\n\n",
                     "End\"sfdgs\"",
                     "Endsfdgs\n",
                     "Я программист",
                     "Я программист12324354",
                     "копирование выполнено успешно\n",
                     "копирован\nие",
                     "копирован%%ие",
                     "[0-9]",
                     "^int\\d",
                     "\33[0d\33[2j",
                     "\x1b\x5b\x48\x1b\x5b\x32\x4a\\c",
                     "|.[H.[J|",
                     "|.+|",
                     "|.&a0y0C.J|",
                     "|  .1        .1  |",
                     "\x1b[2J",
                     "\0\a\b\t\n\v\f\r\e",
                     "\0\a\b\t\n\v\f\r\esa",
                     "0xA8",
                     "a BS ^",
                     "\tasd"};
  for (size_t i = 0; i < 33; i++) {
    ck_assert_int_eq(strlen(str[i]), s21_strlen(str[i]));
  }
}
END_TEST

START_TEST(s21_strcpy1) {
  char str1[][100] = {"123456",
                      "qwerty",
                      "",
                      "ASDFGg",
                      "!@#$%^&*()",
                      "\\",
                      "End\0sfdgs",
                      "End\0\nsfdgs",
                      "End\0\tsfdgs",
                      "End\nsfdgs",
                      "Endsfdgs\0\0\0",
                      "Endsfdgs\\n\n",
                      "End\"sfdgs\"",
                      "Endsfdgs\n",
                      "Я программист",
                      "Я программист12324354",
                      "копирование выполнено успешно\n",
                      "копирован\nие",
                      "копирован%%ие",
                      "[0-9]",
                      "^int\\d",
                      "\33[0d\33[2j",
                      "\x1b\x5b\x48\x1b\x5b\x32\x4a\\c",
                      "|.[H.[J|",
                      "|.+|",
                      "|.&a0y0C.J|",
                      "|  .1        .1  |",
                      "\x1b[2J",
                      "\0\a\b\t\n\v\f\r\e",
                      "\0\a\b\t\n\v\f\r\esa",
                      "0xA8",
                      "a BS ^",
                      "\tasd"};
  for (size_t i = 0; i < 33; i++) {
    char str2[100] = "";
    char str22[100] = "";
    strcpy(str2, str1[i]);
    s21_strcpy(str22, str1[i]);
    ck_assert_pstr_eq(str2, str22);
    ck_assert_mem_eq(str2, str22, 100);

    char str3[100] = "yes, i want succes!!!";
    char str33[100] = "yes, i want succes!!!";
    strcpy(str3, str1[i]);
    s21_strcpy(str33, str1[i]);
    ck_assert_pstr_eq(str3, str33);
    ck_assert_mem_eq(str3, str33, 100);

    char str4[110] = "no";
    char str44[110] = "no";
    strcpy(str4, str1[i]);
    s21_strcpy(str44, str1[i]);
    ck_assert_pstr_eq(str4, str44);
    ck_assert_mem_eq(str4, str44, 110);
  }
}
END_TEST

START_TEST(s21_memcpy1) {
  char str1[][100] = {"123456",
                      "qwerty",
                      "",
                      "ASDFGg",
                      "!@#$%^&*()",
                      "\\",
                      "End\0sfdgs",
                      "End\0\nsfdgs",
                      "End\0\tsfdgs",
                      "End\nsfdgs",
                      "Endsfdgs\0\0\0",
                      "Endsfdgs\\n\n",
                      "End\"sfdgs\"",
                      "Endsfdgs\n",
                      "Я программист",
                      "Я программист12324354",
                      "копирование выполнено успешно\n",
                      "копирован\nие",
                      "копирован%%ие",
                      "[0-9]",
                      "^int\\d",
                      "\33[0d\33[2j",
                      "\x1b\x5b\x48\x1b\x5b\x32\x4a\\c",
                      "|.[H.[J|",
                      "|.+|",
                      "|.&a0y0C.J|",
                      "|  .1        .1  |",
                      "\x1b[2J",
                      "\0\a\b\t\n\v\f\r\e",
                      "\0\a\b\t\n\v\f\r\esa",
                      "0xA8",
                      "a BS ^",
                      "\tasd"};
  for (size_t i = 0; i < 33; i++) {
    char str2[100] = "";
    char str22[100] = "";
    memcpy(str2, str1[i], strlen(str1[i]) + 1);
    s21_memcpy(str22, str1[i], strlen(str1[i]) + 1);
    ck_assert_pstr_eq(str2, str22);
    ck_assert_mem_eq(str2, str22, 100);

    char str3[100] = "";
    char str33[100] = "";
    memcpy(str3, str1[i], strlen(str1[i]));
    s21_memcpy(str33, str1[i], strlen(str1[i]));
    ck_assert_pstr_eq(str3, str33);
    ck_assert_mem_eq(str3, str33, 100);

    char str4[100] = "";
    char str44[100] = "";
    memcpy(str4, str1[i], 0);
    s21_memcpy(str44, str1[i], 0);
    ck_assert_pstr_eq(str4, str44);
    ck_assert_mem_eq(str4, str44, 100);
  }
}
END_TEST

START_TEST(s21_memmove1) {
  char str1[][100] = {"123456",
                      "qwerty",
                      "",
                      "ASDFGg",
                      "!@#$%^&*()",
                      "\\",
                      "End\0sfdgs",
                      "End\0\nsfdgs",
                      "End\0\tsfdgs",
                      "End\nsfdgs",
                      "Endsfdgs\0\0\0",
                      "Endsfdgs\\n\n",
                      "End\"sfdgs\"",
                      "Endsfdgs\n",
                      "Я программист",
                      "Я программист12324354",
                      "копирование выполнено успешно\n",
                      "копирован\nие",
                      "копирован%%ие",
                      "[0-9]",
                      "^int\\d",
                      "\33[0d\33[2j",
                      "\x1b\x5b\x48\x1b\x5b\x32\x4a\\c",
                      "|.[H.[J|",
                      "|.+|",
                      "|.&a0y0C.J|",
                      "|  .1        .1  |",
                      "\x1b[2J",
                      "\0\a\b\t\n\v\f\r\e",
                      "\0\a\b\t\n\v\f\r\esa",
                      "0xA8",
                      "a BS ^",
                      "\tasd"};
  for (size_t i = 0; i < 33; i++) {
    char str2[100] = "";
    char str22[100] = "";
    memmove(str2, str1[i], strlen(str1[i]) + 1);
    s21_memmove(str22, str1[i], strlen(str1[i]) + 1);
    ck_assert_pstr_eq(str2, str22);
    ck_assert_mem_eq(str2, str22, 100);

    char str3[100] = "";
    char str33[100] = "";
    memmove(str3, str1[i] + 6, strlen(str1[i]) + 1);
    s21_memmove(str33, str1[i] + 6, strlen(str1[i]) + 1);
    ck_assert_pstr_eq(str3, str33);
    ck_assert_mem_eq(str3, str33, 100);

    char str4[100] = "asdf";
    char str44[100] = "asdf";
    memmove(str4 + 2, str1[i] + 2, strlen(str1[i]) + 1);
    s21_memmove(str44 + 2, str1[i] + 2, strlen(str1[i]) + 1);
    ck_assert_pstr_eq(str4, str44);
    ck_assert_mem_eq(str4, str44, 100);

    char str5[100] = "asdf";
    char str55[100] = "asdf";
    memmove(str5 + 2, str1[i] + 2, 0);
    s21_memmove(str55 + 2, str1[i] + 2, 0);
    ck_assert_pstr_eq(str5, str55);
    ck_assert_mem_eq(str5, str55, 100);

    char str6[100] = "asdf";
    char str66[100] = "asdf";
    memmove(str6 + 2, str1[i], 0);
    s21_memmove(str66 + 2, str1[i], 0);
    ck_assert_pstr_eq(str6, str66);
    ck_assert_mem_eq(str6, str66, 100);
  }
  char str7[] = "memmove can be a very useful feature.............ba";
  char str77[] = "memmove can be a very useful feature.............ba";
  memmove(str7 + 16, str7 + 20, 20);
  s21_memmove(str77 + 16, str77 + 20, 20);
  ck_assert_pstr_eq(str7, str77);
  ck_assert_mem_eq(str7, str77, strlen(str7) + 1);

  char str8[] = "memmove can be a very useful feature.............ba";
  char str88[] = "memmove can be a very useful feature.............ba";
  memmove(str8 + 14, str8 + 8, 20);
  s21_memmove(str88 + 14, str88 + 8, 20);
  ck_assert_pstr_eq(str8, str88);
  ck_assert_mem_eq(str8, str88, strlen(str8) + 1);

  char str9[] = "memmove can be a very useful feature.............ba";
  char str99[] = "memmove can be a very useful feature.............ba";
  memmove(str9 + 14, str9 + 8, 1);
  s21_memmove(str99 + 14, str99 + 8, 1);
  ck_assert_pstr_eq(str9, str99);
  ck_assert_mem_eq(str9, str99, strlen(str8) + 1);

  int str10[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int str11[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  memmove(str10 + 7, str10 + 4, 2);
  s21_memmove(str11 + 7, str11 + 4, 2);
  ck_assert_mem_eq(str10, str11, 1);
}
END_TEST

START_TEST(s21_strncpy1) {
  char str1[][100] = {"123456",
                      "qwerty",
                      "",
                      "ASDFGg",
                      "!@#$%^&*()",
                      "\\",
                      "End\0sfdgs",
                      "End\0\nsfdgs",
                      "End\0\tsfdgs",
                      "End\nsfdgs",
                      "Endsfdgs\0\0\0",
                      "Endsfdgs\\n\n",
                      "End\"sfdgs\"",
                      "Endsfdgs\n",
                      "Я программист",
                      "Я программист12324354",
                      "копирование выполнено успешно\n",
                      "копирован\nие",
                      "копирован%%ие",
                      "[0-9]",
                      "^int\\d",
                      "\33[0d\33[2j",
                      "\x1b\x5b\x48\x1b\x5b\x32\x4a\\c",
                      "|.[H.[J|",
                      "|.+|",
                      "|.&a0y0C.J|",
                      "|  .1        .1  |",
                      "\x1b[2J",
                      "\0\a\b\t\n\v\f\r\e",
                      "\0\a\b\t\n\v\f\r\esa",
                      "0xA8",
                      "a BS ^",
                      "\tasd"};
  char str2[100] = "\0";
  char str22[100] = "\0";
  for (size_t i = 0; i < 33; i++) {
    memset(str2, '\0', sizeof(str2));
    memset(str22, '\0', sizeof(str22));
    strncpy(str2, str1[i], 2);
    s21_strncpy(str22, str1[i], 2);
    ck_assert_pstr_eq(str2, str22);
    ck_assert_mem_eq(str2, str22, sizeof(str1[i]));
    ck_assert_mem_eq(strncpy(str2, str1[i], 7), s21_strncpy(str22, str1[i], 7),
                     sizeof(str1[i]));

    memset(str2, '\0', sizeof(str2));
    memset(str22, '\0', sizeof(str22));
    strncpy(str2, str1[i], 90);
    s21_strncpy(str22, str1[i], 90);
    ck_assert_pstr_eq(str2, str22);
    ck_assert_mem_eq(str2, str22, sizeof(str1[i]));
    ck_assert_mem_eq(strncpy(str2, str1[i], 7), s21_strncpy(str22, str1[i], 7),
                     sizeof(str1[i]));
  }
}
END_TEST

START_TEST(s21_memset1) {
  char str1[][100] = {"123456",
                      "qwerty",
                      "",
                      "ASDFGg",
                      "!@#$%^&*()",
                      "\\",
                      "End\0sfdgs",
                      "End\0\nsfdgs",
                      "End\0\tsfdgs",
                      "End\nsfdgs",
                      "Endsfdgs\0\0\0",
                      "Endsfdgs\\n\n",
                      "End\"sfdgs\"",
                      "Endsfdgs\n",
                      "Я программист",
                      "Я программист12324354",
                      "копирование выполнено успешно\n",
                      "копирован\nие",
                      "копирован%%ие",
                      "[0-9]",
                      "^int\\d",
                      "\33[0d\33[2j",
                      "\x1b\x5b\x48\x1b\x5b\x32\x4a\\c",
                      "|.[H.[J|",
                      "|.+|",
                      "|.&a0y0C.J|",
                      "|  .1        .1  |",
                      "\x1b[2J",
                      "\0\a\b\t\n\v\f\r\e",
                      "\0\a\b\t\n\v\f\r\esa",
                      "0xA8",
                      "a BS ^",
                      "\tasd"};
  char str2[][100] = {"123456",
                      "qwerty",
                      "",
                      "ASDFGg",
                      "!@#$%^&*()",
                      "\\",
                      "End\0sfdgs",
                      "End\0\nsfdgs",
                      "End\0\tsfdgs",
                      "End\nsfdgs",
                      "Endsfdgs\0\0\0",
                      "Endsfdgs\\n\n",
                      "End\"sfdgs\"",
                      "Endsfdgs\n",
                      "Я программист",
                      "Я программист12324354",
                      "копирование выполнено успешно\n",
                      "копирован\nие",
                      "копирован%%ие",
                      "[0-9]",
                      "^int\\d",
                      "\33[0d\33[2j",
                      "\x1b\x5b\x48\x1b\x5b\x32\x4a\\c",
                      "|.[H.[J|",
                      "|.+|",
                      "|.&a0y0C.J|",
                      "|  .1        .1  |",
                      "\x1b[2J",
                      "\0\a\b\t\n\v\f\r\e",
                      "\0\a\b\t\n\v\f\r\esa",
                      "0xA8",
                      "a BS ^",
                      "\tasd"};
  for (size_t i = 0; i < 33; i++) {
    s21_memset(str1[i], 'q', strlen(str1[i]));
    memset(str2[i], 'q', strlen(str2[i]));
    ck_assert_pstr_eq(str1[i], str2[i]);
    ck_assert_mem_eq(str1[i], str2[i], sizeof(str1[i]));
  }
  for (size_t i = 0; i < 33; i++) {
    s21_memset(str1[i], '\0', sizeof(str1[i]));
    memset(str2[i], '\0', sizeof(str2[i]));
    ck_assert_pstr_eq(str1[i], str2[i]);
    ck_assert_mem_eq(str1[i], str2[i], strlen(str1[i]));
  }
  for (size_t i = 0; i < 33; i++) {
    ck_assert_mem_eq(s21_memset(str1[i], 'g', 40), memset(str2[i], 'g', 40), 0);
    ck_assert_pstr_eq(str1[i], str2[i]);
  }
}
END_TEST

START_TEST(s21_strcmp1) {
  char str1[15] = {"\0"};
  char str2[15] = {"\0"};
  strcpy(str1, "abc");
  strcpy(str2, "abcde");
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));

  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  strcpy(str1, "abcde");
  strcpy(str2, "abc");
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));

  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  strcpy(str1, "abcdef");
  strcpy(str2, "abcdef");
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));

  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  strcpy(str1, "abcdef");
  strcpy(str2, "ABCDEF");
  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST

START_TEST(s21_strncmp1) {
  char str1[30] = {"\0"};
  char str2[30] = {"\0"};
  strcpy(str1, "abcdef abcdef abobas");
  strcpy(str2, "abcdef abcdef abcdef");
  ck_assert_int_eq(strncmp(str1, str2, 4), s21_strncmp(str1, str2, 4));
  ck_assert_int_eq(strncmp(str1, str2, 19), s21_strncmp(str1, str2, 19));
  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
  ck_assert_int_eq(strncmp(str1, str2, 29), s21_strncmp(str1, str2, 29));
  ck_assert_int_eq(strncmp(str1, str2, 52), s21_strncmp(str1, str2, 52));
}
END_TEST

START_TEST(s21_memcmp1) {
  char str1[30] = {"\0"};
  char str2[30] = {"\0"};
  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  ck_assert_int_eq(memcmp(str1, str2, 4), s21_memcmp(str1, str2, 4));
  strcpy(str1, "abcdef abcdef abobas");
  strcpy(str2, "abcdef abcdef abcdef");
  ck_assert_int_eq(memcmp(str1, str2, 4), s21_memcmp(str1, str2, 4));
  ck_assert_int_eq(memcmp(str1, str2, 19), s21_memcmp(str1, str2, 19));
  ck_assert_int_eq(memcmp(str1, str2, 0), s21_memcmp(str1, str2, 0));
  ck_assert_int_eq(memcmp(str1, str2, 29), s21_memcmp(str1, str2, 29));
  ck_assert_int_eq(memcmp(str1, str2, 52), s21_memcmp(str1, str2, 52));
}
END_TEST

START_TEST(s21_strcat1) {
  char str1[30] = {"\0"}, str2[30] = {"\0"}, str3[30] = {"\0"},
       str4[30] = {"\0"};
  strcpy(str1, "abc");
  strcpy(str2, "abcde");
  strcpy(str3, "abc");
  strcpy(str4, "abcde");
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str1, str2));
  ck_assert_pstr_eq(strcat(str3, str4), s21_strcat(str3, str4));
  ck_assert_mem_eq(str1, str3, 2);

  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  memset(str3, '\0', sizeof(str3));
  memset(str4, '\0', sizeof(str4));
  strcpy(str1, "abcde");
  strcpy(str2, "abc");
  strcpy(str3, "abcde");
  strcpy(str4, "abc");
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str1, str2));
  ck_assert_pstr_eq(strcat(str3, str4), s21_strcat(str3, str4));
  ck_assert_mem_eq(str1, str3, sizeof(str1));

  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  memset(str3, '\0', sizeof(str3));
  memset(str4, '\0', sizeof(str4));
  strcpy(str1, "abcde");
  strcpy(str2, "\tabcdef");
  strcpy(str3, "abcde");
  strcpy(str4, "\tabcdef");
  ck_assert_pstr_eq(strcat(str1, str2), s21_strcat(str1, str2));
  ck_assert_pstr_eq(strcat(str3, str4), s21_strcat(str3, str4));
  ck_assert_mem_eq(str1, str3, sizeof(str1));
}
END_TEST

START_TEST(s21_strncat1) {
  char str1[100] = {"\0"}, str2[100] = {"\0"}, str3[100] = {"\0"},
       str4[100] = {"\0"};
  strcpy(str1, "abc abc abc");
  strcpy(str2, "abcde abcde abcde");
  strcpy(str3, "abc abc abc");
  strcpy(str4, "abcde abcde abcde");
  ck_assert_pstr_eq(strncat(str1, str2, strlen(str2)),
                    s21_strncat(str1, str2, strlen(str2)));
  ck_assert_pstr_eq(strncat(str3, str4, strlen(str2)),
                    s21_strncat(str3, str4, strlen(str2)));
  ck_assert_mem_eq(str1, str3, 2);

  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  memset(str3, '\0', sizeof(str3));
  memset(str4, '\0', sizeof(str4));
  strcpy(str1, "abcde abcde abcde");
  strcpy(str2, "abc abc abc");
  strcpy(str3, "abcde abcde abcde");
  strcpy(str4, "abc abc abc");
  ck_assert_pstr_eq(strncat(str1, str2, 6), s21_strncat(str1, str2, 6));
  ck_assert_pstr_eq(strncat(str3, str4, 6), s21_strncat(str3, str4, 6));
  ck_assert_mem_eq(str1, str3, sizeof(str1));

  memset(str1, '\0', sizeof(str1));
  memset(str2, '\0', sizeof(str2));
  memset(str3, '\0', sizeof(str3));
  memset(str4, '\0', sizeof(str4));
  strcpy(str1, "abcde abcde abcde");
  strcpy(str2, "\tabcdef abcdef abcdef");
  strcpy(str3, "abcde abcde abcde");
  strcpy(str4, "\tabcdef abcdef abcdef");
  ck_assert_pstr_eq(strncat(str1, str2, 2), s21_strncat(str1, str2, 2));
  ck_assert_pstr_eq(strncat(str3, str4, 2), s21_strncat(str3, str4, 2));
  ck_assert_mem_eq(str1, str3, strlen(str3));
}
END_TEST

START_TEST(s21_strspn1) {
  const char str1[] = "ABCDEF4960910";
  const char str2[] = "ABCD";
  const char str3[] = "013";
  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1, str2));
  ck_assert_int_eq(strspn(str1, str3), s21_strspn(str1, str3));
  ck_assert_int_eq(strspn(str2, str3), s21_strspn(str2, str3));
}
END_TEST

START_TEST(s21_strcspn1) {
  const char str1[] = "ABCDEF4960910";
  const char str2[] = "ABCD";
  const char str3[] = "013";
  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
  ck_assert_int_eq(strcspn(str1, str3), s21_strcspn(str1, str3));
  ck_assert_int_eq(strcspn(str2, str3), s21_strcspn(str2, str3));
}
END_TEST

START_TEST(s21_strchr1) {
  const char str[] = "www.site.ru";
  const char ch1 = '.';
  const char ch2 = 'q';
  ck_assert_pstr_eq(strchr(str, ch1), s21_strchr(str, ch1));
  ck_assert_pstr_eq(strchr(str, ch2), s21_strchr(str, ch2));
}
END_TEST

START_TEST(s21_strrchr1) {
  const char str[] = "www.site.ru";
  const char ch1 = '.';
  const char ch2 = 'q';
  ck_assert_pstr_eq(strrchr(str, ch1), s21_strrchr(str, ch1));
  ck_assert_pstr_eq(strrchr(str, ch2), s21_strrchr(str, ch2));
  ck_assert_pstr_eq(strrchr(str, '\0'), s21_strrchr(str, '\0'));
}
END_TEST

START_TEST(s21_memchr1) {
  const char str[] = "www.site.ru";
  const char ch1 = '.';
  const char ch2 = 'q';
  ck_assert_pstr_eq(memchr(str, ch1, strlen(str)),
                    s21_memchr(str, ch1, strlen(str)));
  ck_assert_pstr_eq(memchr(str, ch1, 4), s21_memchr(str, ch1, 4));
  ck_assert_pstr_eq(memchr(str, ch1, 2), s21_memchr(str, ch1, 2));
  ck_assert_pstr_eq(memchr(str, ch2, strlen(str)),
                    s21_memchr(str, ch2, strlen(str)));
}
END_TEST

START_TEST(s21_strpbrk1) {
  const char str1[] = "abcde2fghi3jk4l";
  const char str2[] = "qf34";
  const char str3[] = "q";
  ck_assert_pstr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2));
  ck_assert_pstr_eq(strpbrk(str1, str3), s21_strpbrk(str1, str3));
}
END_TEST

START_TEST(s21_strstr1) {
  const char haystack[20] = "TutorialsPoint";
  const char haystack1[20] = "PointTutorialsPoint";
  const char needle[10] = "Point";
  const char needle1[10] = "Ts";
  const char needle2[10] = "";
  ck_assert_pstr_eq(strstr(haystack, needle), s21_strstr(haystack, needle));
  ck_assert_pstr_eq(strstr(haystack1, needle), s21_strstr(haystack1, needle));
  ck_assert_pstr_eq(strstr(haystack, needle1), s21_strstr(haystack, needle1));
  ck_assert_pstr_eq(strstr(haystack, needle2), s21_strstr(haystack, needle2));
  ck_assert_pstr_eq(strstr(haystack, haystack), s21_strstr(haystack, haystack));
}
END_TEST

START_TEST(s21_strtok1) {
  char strt[80] = "This is - www.tutorialspoint.com - website";
  char strt1[80] = "This is - www.tutorialspoint.com - website";
  const char s[2] = "-";
  char *token = strtok(strt, s);
  char *token1 = s21_strtok(strt1, s);
  ck_assert_uint_eq(strlen(token), strlen(token1));
  ck_assert_pstr_eq(token, token1);
  while (token != NULL && token1 != NULL) {
    token = strtok(NULL, s);
    token1 = s21_strtok(NULL, s);
    ck_assert_pstr_eq(token, token1);
  }
}
END_TEST

START_TEST(s21_to_upper1) {
  char str_in[8][20] = {"abcde", "Abcde", "2+2*3", " ", "\t", "", "\b."};
  char str_out[8][20] = {"ABCDE", "ABCDE", "2+2*3", " ", "\t", "", "\b."};
  for (size_t i = 0; i < 8; i++) {
    char *res = s21_to_upper(str_in[i]);
    ck_assert_pstr_eq(res, str_out[i]);
    if (res) free(res);
  }

  char *str1 = "i'm programming";
  char *res1 = "I'M PROGRAMMING";
  char *cur_res1 = s21_to_upper(str1);
  ck_assert_pstr_eq(res1, cur_res1);
  if (cur_res1) {
    free(cur_res1);
  }

  // char *str2 = NULL;
  // char *res2 = NULL;
  // char *cur_res2 = s21_to_lower(str2);
  // ck_assert_pstr_eq(res2, cur_res2);
  // if (cur_res2) free(cur_res2);
}
END_TEST

START_TEST(s21_to_lower1) {
  char str_in[8][20] = {"abcde", "ABCDE", "Abcde", "2+2*3",
                        " ",     "\t",    "",      "\b."};
  char str_out[8][20] = {"abcde", "abcde", "abcde", "2+2*3",
                         " ",     "\t",    "",      "\b."};
  for (size_t i = 0; i < 8; i++) {
    char *res = s21_to_lower(str_in[i]);
    ck_assert_pstr_eq(res, str_out[i]);
    if (res) free(res);
  }

  char *str1 = "I'M PROGRAMMING";
  char *res1 = "i'm programming";
  char *cur_res1 = s21_to_lower(str1);
  ck_assert_pstr_eq(res1, cur_res1);
  if (cur_res1) free(cur_res1);

  // char *str2 = NULL;
  // char *res2 = NULL;
  // char *cur_res2 = s21_to_lower(str2);
  // ck_assert_pstr_eq(res2, cur_res2);
  // if (cur_res2) free(cur_res2);
}
END_TEST

START_TEST(s21_insert1) {
  char str1[100] = "I'm programming";
  char ins1[100] = "like ";
  char res1[100] = "I'm like programming";
  char *cur_res1 = s21_insert(str1, ins1, 4);
  ck_assert_pstr_eq(res1, cur_res1);
  if (cur_res1) free(cur_res1);

  char str2[100] = "";
  char ins2[100] = "123";
  char *res2 = NULL;
  char *cur_res2 = s21_insert(str2, ins2, 10);
  ck_assert_pstr_eq(res2, cur_res2);
  if (cur_res2) free(cur_res2);

  char str3[100] = "";
  char ins3[100] = "";
  char *res3 = NULL;
  char *cur_res3 = s21_insert(str3, ins3, 10);
  ck_assert_pstr_eq(res3, cur_res3);
  if (cur_res3) free(cur_res3);

  char *str4 = "laka ama";
  char *ins4 = "";
  char *res4 = "laka ama";
  char *cur_res4 = s21_insert(str4, ins4, 2);
  ck_assert_pstr_eq(res4, cur_res4);
  if (cur_res4) free(cur_res4);

  char *str5 = "laka ama";
  char *ins5 = "ren";
  char *res5 = NULL;
  char *cur_res5 = s21_insert(str5, ins5, 20);
  ck_assert_pstr_eq(res5, cur_res5);
  if (cur_res5) free(cur_res5);

  char *str6 = "laka ama";
  char *ins6 = "";
  char *res6 = NULL;
  char *cur_res6 = s21_insert(str6, ins6, 30);
  ck_assert_pstr_eq(res6, cur_res6);
  if (cur_res6) free(cur_res6);

  char *str7 = "laka ama";
  char *ins7 = NULL;
  char *res7 = NULL;
  char *cur_res7 = s21_insert(str7, ins7, 2);
  ck_assert_pstr_eq(res7, cur_res7);
  if (cur_res7) free(cur_res7);

  char *str8 = "laka ama";
  char *ins8 = NULL;
  char *res8 = NULL;
  char *cur_res8 = s21_insert(str8, ins8, 30);
  ck_assert_pstr_eq(res8, cur_res8);
  if (cur_res8) free(cur_res8);

  char *str9 = NULL;
  char *ins9 = "qwerty";
  char *res9 = NULL;
  char *cur_res9 = s21_insert(str9, ins9, 5);
  ck_assert_pstr_eq(res9, cur_res9);
  if (cur_res9) free(cur_res9);

  char *str10 = NULL;
  char *ins10 = NULL;
  char *res10 = NULL;
  char *cur_res10 = s21_insert(str10, ins10, 5);
  ck_assert_pstr_eq(res10, cur_res10);
  if (cur_res10) free(cur_res10);
}
END_TEST

START_TEST(s21_trim1) {
  char str1[50] = "   I'm prog   ramming   ";
  char res1[50] = "I'm prog   ramming";
  char ch1[20] = " ";
  char *cur_res1 = s21_trim(str1, ch1);
  ck_assert_pstr_eq(res1, cur_res1);
  if (cur_res1) free(cur_res1);

  char str2[50] = "   gI'm prog   rammin";
  char res2[50] = "I'm prog   rammin";
  char ch2[20] = " g";
  char *cur_res2 = s21_trim(str2, ch2);
  ck_assert_pstr_eq(res2, cur_res2);
  if (cur_res2) free(cur_res2);

  char str3[50] = "   I'm prog   ramminggg   ";
  char res3[50] = "I'm prog   ramminggg";
  char ch3[20] = "";
  char *cur_res3 = s21_trim(str3, ch3);
  ck_assert_pstr_eq(res3, cur_res3);
  if (cur_res3) free(cur_res3);

  char str4[50] = "   I'm prog   ramminggg   ";
  char res4[50] = "I'm prog   ramminggg";
  char *cur_res4 = s21_trim(str4, NULL);
  ck_assert_pstr_eq(res4, cur_res4);
  if (cur_res4) free(cur_res4);

  char str5[50] = "";
  char res5[50] = "";
  char ch5[50] = "I'm prog   ramminggg";
  char *cur_res5 = s21_trim(str5, ch5);
  ck_assert_pstr_eq(res5, cur_res5);
  if (cur_res5) free(cur_res5);

  char *str6 = NULL;
  char *res6 = NULL;
  char *ch6 = " 0";
  char *cur_res6 = s21_trim(str6, ch6);
  ck_assert_pstr_eq(res6, cur_res6);
  if (cur_res6) free(cur_res6);

  char *str7 = NULL;
  char *res7 = NULL;
  char *ch7 = NULL;
  char *cur_res7 = s21_trim(str7, ch7);
  ck_assert_pstr_eq(res7, cur_res7);
  if (cur_res7) free(cur_res7);
}
END_TEST

START_TEST(s21_strerror1) {
  char *str = {"\0"};
  char *res = {"\0"};
  for (int i = -1; i < 134; i++) {
    str = s21_strerror(i);
    res = s21_strerror(i);
    ck_assert_str_eq(str, res);
  }
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf = 0;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, spec_c);
  tcase_add_test(tc1_1, spec_d);
  tcase_add_test(tc1_1, spec_i);
  tcase_add_test(tc1_1, spec_f);
  tcase_add_test(tc1_1, spec_s);
  tcase_add_test(tc1_1, spec_u);
  tcase_add_test(tc1_1, spec_procent);
  tcase_add_test(tc1_1, varia);
  tcase_add_test(tc1_1, varia0);
  tcase_add_test(tc1_1, spec_g);
  tcase_add_test(tc1_1, spec_e);
  tcase_add_test(tc1_1, spec_x);
  tcase_add_test(tc1_1, spec_o);
  tcase_add_test(tc1_1, spec_n);
  tcase_add_test(tc1_1, spec_p);
  tcase_add_test(tc1_1, s21_NULL1);
  tcase_add_test(tc1_1, s21_size_t1);
  tcase_add_test(tc1_1, s21_strlen1);
  tcase_add_test(tc1_1, s21_strcpy1);
  tcase_add_test(tc1_1, s21_memcpy1);
  tcase_add_test(tc1_1, s21_memmove1);
  tcase_add_test(tc1_1, s21_strncpy1);
  tcase_add_test(tc1_1, s21_memset1);
  tcase_add_test(tc1_1, s21_strcmp1);
  tcase_add_test(tc1_1, s21_strncmp1);
  tcase_add_test(tc1_1, s21_memcmp1);
  tcase_add_test(tc1_1, s21_strcat1);
  tcase_add_test(tc1_1, s21_strncat1);
  tcase_add_test(tc1_1, s21_strspn1);
  tcase_add_test(tc1_1, s21_strcspn1);
  tcase_add_test(tc1_1, s21_strchr1);
  tcase_add_test(tc1_1, s21_strrchr1);
  tcase_add_test(tc1_1, s21_memchr1);
  tcase_add_test(tc1_1, s21_strpbrk1);
  tcase_add_test(tc1_1, s21_strstr1);
  tcase_add_test(tc1_1, s21_strtok1);
  tcase_add_test(tc1_1, s21_to_upper1);
  tcase_add_test(tc1_1, s21_to_lower1);
  tcase_add_test(tc1_1, s21_insert1);
  tcase_add_test(tc1_1, s21_trim1);
  tcase_add_test(tc1_1, s21_strerror1);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
