#include <stdio.h>

int main()
{
    int arr[10];
    int *ptr=&arr[0];
    //input
    for(int i=0;i<10;i++){
        printf("Enter the value of %dth index : ",i);
        scanf("%d",(ptr+i));
    }
    for(int i=0;i<10;i++){
        printf("The value of %dth index is %d.\n",i,*(ptr+i));
    }
    return 0;
}