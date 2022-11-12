#include <stdio.h>

int main()
{
    float price[3];
    printf("Enter the price of first item : ");
    scanf("%f",&price[0]);
    printf("Enter the price of second item : ");
    scanf("%f",&price[1]);
    printf("Enter the price of third item : ");
    scanf("%f",&price[2]);
    for(int i=0;i<3;i++){
        price[i]=price[i]+(0.18*price[i]);
    }
    printf("New prices of first , second and third item if %f , %f and %f respectively.",price[0],price[1],price[2]);
    return 0;
}