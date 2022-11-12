#include<stdio.h>

int main()
{
    int n;
    do{
        printf("Enter an even number : ");
        scanf("%d",&n);
        if(n%13==0){
            printf("Oops! you entered an multiple of three.");
            break;
        }
    }while(1);
    return 0;
}