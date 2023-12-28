#include <cs50.h>
#include <stdio.h>

int main(void)
{
    do {
        int height = get_int("Height: ");
    } while (height < 1 || height >8);
    for(let i = 0; i < height; i++)
    {
        for(let j = 0 ; j < i ; j++)
        {
            printf(" ");
        }
        printf("#\n");
    }
}
