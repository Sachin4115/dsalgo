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
void quicksort(int arr[],int end,int start){
    if(start>=end)
        return;
    int pivot = partition(arr,start,end);
    quicksort(arr,pivot-1,start);
    quicksort(arr,end,pivot+1);
}
int main()
{
    int arr[]={4,1,3,9,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,n-1,0);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}