#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);

string rotate (string plaintext, int key);

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
    // printf("c: %i\n", plaintext[0]);
    // int n = strlen(plaintext);
    // char ciphertext[n];
    // char ciphertext[strlen(plaintext)+1];
    // printf("ciphertext %s\n", ciphertext);
    // ciphertext[n] = 0;
    string ciphertext = rotate(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
    // printf("n= %i\n", n);
    return 0;
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(str); i < n; i++){
        if (s[i] < 48 || s[i] >57)
        {
            return false;
        }
    }
    return true;
}

string rotate (string plaintext, int key)
{
    char ciphertext[strlen(plaintext)];
    for (int i = 0, n = strlen(plaintext); i < n; i++)
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
    return ciphertext;
}
