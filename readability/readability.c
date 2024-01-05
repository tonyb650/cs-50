#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string textBlock = get_string("Text: ");
    int grade = 3;
    // index = 0.0588 * L - 0.296 * S -15.8;
    // where L is the average number of letters per 100 words in the text,
    // and S is the average number of sentences per 100 words in the text.
    printf("Grade %i\n", grade);
    return 0;
}
