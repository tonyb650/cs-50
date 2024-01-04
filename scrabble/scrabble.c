#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    printf("Score1 %i\n",score1);
    printf("Score2 %i\n",score2);
    if(score1>score2)
    {
        printf("The winner is player 1\n");
    }
    else if (score1<score2)
    {
        printf("The winner is player 2\n");
    }
    else
    {
        printf("There is no winner\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // int i = strlen(word);
    int score = 0;
    for(int i = 0, int n = strlen(word) ; i < n; i++)
    {
        char c = word[i];
        if(islower(c))
        {
            c -= 32;
        }
        printf("char %c &  %d\n", c, c);
        printf("value= %i\n", POINTS[c-65]);
        score += POINTS[c-65];
    }
    return score;
}
