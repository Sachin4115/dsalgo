#include <stdio.h>
void EnterNumbers(int arr[],int n);
int LargestNumber(int arr[],int n);
int main()
{
    int n,arr[n];
    printf("Enter the number of terms in the array : ");
    scanf("%d",&n);
    EnterNumbers(arr,n);
    int largestnumber = LargestNumber(arr,n);
    printf("The largest number in the array is %d",largestnumber);
    return 0;
}
void EnterNumbers(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Enter the %dth number of the array : ",i+1);
        scanf("%d",&arr[i]);
}
}
int LargestNumber(int arr[],int n){
    for(int i=0;i<n;i++){
        int x = 0;
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
            x=1;
        }
        }
        if(x == 0){
            return arr[i];
        }
    }
}