#include "assignment_2.h"
#include <limits.h>
#include <stdio.h>
#include <float.h>

void problem_2_1() {

  printf("char: size = %zu bytes, min = %d, max = %d\n",
    sizeof(char), CHAR_MIN, CHAR_MAX);

  printf("unsigned char: size = %zu bytes, min = %u, max = %u\n",
    sizeof(char),0, UCHAR_MAX);

  printf("short: size = %zu bytes, min = %d, max = %d\n",
    sizeof(short), SHRT_MIN, SHRT_MAX);

  printf("int: size = %zu bytes, min = %d, max = %d\n",
    sizeof(int), INT_MIN, INT_MAX);

  printf("unsigned int: size = %zu bytes,  min = %u, max = %u\n",
    sizeof(int) ,0, UINT_MAX);

  printf("unsigned long: max = %ld, max = %ld\n", LONG_MIN, LONG_MAX);

  printf("float: min = %e, max = %e\n", -FLT_MAX, FLT_MAX);
}

void problem_2_2(char c) {
  if (c >= 'a' && c <= 'z') {
    printf("lower case letter.");
  }

  if (c >= 'A' && c <= 'Z') {
    printf("upper case letter.");
  }

  if (c >= '0' && c <= '9') {
    printf("digit.");
  }

  if (c == ' ' || c == '\t' || c == '\n') {
    printf("white space (includes space,tab,new line).");
  }
}

void problem_2_3() {
  const int val = 0xCAFE;

  const int test =
       ((val & 0x1) != 0) +
       ((val & 0x2) != 0) +
       ((val & 0x4) != 0) +
       ((val & 0x8) != 0) >= 3;

  printf("At least 3 of last 4 bits set: 0x%x\n", test);

  /*
  AND
  11001010 11111110  - 0xCAFE
  00000000 11111111  - 0x00FF
  ---------------------------
  00000000 11111110  - 0x00FE
  ---------------------------
  << 8
  11111110 00000000  - 0xFE00
  ---------------------------

  >> 8
  11001010 11111110  - 0xCAFE
  00000000 11001010  - 0x00CA

  ---------------------------
  OR
  00000000 11001010  - 0x00CA
  11111110 00000000  - 0xFE00
  ---------------------------
  11111110 11001010  - 0xFECA

  */

  const int reversed = (val & 0x00FF) << 8 | val >> 8;
  printf("Reverse the byte order: 0x%x\n", reversed);

  const int rotated =  (val >> 4 | val << 12) & 0xFFFF;
  printf("Rotate 4 bits: 0x%x\n", rotated);

}

void problem_2_4() {

}

void problem_2_5() {

}