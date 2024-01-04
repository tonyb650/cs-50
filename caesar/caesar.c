#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    printf("c: %c\n", plaintext[0]);
    // int n = strlen(plaintext);
    // char* ciphertext[n];
    // for (int i = 0; i < n; i++)
    // {
    //     char c = plaintext[i];
    //     ciphertext[i] = c;
    // }
    // printf("ciphertext: %s\n", ciphertext);
}
