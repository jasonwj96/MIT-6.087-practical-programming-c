#include "assignment_6b_62.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

struct wordrec *walloc(const char *str) {
  struct wordrec *p = malloc(sizeof(struct wordrec));

  if (p != NULL) {
    p->count = 0;
    p->word = strdup(str); /* creates a duplicate */
    p->next = NULL;
  }

  return p;
}

/* hash table -- array of MAX_BUCKETS linked-list heads */
struct wordrec *table[MAX_BUCKETS];

/*
 * @function hash_string
 * @desc produces hash code for a string
 *       multipliers 31, 35 have been found to work well
 */
unsigned long hash_string(const char *str) {
  unsigned long hash = 0;
  while (*str) {
    hash = hash * MULTIPLIER + *str;
    str++;
  }
  return hash % MAX_BUCKETS;
}

/*
 * @function lookup
 * @desc returns a pointer to the word's record, or creates it if
 *       'create' is non-zero and the word isn't already present.
 *       Returns NULL if not found and create == 0.
 */
struct wordrec *lookup(const char *str, int create) {
  unsigned long hash = hash_string(str);
  struct wordrec *wp = table[hash];
  struct wordrec *curr = NULL;

  for (curr = wp; curr != NULL; curr = curr->next)
    if (strcmp(curr->word, str) == 0) /* found */
      return curr;

  /* not found */
  if (create) {
    curr = walloc(str);
    if (curr == NULL)
      return NULL; /* malloc failed -- caller must check */

    /* add to front */
    curr->next = table[hash];
    table[hash] = curr;
  }

  return curr;
}

/*
 * @function cleartable
 * @desc reclaims all memory held by the table -- every malloc()
 *       (both the wordrec itself and its strdup'd word) is matched
 *       with a free()
 */
void cleartable(void) {
  struct wordrec *wp = NULL, *p = NULL;
  int i = 0;

  for (i = 0; i < MAX_BUCKETS; i++) {
    wp = table[i];
    while (wp) {
      p = wp;
      wp = wp->next;
      free(p->word);
      free(p);
    }
    table[i] = NULL; /* avoid a dangling/reused pointer if cleartable() is ever called twice */
  }
}

void problem_6b_62(int argc, char *argv[]) {
  const char *filename = (argc > 1) ? argv[1] : "book.txt";
  FILE *fp = fopen(filename, "r");
  char word[1024]; /* big enough */
  struct wordrec *wp = NULL;
  int i = 0;

  if (fp == NULL) {
    fprintf(stderr, "could not open %s\n", filename);
  }

  memset(table, 0, sizeof(table));

  /* read from input */
  while (1) {
    if (fscanf(fp, "%1023s", word) != 1) /* width limit avoids overflowing word[] */
      break;
    wp = lookup(word, 1); /* create if doesn't exist */
    if (wp == NULL) {
      fprintf(stderr, "out of memory\n");
      fclose(fp);
    }
    wp->count++;
  }
  fclose(fp);

  /* print all words with frequency > 1000 */
  for (i = 0; i < MAX_BUCKETS; i++) {
    for (wp = table[i]; wp != NULL; wp = wp->next) {
      if (wp->count > 1000) {
        printf("%s-->%ld\n", wp->word, wp->count);
      }
    }
  }

  cleartable();
}
