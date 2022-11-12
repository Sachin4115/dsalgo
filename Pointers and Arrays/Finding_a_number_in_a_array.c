#include <stdio.h>
void EnterNumbers(int arr[],int n);
int SearchNumber(int arr[],int n,int s);
int main()
{
    int n,s,arr[n];
    printf("Enter the number of terms in the array : ");
    scanf("%d",&n);
    EnterNumbers(arr,n);
    printf("Enter the number whose occurrence you want to find in the array  : ");
    scanf("%d",&s);
    int x =SearchNumber(arr,n,s);
    printf("The number %d is present %d times in the given array.",s,x);
    return 0;
}
void EnterNumbers(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Enter the %dth number of the array : ",i+1);
        scanf("%d",&arr[i]);
    }
}
int SearchNumber(int arr[],int n,int s){
    int x=0;
    for(int i=0;i<n;i++){
        if(arr[i]==s){
            x++;
        }
    }
    return x;
}