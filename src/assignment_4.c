#include "assignment_4.h"

#include <stddef.h>
#include <stdio.h>

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
  int arr[] = {0, 1, 3, 7, 4, 2};
  int p = 5;

  shift_element(arr, &p);

  int arr2[] = {5, 2, 8, 1, 9};
  insertion_sort(arr2, array_length(arr2));
}

void insertion_sort(int arr[], size_t len) {
  for (int *p = arr + 1; p < arr + len; p++) {
    shift_element(arr, p);
  }
}

/*
 *
char *strtok(char *text, const char *delims) {
  if (!text)
    text = pnexttoken;

  find start of token in text
  text += strspn(text, delims);

  if (*text == '\0')
    return NULL;

  find end of token in text
  pnexttoken = text + strcspn(text, delims);

  insert null terminator at end
  if (*pnexttoken != '\0')
    *pnexttoken++ = '\0';

  return text;
}

*/


int strpos(const char *str, char ch) {
  const char *p = str;

  while (*p != '\0') {
    if (*p == ch)
      return p - str;

    p++;
  }

  return -1;
}

/*
  In the context of our string tokenizer, the function strspn() computes the index of the
  first non-delimiter character in our string. Using pointers or array indexing (your choice),
  implement the strspn() function. In order to locate a character in another string, you may
  use the function strpos()
*/
unsigned int strspn(const char *str, const char *delims) {
  const char *curr_c = str;

  while (*curr_c != '\0') {
    if (strpos(delims, *curr_c) == -1)
      break;

    curr_c++;
  }

  return curr_c - str;
}


void problem_4_2(void) {
  const char *str = " . This";

  printf("%d", strspn(" . This", " ."));
}
