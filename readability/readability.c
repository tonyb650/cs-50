#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string textBlock = get_string("Text: ");
    int characters = strlen(textBlock);
    int periods = 0;
    int spaces = 0;
    int letters = characters;
    for (int i = 0; i < characters; i++)
    {
        if (textBlock[i] == 32) // space
        {
            spaces++;
            letters--;
        }
        else if (textBlock[i] == 46) //period
        {
            periods++;
            letters--;
        }
        else if (textBlock[i] <65 || textBlock[i] > 122 || (textBlock[i] > 90 && textBlock[i] < 97)) // other punctuation
        {
            letters--;
        }
    }
    printf("Spaces %i\n", spaces);
    printf("periods %i\n", periods);
    printf("Letters %i\n", letters);
    // index = 0.0588 * L - 0.296 * S -15.8;
    // where L is the average number of letters per 100 words in the text,
    // and S is the average number of sentences per 100 words in the text.
    // Steps:
    // - get word count
    
    // - get letter count
    // calculate L (letters/(words/100))
    // - get number of sentences
    // - calculate S (sentences/(words/100))
    //
    int index = 3;
    if (index < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}
