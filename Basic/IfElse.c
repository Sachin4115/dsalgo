#include <stdio.h>

int main()
{
    int a;
    printf("How many animes have you watched ");
    scanf("%d", &a);

    if (a > 30)
    {
        printf("You are a man of culture.\n");
    }
    else
    {
        printf("Give up on your dreams and die.");
    }
    return 0;
}