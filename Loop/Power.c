#include <stdio.h>

int main()
{
    float base,power,result=1;
    printf("Enter the base number : ");
    scanf("\n%f",&base);
    printf("Enter the power number : ");
    scanf("\n%f",&power);

    for(int i=1;i<=power;i++){
        result*=base;
    }
    printf("The number %f raise to the power %f is equal to %f",base,power,result);
    return 0;
}