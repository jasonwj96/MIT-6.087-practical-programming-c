#include "assignment_2.h"
#include <limits.h>
#include <stdio.h>
#include <float.h>

void problem_2_1() {

  printf("char: min = %d, max = %d\n", CHAR_MIN, CHAR_MAX);
  printf("unsigned char: min = %u, max = %u\n", 0, UCHAR_MAX);
  printf("short: min = %d, max = %d\n", SHRT_MIN, SHRT_MAX);
  printf("int: min = %d, max = %d\n", INT_MIN, INT_MAX);
  printf("unsigned int: min = %u, max = %u\n", 0, UINT_MAX);
  printf("unsigned long: max = %ld, max = %ld\n", LONG_MIN, LONG_MAX);
  printf("float: min = %e, max = %e\n", -FLT_MAX, FLT_MAX);
}