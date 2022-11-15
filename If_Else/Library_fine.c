#include <stdio.h>

int main()
{
    int days;
    printf("Enter the number of days the member is late to submit the book : ");
    scanf("%d",&days);
    if(days==5){
        printf("Fine of 0.50 rupees");
    }
    else if(days>5&&days<10){
        printf("Fine of 1 rupees");
    }
    else if(days>10&&days<30){
        printf("Fine of 5 rupees");
    }
    else if(days>30){
        printf("Your membership is cancelled.");
    }
    return 0;
}