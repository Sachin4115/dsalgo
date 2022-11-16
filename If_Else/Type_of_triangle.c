#include <stdio.h>

int main()
{
    int a,b,c;
    printf("Enter the first side of the triangle : ");
    scanf("%d", &a);
    printf("Enter the second side of the triangle : ");
    scanf("%d", &b);
    printf("Enter the third side of the triangle : ");
    scanf("%d", &c);
    if(a==b&&a==c){
        printf("The enetered triangle is equilateral.");
    }
    else if(a==b||a==c){
        printf("The enetered triangle is isosceles.");
    }
    else{
        printf("The enetered triangle is scalene.");
    }
    if (a >= b && a >= c)
    {
        if (b*b + c*c ==  a*a)
        {
            printf("\nThe triangle entered is right angled triangle.");
        }
        else{
            printf("\nThe triangle that you have entered is not right angled triangle.");
        }
    }
    else if (b >= c && b >= a)
    {
        if (a*a + c*c == b*b)
        {
            printf("\nThe triangle entered is right angled triangle.");
        }
        else{
            printf("\nThe triangle that you have entered is not right angled triangle.");
        }
    }
    else if (c >= a && c >= b)
    {
        if (a*a + b*b == c*c)
        {
            printf("\nThe triangle entered is right angled triangle.");
        }
        else{
            printf("\nThe triangle that you have entered is not right angled triangle.");
        }
    }
    return 0;
}