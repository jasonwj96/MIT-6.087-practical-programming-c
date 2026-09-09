#pragma once

#include <limits.h>

struct trie_node {
  char *translation;
  struct trie_node *children[UCHAR_MAX + 1];
};

struct trie_node *new_node(void);
void delete_node(struct trie_node *pnode);
int add_word(const char *word, char *translation);
char *lookup_word(const char *word);
void problem_6a_62(void);

extern struct trie_node *proot;

