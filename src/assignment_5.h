#pragma once

struct node;

void display(struct node *head);

struct node* addback(struct node* head,int data);
struct node* find(struct node* head,int data);
struct node* delnode(struct node* head,struct node* pelement);

void problem_5_1_a();
void problem_5_1_b();
void problem_5_1_c();
void problem_5_1_d();
void problem_5_1_e();
void problem_5_1_f();