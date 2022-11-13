#include <stdio.h>

int main()
{
    int num;
    printf("Enter the number you want to check : ");
    scanf("%d",&num);

    num%2?printf("The number you have entered is odd"):printf("The number you have entered is even");

    return 0;
}