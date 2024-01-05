#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string textBlock = get_string("Text: ");
    int characters = strlen(textBlock);
    int scentenceEnds = 0;
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
            scentenceEnds++;
            letters--;
        }
        else if (textBlock[i] <65 || textBlock[i] > 122 || (textBlock[i] > 90 && textBlock[i] < 97)) // other punctuation
        {
            letters--;
        }
    }
    printf("Spaces %i\n", spaces);
    printf("scentenceEnds %i\n", scentenceEnds);
    printf("Letters %i\n", letters);
    // index = 0.0588 * L - 0.296 * S -15.8;
    // where L is the average number of letters per 100 words in the text,
    // and S is the average number of sentences per 100 words in the text.
    // Steps:
    // - get word count
    int words = spaces + 1;
    // - get letter count

    // calculate L (letters/(words/100))
    int L = round(letters / (words/100));
    // - get number of sentences
    int sentences = scentenceEnds;
    // - calculate S (sentences/(words/100))
    int S = round(sentences / (words/100));
    printf("S %i\n", S);
    printf("L %i\n", L);

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
