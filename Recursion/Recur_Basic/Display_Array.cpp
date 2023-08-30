#include <iostream>
using namespace std;

void PrintArray(int arr[],int n){
    if(n==0)
        return;
    PrintArray(arr,n-1);
    cout<<arr[n-1]<<" ";
}

int main()
{
    int n,element;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element at "<<i<<"th index: ";
        cin>>element;
        arr[i]=element;
    }
    PrintArray(arr,n);
    return 0;
}