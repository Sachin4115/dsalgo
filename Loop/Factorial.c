#include <stdio.h>

int main()
{
    float num,fact=1;
    printf("Enter the number you want to calculate factorial of : ");
    scanf("\n%f",&num);
    for(int i=1;i<=num;i++){
        fact*=i;
    }
    printf("The factorial of the number %f is %f.",num,fact);
    return 0;
}