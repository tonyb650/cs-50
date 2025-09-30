// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

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
    while (n != NULL)
    {
        // compare the word in the linked list (n->word) with the word from the text (word)
        if (strcasecmp(n->word, word) == 0)
        {
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
        // multiply the letter value(0-26) by it's position (0-strlen(word)). Then add result to
        // hashVal
        hashVal = hashVal + (toupper(word[i]) - 'A') * i;
    }
    // final hash = hashVal mod N (total number of buckets)
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
    // initialize string 'word' to max possible word length
    char word[LENGTH + 1];
    // fscanf loads one word at a time from the file opened above, until "End Of File"
    while (fscanf(dictFile, "%s", word) != EOF)
    {
        // keep track of the size of our dictionary as we add to it
        dictWordCount++;
        // get a hash value for the newly retrieved word
        unsigned int bucket = hash(word);
        // create new node and insert in linked list
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Memory not allocated \n");
            return false;
        }
        // copy the word from the file into the new node.word location
        strcpy(n->word, word); // strcpy means "string copy", it copies a string from a source into
                               // a destination
        // set the 'node.next' pointer on the newly created node to point to the previous 'head'
        // node
        n->next = table[bucket];
        // set the pointer in the hash table to point to the newly created node
        table[bucket] = n;
    }
    fclose(dictFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictWordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // loop through buckets in hash table
    for (int bucket = 0; bucket < N; bucket++)
    {
        // retrieve the pointer to the head node from the hash table for this 'bucket'
        node *n = table[bucket];
        // loop through all the nodes in the linked list at this 'bucket'
        while (n != NULL)
        {
            // set a temp node so we know where to go next
            node *nextNode = n->next;
            // free the memory
            free(n);
            // move to the temp node
            n = nextNode;
        }
    }
    return true;
}
