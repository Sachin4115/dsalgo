#include<stdio.h>

int main()
{
    int n,sum=0;
    printf("Enter the number of terms that you want to add");
    scanf("%d",&n);
    // for(int i=1,j=n;i<=n && j>0;i++,j--){
    //     printf("%d\n",j);
    //     sum=sum+i;
    // }
    // printf("%d",sum);
    //**************************//
    //            OR            //
    //**************************//
    for(int j=n; j>0;j--){
    printf("%d\n",j);
    sum=sum+j;
    }
    printf("%d",sum);
    return 0;
}