#include "assignment_4.h"

#include <stddef.h>

#define array_length(arr) (sizeof(arr) / sizeof((arr)[0]))

/*

void shift_element(unsigned int i) {
  int ivalue;
  for (ivalue = arr[i]; i && arr[i-1] > ivalue; i--)
    arr[i] = arr[i-1];
  arr[i] = ivalue;
}

*/

void shift_element(const int arr[], int *pElement) {
  int ivalue;

  for (ivalue = *pElement; pElement > arr && *(pElement - 1) > ivalue; pElement--) {
    *pElement = *(pElement - 1);
  }

  *pElement = ivalue;
}

void problem_4_1(int argc, char *argv[]) {
  const int arr[] = {0, 1, 3, 7, 4, 2};
  int p = 5;

  shift_element(arr, &p);
}

void insertion_sort(int arr[], size_t len) {
  for (int *p = arr + 1; p < arr + len; p++) {
    shift_element(arr, p);
  }
}

void problem_4_2(void) {
  int arr[] = {5, 2, 8, 1, 9};

  insertion_sort(arr, array_length(arr));
}