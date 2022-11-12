#include<stdio.h>

int main()
{
    int num;
    printf("Enter the number that you want to check : ");
    scanf("%d",&num);
    for(int i = 2;i<num-1;i++){
        if(num%i == 0){
            printf("The number is not Prime.");
            num=0;
            break;
        }
    }
    if(num){
        printf("The number is a Prime.");
    }
    return 0;
}