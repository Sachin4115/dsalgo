#include <stdio.h>

int main()
{
    int arr[10],p=0;
    for(int i=0;i<10;i++){
        printf("Enter the value of %dth term of the array : ",i);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<10;i++){
        if(arr[i]%2 == 1){
            p++;
            printf("The %dth term of the array %d is odd.\n",i,arr[i]);
        }
    }
    printf("There are total %d odd terms in the array",p);

    return 0;
}