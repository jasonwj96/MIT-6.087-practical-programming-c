#include <stdio.h>

void problem_1_1(){
  const double ans = 10.0 + 2.0 / ((3.0 - 2.0) * 2.0);
  printf("Problem 1.1 - c: %f\n", ans);
}

void problem_1_2() {

#define squared(x) x*x

  const double ans1 = 18.0 / squared(2+1);
  printf("x*x -> %f\n", ans1);

  #undef squared

  #define squared(x) (x*x)
  const double ans2 = 18.0 / squared(2+1);
  printf("(x*x) -> %f\n", ans2);

  #undef squared

  #define squared(x) (x)*(x)

  const double ans3 = 18.0 / squared(2+1);
  printf("(x)*(x) -> %f\n", ans3);

  #undef squared

  #define squared(x) ((x)*(x))

  const double ans4 = 18.0 / squared(2+1);
  printf("((x)*(x)) -> %f\n", ans4);
}

void problem_1_3() {
  printf("Hello, 6.087 students.\n");
}

void problem_1_4() {
#define MSG1 "All your base are belong to us!\n"
  const char msg[] = MSG1;
  puts(msg);

}