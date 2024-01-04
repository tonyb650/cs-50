#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if(argc < 2) {
        printf("Key is needed.\n");
        return 1;
    }
    // printf("argc= %i\n", argc);
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    // printf("c: %i\n", plaintext[0]);
    int n = strlen(plaintext);
    char ciphertext[n];
    for (int i = 0; i < n; i++)
    {
         char c = plaintext[i];
         if (c <= 90 && c >= 65)
         {
             ciphertext[i] = (c + key - 65) % 26;
         }
         else if (c <= 122 && c>= 97)
         {
             ciphertext[i] = (c + key - 65) % 26;
         }
    }
    printf("ciphertext: %s\n", ciphertext);
}
