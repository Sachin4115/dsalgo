#include <stdio.h>

int main()
{
    int marks;
    printf("Enter your number[0-100]:  ");
    scanf("%d", &marks);

    if (marks >= 35 && marks <= 100)
    {
        printf("Pass\n");
    }
    else if (marks >= 0 && marks < 35)
    {
        printf("Fail\n");
    }
    else
    {
        printf("Marks must be beween 0 to 100\n");
    }

//By Ternary Operator
    marks >= 35 ? printf("Pass\n") : printf("Fail\n");
    return 0;
}