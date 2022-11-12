#include<stdio.h>

int main()
{
    int i,n,sum=0;
    printf("Enter the number of terms that you want to add");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        sum=sum+i;
    }
    printf("The value of the required sum is %d : ",sum);

    return 0;
}