#pragma once

#define MAX_STUDENTS 10

struct student {
  char fname[100];
  char lname[100];
  int year;
  int age;
};

/* comparison callbacks, for use with qsort() */
int compare_firstname(const void *a, const void *b);

int compare_lastname(const void *a, const void *b);

/* generic "apply fp to every record" iterator */
void apply(struct student *sarr, int nrec,
           void (*fp)(void *prec, void *arg), void *arg);

/* callbacks usable with apply() */
void print_rec(void *prec, void *arg);

void isolder(void *prec, void *arg);

void problem_6b_61(void);
