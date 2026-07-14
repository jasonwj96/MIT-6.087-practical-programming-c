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

struct tnode *addnode(struct tnode *root, int data) {
  if (!root) {
    return talloc(data);
  }

  if (data < root->data) {
    root->left = addnode(root->left, data);
  } else if (data > root->data) {
    root->right = addnode(root->right, data);
  }

  return root;
}

void preorder(struct tnode *root) {
  if (!root) {
    return;
  }

  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(struct tnode *root) {
  if (!root) {
    return;
  }

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int deltree(struct tnode *root) {
  if (!root) {
    return 0;
  }

  int count = 0;
  count += deltree(root->left);
  count += deltree(root->right);
  free(root);
  count += 1;

  return count;
}

void problem_5_2_a() {
  struct tnode *new = talloc(5);
  if (new) {
    printf("%d\n", new->data);
    free(new);
  }
}

void problem_5_2_b() {
  struct tnode *root = NULL;
  int values[] = {3, 1, 0, 2, 8, 6, 5, 9};
  int n = sizeof(values) / sizeof(values[0]);

  for (int i = 0; i < n; i++) {
    root = addnode(root, values[i]);
  }

  preorder(root);
  printf("\n");

  deltree(root);
}

void problem_5_2_c() {
  struct tnode *root = NULL;
  int values[] = {3, 1, 0, 2, 8, 6, 5, 9};
  int n = sizeof(values) / sizeof(values[0]);

  for (int i = 0; i < n; i++) {
    root = addnode(root, values[i]);
  }

  preorder(root);
  printf("\n");

  deltree(root);
}

void problem_5_2_d() {
  struct tnode *root = NULL;
  int values[] = {3, 1, 0, 2, 8, 6, 5, 9};
  int n = sizeof(values) / sizeof(values[0]);

  for (int i = 0; i < n; i++) {
    root = addnode(root, values[i]);
  }

  inorder(root);
  printf("\n");

  deltree(root);
}

void problem_5_2_e() {
  struct tnode *root = NULL;
  int values[] = {3, 1, 0, 2, 8, 6, 5, 9};
  int n = sizeof(values) / sizeof(values[0]);

  for (int i = 0; i < n; i++) {
    root = addnode(root, values[i]);
  }

  int deleted = deltree(root);
  printf("%d\n", deleted);
}
