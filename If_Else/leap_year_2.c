#include <stdio.h>

int main()
{
    int year;
    printf("Enter the year you want to check : ");
    scanf("%d",&year);

    year%4?printf("%d is not a leap year", year):printf("%d is a leap year", year);

    return 0;
}