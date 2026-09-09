#include "assignment_6b_61.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static struct student class[] = {
  {.fname = "Sean", .lname = "Penn", .year = 2, .age = 21},
  {.fname = "Sean", .lname = "Connery", .year = 4, .age = 25},
  {.fname = "Angelina", .lname = "Jolie", .year = 3, .age = 22},
  {.fname = "Meryl", .lname = "Streep", .year = 4, .age = 29},
  {.fname = "Robin", .lname = "Williams", .year = 3, .age = 32},
  {.fname = "Bill", .lname = "Gates", .year = 3, .age = 17},
  {.fname = "Jodie", .lname = "Foster", .year = 4, .age = 25},
  {.fname = "John", .lname = "Travolta", .year = 1, .age = 17},
  {.fname = "Isaac", .lname = "Newton", .year = 2, .age = 19},
  {.fname = "Sarah", .lname = "Palin", .year = 2, .age = 19}
};

/*
 * @function compare_firstname
 * @desc compares first name of two records.
 */
int compare_firstname(const void *a, const void *b) {
  const struct student *sa = (struct student *) a;
  const struct student *sb = (struct student *) b;
  return strcmp(sa->fname, sb->fname);
}

/*
 * @function compare_lastname
 * @desc compares last name of two records.
 */
int compare_lastname(const void *a, const void *b) {
  struct student *sa = (struct student *) a;
  struct student *sb = (struct student *) b;
  return strcmp(sa->lname, sb->lname);
}

/*
 * @function apply
 * @desc applies fp to every record in sarr, passing arg through unchanged
 */
void apply(struct student *sarr, int nrec,
           void (*fp)(void *prec, void *arg), void *arg) {
  for (int i = 0; i < nrec; i++) {
    fp(&sarr[i], arg);
  }
}

/*
 * @function print_rec
 * @desc prints student record unconditionally
 */
void print_rec(void *prec, void *arg) {
  (void) arg;
  struct student *pstud = prec;
  printf("%-20s%-20s%4d%4d\n", pstud->fname, pstud->lname, pstud->year, pstud->age);
}

/*
 * @function isolder
 * @desc prints student record only if age is greater than the threshold
 *       pointed to by arg; does nothing otherwise
 */
void isolder(void *prec, void *arg) {
  int *age = arg;
  struct student *pstud = prec;

  if (pstud->age < *age) {
    return;
  }

  printf("%-20s%-20s%4d%4d\n", pstud->fname, pstud->lname, pstud->year, pstud->age);
}

void problem_6b_61() {
  int nstudents = sizeof(class) / sizeof(struct student);
  int age;

  puts("Raw records:");
  puts("-------------------------------");
  apply(class, nstudents, print_rec, NULL);

  /* sort based on first name */
  puts("Sorted by first name:");
  puts("-------------------------------");
  qsort(class, nstudents, sizeof(struct student), compare_firstname);
  apply(class, nstudents, print_rec, NULL);

  /* sort based on last name */
  puts("Sorted by last name:");
  puts("-------------------------------");
  qsort(class, nstudents, sizeof(struct student), compare_lastname);
  apply(class, nstudents, print_rec, NULL);

  /* print people older than 20 */
  puts("People older than 20:");
  puts("-------------------------------");
  age = 20;
  apply(class, nstudents, isolder, &age);
}
