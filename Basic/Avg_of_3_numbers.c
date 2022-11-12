#include<stdio.h>

int main()
{
    float a,b,c;
    printf("Enter the first number");
    scanf("%f",&a);
    printf("Enter the second number");
    scanf("%f",&b);
    printf("Enter the third number");
    scanf("%f",&c);
    printf("Average of the given numbers is %f", (a+b+c)/3);
    return 0;
}