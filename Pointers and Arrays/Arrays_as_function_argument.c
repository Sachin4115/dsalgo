#include <stdio.h>

void Printnumbers(int *arr,int n); //array as pointer.
void printnumbers(int arr[],int n);//Array as array.
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    printnumbers(arr,10);
    printf("\n");
    printnumbers(arr,10);
    return 0;
}
void printnumbers(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
void Printnumbers(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}