// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 500;

// Store size of dictionary
int dictWordCount = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // get the hash value for the word in the text
    unsigned int bucket = hash(word);
    // get the pointer to the 'head' of that bucket
    node *n = table[bucket];
    // loop through the linked list of words a that bucket
    while(n != NULL){
        // compare the word in the linked list (n->word) with the word from the text (word)
        if(strcasecmp(n->word,word)==0){
            // the word IS in the linked list, therefore return true
            return true;
        }
        n = n->next;
    }
    // we've got to the end of the linked list and didn't find the word
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // start with a hash value of 0
    int hashVal = 0;
    // loop through each character in the word, starting with the last
    for (int i = strlen(word); i >= 0; i--)
    {
        // multiply the 
        hashVal = hashVal + (toupper(word[i])-'A')*i;
    }
    return hashVal % N;
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
        dictWordCount++;
        // printf("Word =  %s.\n", word);
        unsigned int bucket = hash(word);
        // printf("Bucket =  %i.\n", bucket);
        // create new node and insert in linked list
        node *n = malloc(sizeof(node));
        if(n==NULL){
            printf("Memory not allocated \n");
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
    return dictWordCount;
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // loop through buckets, then through nodes
    for (int bucket = 0; bucket < N; bucket++)
    {
        node *n = table[bucket];
        while ( n != NULL)
        {
            node *nextNode = n->next;
            free(n);
            n = nextNode;
        }
    }
    return true;
}
