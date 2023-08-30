#include <iostream>
using namespace std;

int LIndex(int arr[],int n,int x){
    if(n==0)
        return n-1;
    if(x==arr[n-1]){
        return n-1;
    }
    else{
        return LIndex(arr,n-1,x);
    }
}

int main()
{
    int n,element,x;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element at "<<i<<"th index: ";
        cin>>element;
        arr[i]=element;
    }
    cout<<"Enter the element you want to search : ";
    cin>>x;
    cout<<LIndex(arr,n,x);
    return 0;
}