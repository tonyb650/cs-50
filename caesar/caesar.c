#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate (char c, int n);

int main(int argc, string argv[])
{
    if(argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    };
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
         plaintext[i] = rotate(plaintext[i], key);
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++){
        if (s[i] < 48 || s[i] >57)
        {
            return false;
        }
    }
    return true;
}

char rotate (char c, int n)
{
    {
         if (c <= 90 && c >= 65)
         {
             c = ((c + n - 65) % 26) + 65;
         }
         else if (c <= 122 && c>= 97)
         {
             c = ((c + n - 97) % 26) + 97;
         }
    }
    return c;
}
