// Implements a dictionary's functionality
// My solution

#include "dictionary.h"

// Word count
int countDictWords = 0;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word[LENGTH + 1];
    int n = LENGTH + 2;

    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr,"Could not open %s.\n", dictionary);
        return false;
    }

    while (fgets(word, n, file) != NULL)
    {
        word[strlen(word) - 1] = '\0';

        unsigned int k = hash(word);

        node *ptr = (node*) malloc(sizeof(node));
        if (ptr == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(ptr->word, word);

        ptr->next = dict[k];

        dict[k] = ptr;

        countDictWords++;
    }

    fclose(file);
    return true;
}

// Check if word is in the dictionary
bool check(const char* word)
{
    char copyWord[LENGTH + 1];

    int i = 0;

    for (i = 0; word[i] != '\0'; i++)
    {
        copyWord[i] = tolower(word[i]);
    }

    copyWord[i] = '\0';

    unsigned int index = hash(copyWord);

    node* start = dict[index];

    if (start != NULL)
    {
        node *ptr = start;

        while (ptr != NULL)
        {
            if (strcmp(copyWord, ptr->word) == 0)
            {
                return true;
            }
            ptr = ptr->next;
        }
    }
    return false;
}

// Ref: https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
unsigned int hash(const char *word)
{
    unsigned int hash = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        hash = (hash << 2) ^ word[i];
    }
    return hash % HASH_MAX;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < HASH_MAX; i++)
    {
        node *ptr = dict[i];

        while (ptr != NULL)
        {
            node *temp = ptr;
            ptr = temp->next;
            free(temp);
        }
    }
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return countDictWords;
}
