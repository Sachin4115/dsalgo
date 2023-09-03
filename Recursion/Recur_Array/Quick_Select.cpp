#include <iostream>
using namespace std;
int partition(int arr[],int start,int end){
    int pivot=arr[end];
    int PI=start;
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[PI]);
            PI++;
        }
    }
    swap(arr[PI],arr[end]);
    return PI;
}
int quickselect(int arr[],int k,int end,int start){
    int pivot = partition(arr,start,end);
    if(pivot>k)
        return quickselect(arr,k,pivot-1,start);
    else if(pivot<k)
        return quickselect(arr,k,end,pivot+1);
    else
        return pivot;
}
int main()
{
    int arr[]={7,4,6,3,9,1};
    int k=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<quickselect(arr,k-1,n-1,0);
    return 0;
}