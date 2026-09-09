#pragma once

#define MAX_BUCKETS 1000
#define MULTIPLIER 31
#define MAX_LEN 100

struct wordrec {
  char *word;
  unsigned long count;
  struct wordrec *next;
};

struct wordrec *walloc(const char *str);

unsigned long hash_string(const char *str);

struct wordrec *lookup(const char *str, int create);

void cleartable(void);

/* hash table -- array of MAX_BUCKETS linked-list heads */
extern struct wordrec *table[MAX_BUCKETS];

void problem_6b_62(int argc, char *argv[]);
