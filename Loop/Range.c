#include <stdio.h>

int main()
{
    int num,max,min,turn;
    printf("Enter the number of terms you want to enter : ");
    scanf("%d",&turn);
    for(int i=1;i<=turn;i++){
        printf("Enter the numbers in the set : ");
        scanf("%d",&num);
        if(num>max){
            max=num;
        }
        else if(num<min){
            min=num;
        }
    }
    printf("The range of the set of the numbers entered by the user is [%d,%d]",min,max);
    return 0;
}