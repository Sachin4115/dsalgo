#include<stdio.h>

int main()
{
    int n;
    printf("Enter the sum");
    scanf("%d",&n);
    for(int sum=0,i=1;i<=100;i++){
        sum=sum+i;
        if(sum>n){
            break;
        }
        printf("%d\n",i);
    }
    printf("The End");
    return 0;
}