#include <stdio.h>
//In array changes are done every time it is changed by any function because arrays are always called by refrence and never by value.
void reverse(int arr[],int n);
int main()
{
    int n,arr[n];
    printf("Enter the index of array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the %dth term of the array : ",i);
        scanf("%d",&arr[i]);
    }
    reverse(arr,n);
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
void reverse(int arr[],int n){
    for(int i=0;i<n/2;i++){
        int temp = arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }

}