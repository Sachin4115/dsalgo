#include <stdio.h>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("*  ");
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*  ");
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 6; j > i; j--)
        {
            printf("*  ");
        }
        printf("\n");
    }


    return 0;
}