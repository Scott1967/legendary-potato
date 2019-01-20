// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define HASH_MAX 143091

// Structure
typedef struct _node
{
    char word[LENGTH + 1];
    struct _node* next;
}
node;

// An array of pointers
node* dict[HASH_MAX];

// Prototypes
bool load(const char *dictionary);
bool check(const char *word);
unsigned int size(void);
bool unload(void);

// Ref: https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
unsigned int hash(const char *word);

#endif // DICTIONARY_H
