#include "assignment_4.h"

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
