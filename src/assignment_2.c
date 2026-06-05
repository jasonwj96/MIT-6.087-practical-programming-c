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