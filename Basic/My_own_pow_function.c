#include <stdio.h>
float Pow(float n,float p);
int main()
{
    float number,power;
    printf("Enter the number whose power you want to calculate : ");
    scanf("%f",&number);
    printf("Enter the power of the number that you want to calculate : ");
    scanf("%f",&power);
    printf("The number %f raised to the power %f is %f.",number,power,Pow(number,power));
    return 0;
}

float Pow(float n,float p){
    if (p==0){
        return 1;
    }
    float ansdn=Pow(n,p-1);
    float ans=ansdn*n;
    return ans;
}