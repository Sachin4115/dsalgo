#include <stdio.h>

int main()
{
    int i,j,n,sum,x,num,k,arr[n];
    printf("Enter the number of elements in the array : ");
    scanf("%d",&n);
    printf("Enter the number you want to compare the sum to : ");
    scanf("%d",&num);
    x=n;
    for(k=0;k<n;k++){
        printf("Enter the Numbers of the array at position %d : ",k);
        scanf("%d",&arr[k]);
    }
    for(j=0;j<n;j++){
        sum=0;
        for(i=j;i<n;i++){
            sum+=arr[i];
            if(sum>=num){
                if((i-j+1)<x){
                    x=i-j+1;
                }
            }
        }
    }
    printf("%d",x);
    return 0;
}