#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // TODO: Prompt for start size
    int n = 0;
    while(n<=9)
    {
        n = get_int("Enter starting llama population. Positive Integer: ");
    }
    printf(" %i\n",n);
    // TODO: Prompt for end size
    int e = 0;
    while(e<n)
    {
        e = get_int("Enter ending llama population. Positive Integer: ");
    }
    printf(" %i\n",e);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while(n<e){
        n = n + trunc(n/3) - trunc(n/4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
