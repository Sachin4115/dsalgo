#include <stdio.h>

int main()
{
    int year;
    printf("Enter the year you want to check : ");
    scanf("%d",&year);
    (year%4!=0)||(year%100==0&&year%400!=0)?printf("The Entered year is not a leap year."):printf("The Entered year is a leap year.");
    return 0;
}