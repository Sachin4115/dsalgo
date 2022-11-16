#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter the first side of the triangle : ");
    scanf("%d", &a);
    printf("Enter the second side of the triangle : ");
    scanf("%d", &b);
    printf("Enter the third side of the triangle : ");
    scanf("%d", &c);
    if (a > b && a > c)
    {
        if (b + c > a)
        {
            printf("The triangle entered is valid.");
        }
        else{
            printf("The triangle that you have entered is not valid.");
        }
    }
    else if (b > c && b > a)
    {
        if (a + c > b)
        {
            printf("The triangle entered is valid.");
        }
        else{
            printf("The triangle that you have entered is not valid.");
        }
    }
    else if (c > a && c > b)
    {
        if (a + b > c)
        {
            printf("The triangle entered is valid.");
        }
        else{
            printf("The triangle that you have entered is not valid.");
        }
    }
    return 0;
}