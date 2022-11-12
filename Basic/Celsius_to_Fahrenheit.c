#include<stdio.h>

int main()
{
    float Cel,Far;
    printf("Enter the value of Temperature in Celsius\n");
    scanf("%f",&Cel);

    Far=(Cel*9/5)+32;

    printf("The value of the Temperature at %f degree Celsius in %f degree Fahrenheit",Cel, Far);
    return 0;
}