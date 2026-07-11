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

struct node *find(struct node *head, int data) {
  struct node *curr = head;

  while (curr != NULL) {
    if (curr->data == data) {
      return curr;
    }

    curr = curr->next;
  }

  return NULL;
}


void problem_5_1_a(void) {
  struct node n3 = {30, NULL};
  struct node n2 = {20, &n3};
  struct node n1 = {10, &n2};

  display(&n1);
}


void problem_5_1_c() {
  struct node n3 = {30, NULL};
  struct node n2 = {20, &n3};
  struct node n1 = {10, &n2};

  struct node *found = find(&n1, 10);

  if (found) {
    printf("Found node %d at address 0x%p.\n", found->data, found);
  } else {
    printf("Node not found.\n");
  }

  found = find(&n1, 40);

  if (found) {
    printf("Found node %d at address 0x%p.", found->data, found);
  } else {
    printf("Node %d not found.", 40);
  }
}
