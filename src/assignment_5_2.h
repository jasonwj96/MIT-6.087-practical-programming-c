#pragma once

struct tnode *talloc(int data);

struct tnode *addnode(struct tnode *root, int data);

void preorder(struct tnode *root);

void inorder(struct tnode *root);

int deltree(struct tnode *root);

void problem_5_2_a();

void problem_5_2_b();

void problem_5_2_c();

void problem_5_2_d();

void problem_5_2_e();
