#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height >8);
    for(int i = 1; i <= height; i++)
    {
        for(int j = 1 ; j <= height ; j++)
        {
            if(j<=height-i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
