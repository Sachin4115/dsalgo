#include<stdio.h>

int main()
{
    int n;
    do{
        printf("Enter an even number : ");
        scanf("%d",&n);
        if(n%2==1){
            printf("Oops! you entered an odd number.");
            break;
        }
    }while(1);
    return 0;
}