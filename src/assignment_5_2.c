#include "assignment_5_2.h"

#include <stdio.h>
#include <stdlib.h>

struct tnode {
  int data;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *talloc(int data) {
  struct tnode *new = malloc(sizeof(struct tnode));

  if (new) {
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
  }

  return NULL;
}

void problem_5_2_a() {
  struct tnode *new = talloc(5);
  if (new) {
    printf("%d", new->data);
    free(new);
  }
}
