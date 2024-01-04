#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc != 2) {
        // printf("Key is needed.\n");
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key == 0) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // printf("argc= %i\n", argc);
    string plaintext = get_string("plaintext: ");
    // printf("c: %i\n", plaintext[0]);
    int n = strlen(plaintext);
    char ciphertext[n];
    for (int i = 0; i < n; i++)
    {
         char c = plaintext[i];
         if (c <= 90 && c >= 65)
         {
             ciphertext[i] = ((c + key - 65) % 26) + 65;
         }
         else if (c <= 122 && c>= 97)
         {
             ciphertext[i] = ((c + key - 97) % 26) + 97;
         }
         else
         {
            ciphertext[i] = c;
         }
    }
    printf("ciphertext: %s\n", ciphertext);
}
