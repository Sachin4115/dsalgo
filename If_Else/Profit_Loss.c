#include <stdio.h>

int main()
{
    float cp,sp;
    printf("Enter the cost price of the product sold : ");
    scanf("%f",&cp);

    printf("Enter the selling price of the product sold : ");
    scanf("%f",&sp);

    if(sp>cp){
        printf("You have made profit of Rs%f",sp-cp);
    }
    else{
        printf("You have incurred loss of Rs%f",cp-sp);
    }
    return 0;
}