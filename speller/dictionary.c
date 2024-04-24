// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// ****LOADS**** dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dictFile = fopen(dictionary, "r");
    if (dictFile == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    char word[LENGTH + 1];
    while(fscanf(dictFile, "%s", word)!=EOF)
    {
        printf("Word =  %s.\n", word);
        unsigned int bucket = hash(word);
        printf("Bucket =  %i.\n", bucket);
        // create new node and insert in linked list
        node *n = malloc(sizeof(node));
        if(n==NULL){
            return false;
        }
        strcpy(n->word, word); //strcpy means "string copy", it copies a string from a source into a destination
        n->next = table[bucket];
        table[bucket] = n;
    }
    fclose(dictFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
