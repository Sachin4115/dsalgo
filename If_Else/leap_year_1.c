#include <stdio.h>

int main()
{
    int year;
    printf("Enter the year you want to check : ");
    scanf("%d",&year);
    if(year%4){
        printf("%d is not a leap year", year);
    }
    else{
        printf("%d is a leap year", year);
    }
    return 0;
}