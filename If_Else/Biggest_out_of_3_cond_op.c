#include <stdio.h>

int main()
{
    int a,b,c;
    printf("Enter the first number : ");
    scanf("%d",&a);
    printf("Enter the second number : ");
    scanf("%d",&b);
    printf("Enter the third number : ");
    scanf("%d",&c);

    a>b?(a>c?printf("First number is the biggest."):printf("Third number is the biggest")):(b>c?printf("Second number is the biggest."):printf("Third number is the biggest."));

    return 0;
}