#include<stdio.h>

int main()
{
    float Principal, Rate, Time, Simple_Interest;

    printf("Enter the value of the Principal amount\n");
    scanf("%f",&Principal);

    printf("Enter the value of the Rate\n");
    scanf("%f",&Rate);

    printf("Enter the value of the Time in YEARS\n");
    scanf("%f",&Time);

    Simple_Interest = Principal * Rate * Time / 100;

    printf("The value of the Simple Interest is %f",Simple_Interest);
    return 0;
}