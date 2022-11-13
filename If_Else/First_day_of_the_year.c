#include <stdio.h>

int main()
{
    int year;
    printf("Enter the year you want the first day of : ");
    scanf("%d",&year);
    year-=1900;
    year=year+(year/4);
    year%=7;
    printf("The 1st of January of the year you entered is %dth day of the week(1=monday and 7=sunday)",year+1);
    return 0;
}