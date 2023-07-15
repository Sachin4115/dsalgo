#include <stdio.h>

int main()
{
    int i,j,arr[5]={3,4,2,5,1},temp;
    for(i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    for(i=0;i<5;i++){
        for(j=0;j<4-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return 0;
}