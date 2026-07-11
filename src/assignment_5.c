#include "assignment_5.h"

#include <stdio.h>
#include <stdlib.h>

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


struct node *addback(struct node *head, int data) {
  struct node *new = malloc(sizeof(struct node));

  if (new == NULL) {
    return head;
  }

  new->data = data;
  new->next = NULL;

  if (head == NULL)
    return new;

  struct node *curr = head;

  while (curr->next != NULL) {
    curr = curr->next;
  }

  curr->next = new;

  return head;
}


void problem_5_1_a(void) {
  struct node n3 = {30, NULL};
  struct node n2 = {20, &n3};
  struct node n1 = {10, &n2};

  display(&n1);
}

void problem_5_1_b() {
  struct node n3 = {30, NULL};
  struct node n2 = {20, &n3};
  struct node n1 = {10, &n2};

  struct node *new = addback(&n1, 40);
  display(new);
}