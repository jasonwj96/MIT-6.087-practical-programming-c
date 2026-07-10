#include "assignment_5.h"

#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

void display(struct node *head) {
  struct node *curr = head;

  while (curr != NULL) {
    printf("%d", curr->data);

    if (curr->next != NULL)
      printf(" -> ");

    curr = curr->next;
  }

  printf("\n");
}

void problem_5_1(void) {
  struct node n3 = {30, NULL};
  struct node n2 = {20, &n3};
  struct node n1 = {10, &n2};

  display(&n1);
}
