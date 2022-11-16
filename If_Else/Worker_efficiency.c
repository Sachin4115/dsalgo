#include <stdio.h>

int main()
{
    float hrs;
    printf("Enter the number of hours it takes the worker to complete the job : ");
    scanf("%f",&hrs);
    if(hrs>=2&&hrs<3){
        printf("The worker is highly efficient ighly efficient.");
    }
    else if(hrs>=3&&hrs<4){
        printf("The worker is ordered to improve the speed.");
    }
    else if(hrs>=4&&hrs<5){
        printf("The worker will be trained to improve the speed.");
    }
    else if(hrs>=5){
        printf("The worker have to leave the company.");
    }
    else{
        printf("Please enter the hours correctly.");
    }
    return 0;
}