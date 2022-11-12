#include <stdio.h>

int main()
{
    int a;
    printf("How many animes have you watched ");
    scanf("%d", &a);

    if (a >= 100)
    {
        printf("You are a man of culture.\n");
    }
    else if(a >= 50 && a < 100)
    {
        printf("Parenting done right");
    }
    else if(a > 0 && a < 50)
    {
        printf("Newbie");
    }
    else
    {
        printf("Give up on your dreams and die.");
    }
    return 0;
}