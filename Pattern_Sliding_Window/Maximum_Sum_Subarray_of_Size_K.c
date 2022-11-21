#include <stdio.h>

int main()
{
    int max_sum=0,window_sum=0,i,j,n=5,k,arr[n];
    printf("Enter the number of terms in the array : ");
    scanf("%d",&n);
    printf("Enter the size of the subarray : ");
    scanf("%d",&k);
    for(i=0;i<n;i++){
        printf("Enter the Numbers of the array at position %d : ",i);
        scanf("%d",&arr[i]);
    }
    for(j=0;j<n;j++){
        window_sum=window_sum+arr[j];
        if(j>=(k-1)){
            if(window_sum>max_sum){
                max_sum=window_sum;
            }
             window_sum=window_sum-arr[j-k+1];
        }
    }
    printf("%d",max_sum);
    return 0;
}