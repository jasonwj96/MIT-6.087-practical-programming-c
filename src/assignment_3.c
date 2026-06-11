#include "assignment_3.h"

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 25

static unsigned int results_buffer[NMAX];

void fibonacci() {
  register unsigned int a = 0;
  register unsigned int b = 1;
  register unsigned int c;
  int n;

  results_buffer[0] = a;
  results_buffer[1] = b;

  for (n = 2; n < NMAX; n++) {
    c = a + b;
    results_buffer[n] = c;
    a = b;
    b = c;
  }
}

void problem_3_1() {
  int n, ntests = 10000000;
  clock_t tstart, tend;
  double favg;

  /* do profiling */
  tstart = clock();

  for (n = 0; n < ntests; n++) {
    fibonacci();
  }

  tend = clock();
  /* end profiling */

  /* compute average execution time */
  favg = (double) (tend - tstart) / CLOCKS_PER_SEC / ntests;

  /* print avg execution time in milliseconds */
  printf("Avg. execution time: %g msec\n", favg * 1000);
}

/*
  int factorial(int n){
   int i, ret = 1;

   for(i = 2; i <= n; i++)
     ret *= i;

    return ret;

  }

*/


int factorial(int n) {
  int i = 1;
  int ret = 1;

  do {
    ret *= i;
    i += 1;
  } while (i <= n);

  return ret;
}

double rand_double() {
  return rand() / (RAND_MAX + 1);
}

int sample_geometric_rv(double p) {
  int n = 0;
  double q = rand_double();

  n++;

  while (q >= p) {
    q = rand_double();
    n++;
  }

  return n;
}

void problem_3_3() {
  printf("Factorial: %d\n", factorial(10));
  printf("Sample geometric Rv: %d", sample_geometric_rv(0.5));
}

void problem_3_4(int argc, char *argv[]) {
  FILE *fp = NULL;
  int nfiles = --argc; /* ignore the name of the program itself */
  int argidx = 1; /* ignore the name of the program itself */
  char *currfile = "";
  char c;

  /* count of words, lines, characters */
  unsigned long nw = 0, nl = 0, nc = 0;
  int in_word = 0;

  if (nfiles == 0) {
    fp = stdin; /* standard input */
    nfiles++;
  } else {
    /* set to first */
    currfile = argv[argidx++];
    fp = fopen(currfile, "r");
  }

  while (nfiles > 0) /* files left > 0 */
  {
    if (fp == NULL) {
      fprintf(stderr, "Unable to open input\n");
      exit(-1);
    }

    nc = nw = nl = 0;
    in_word = 0;

    while ((c = getc(fp)) != EOF) {
      nc++;

      if (c == '\n')
        nl++;

      if (isspace(c)) {
        if (in_word) {
          nw++;
          in_word = 0;
        }
      } else {
        in_word = 1;
      }
    }

    /* count last word if file doesn't end with whitespace */
    if (in_word)
      nw++;

    /* count last line if file doesn't end with newline */
    if (nc > 0 && c != '\n')
      nl++;

    printf("Current file: %s\n", currfile);
    printf("Character count: %ld\n", nc);
    printf("Word count: %ld\n", nw);
    printf("Line count: %ld\n\n", nl);

    nfiles--;
    if (nfiles > 0) {
      currfile = argv[argidx++];
      fp = fopen(currfile, "r");
    }
  }
}

struct StateRecord {
  int stateOrigin;
  int countyCodeOrigin;
  int stateCodeDest;
  int countyCodeDest;
  char stateAbbrv[10];
  char stateName[50];
  int returnNum;
  int exmptNum;
  int aggrAgi;
};

#define MAX_RECORDS 2700

void problem_3_5(int argc, char *argv[]) {
  FILE *fp = NULL;
  char line[512];
  struct StateRecord records[MAX_RECORDS];
  int count = 0;

  fp = fopen(argv[1], "r");

  if (fp == NULL) {
    perror("fopen failed");
    exit(-1);
  }

  /* skip header line */
  fgets(line, sizeof(line), fp);

  /* read each data line into array */
  while (fgets(line, sizeof(line), fp) != NULL && count < MAX_RECORDS) {
    const int parsed = sscanf(
      line,
      "\"%d\"\t\"%d\"\t\"%d\"\t\"%d\"\t\"%9[^\"]\"\t\"%49[^\"]\"\t%d\t%d\t%d",
      &records[count].stateOrigin,
      &records[count].countyCodeOrigin,
      &records[count].stateCodeDest,
      &records[count].countyCodeDest,
      records[count].stateAbbrv,
      records[count].stateName,
      &records[count].returnNum,
      &records[count].exmptNum,
      &records[count].aggrAgi);

    if (parsed == 9) {
      count++;
    }
  }

  fclose(fp);

  /* print all records */
  printf("Total records loaded: %d\n\n", count);

  for (int i = 0; i < count; i++) {
    printf("[%d] %s %s origin=%d dest=%d agi=%d\n",
           i,
           records[i].stateAbbrv,
           records[i].stateName,
           records[i].stateOrigin,
           records[i].stateCodeDest,
           records[i].aggrAgi);
  }
}
