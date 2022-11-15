#include <stdio.h>

int main()
{
    int year;
    printf("Enter the year you want to check : ");
    scanf("%d",&year);
    if((year%4!=0)||((year%100==0)&&(year%400!=0))){
        printf("The entered year %d is not a leap year.",year);
    }
    else{
        printf("The entered year %d is a leap year.",year);
    }
    return 0;
}