#include "assignment_6a_62.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct trie_node *proot = NULL;

/* allocate a new node on the heap
 * output: pointer to new node (caller must eventually free via delete_node) */
struct trie_node *new_node(void) {
  struct trie_node *pnode = malloc(sizeof(struct trie_node));

  if (!pnode) {
    return NULL;
  }

  pnode->translation = NULL;

  for (int i = 0; i < UCHAR_MAX + 1; i++) {
    pnode->children[i] = NULL;
  }

  return pnode;
}

/* delete node and all its children (recursively)
 * input: pointer to node to delete
 * postcondition: node, its children, and any translation strings are freed */
void delete_node(struct trie_node *pnode) {
  if (!pnode) {
    return;
  }

  if (pnode->translation) {
    free(pnode->translation);
  }

  for (int i = 0; i < UCHAR_MAX + 1; i++) {
    if (pnode->children[i]) {
      delete_node(pnode->children[i]);
    }
  }

  free(pnode);
}

/* add word to trie, with translation
 * input: word and translation
 * output: non-zero if a new node was created for the final character, zero otherwise
 * postcondition: word exists in trie, translation is stored (appended if word already existed) */
int add_word(const char *word, char *translation) {
  struct trie_node *pnode = proot;

  const int len = strlen(word);

  int inew = 0;

  for (int i = 0; i < len; i++) {
    const unsigned char j = word[i];

    if ((inew = !pnode->children[j])) {
      pnode->children[j] = new_node();
    }

    pnode = pnode->children[j];
  }

  if (pnode->translation) {
    /* word already has translation(s) -- append this one, comma-separated */
    char *old_translation = pnode->translation;
    const int old_len = strlen(old_translation);
    const int new_len = strlen(translation);

    pnode->translation = malloc(old_len + new_len + 2); /* +1 comma, +1 null terminator */

    strcpy(pnode->translation, old_translation);
    strcpy(pnode->translation + old_len, ",");
    strcpy(pnode->translation + old_len + 1, translation);
    free(old_translation);
  } else {
    /* store our own copy -- caller's translation string is reused elsewhere */
    pnode->translation = malloc(strlen(translation) + 1);
    strcpy(pnode->translation, translation);
  }

  return inew;
}

/* search trie structure for word and return translation(s)
 * input: word to search for
 * output: translation string, or NULL if word is not found */
char *lookup_word(const char *word) {
  struct trie_node *pnode = proot;
  const int len = strlen(word);

  for (int i = 0; i < len; i++) {
    unsigned char j = (unsigned char) word[i];

    if (!pnode->children[j]) {
      return NULL;
    }

    pnode = pnode->children[j];
  }

  return pnode->translation;
}

void problem_6a_62() {
  proot = new_node();

  add_word("like", "comme");
  add_word("like", "aimer"); /* second meaning -- should append, not overwrite */
  add_word("and", "et");
  add_word("cat", "chat");

  printf("like -> %s\n", lookup_word("like"));
  printf("and  -> %s\n", lookup_word("and"));
  printf("cat  -> %s\n", lookup_word("cat"));

  char *missing = lookup_word("dog");
  printf("dog  -> %s\n", missing ? missing : "(not found)");

  delete_node(proot);
}
