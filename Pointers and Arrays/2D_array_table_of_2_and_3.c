#include <stdio.h>
void storetable(int arr[][10],int n,int m,int number);
int main()
{
    int arr[2][10];
    storetable(arr,0,10,2);
    printf("\n");
    storetable(arr,1,10,3);
    return 0;
}
void storetable(int arr[][10],int n,int m,int number){
    for(int i=0;i<10;i++){
        arr[n][i]=number*(i+1);
        printf("%d\t",arr[n][i]);
    }
}