#include <stdio.h>

int main()
{
    int n,arr[n],k,ones,to_be_replaced=0,max=0,result=0;
    printf("Enter the number of digits in the array : ");
    scanf("%d",&n);
    printf("Enter the minimum number of replacement : ");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        printf("Enter the %d value of the array : ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<n;j++){
        to_be_replaced=0,max=0,ones=0;
    for(int i=j;i<n;i++){
        if(arr[i]==1){
            ones++;
            max++;
        }
        else{
            to_be_replaced++;
            if(to_be_replaced>k){
                break;
            }
            max++;
        }
        if(max>result){
            result=max;
        }
    }
    }
    printf("%d",result);
    return 0;
}