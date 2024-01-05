#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string textBlock = get_string("Text: ");
    int characters = strlen(textBlock);
    int sentences = 0;
    int spaces = 0;
    int letters = characters;
    for (int i = 0; i < characters; i++)
    {
        if (textBlock[i] == 32) // space
        {
            spaces++;
            letters--;
        }
        else if (textBlock[i] == 46 || textBlock[i] == 33 || textBlock[i] == 63) // period, exclamation mark, question mark
        {
            sentences++;
            letters--;
        }
        else if (textBlock[i] <65 || textBlock[i] > 122 || (textBlock[i] > 90 && textBlock[i] < 97)) // other punctuation or numbers
        {
            letters--;
        }
    }

    int words = spaces + 1;

    // calculate L (letters/(words/100))
    // where L is the average number of letters per 100 words in the text,
    float L = (float) letters / ((float) words/100);

    // calculate S (sentences/(words/100))
    // where S is the average number of sentences per 100 words in the text.
    float S = (float) sentences / ((float)words/100);

    // Finally, calculate index
    float index = round(0.0588 * L - 0.296 * S -15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
    return 0;
}
