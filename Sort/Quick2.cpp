#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int l, int r){
    int pivot = arr[r];
    int pi=l;
    for(int i=l;i<r;i++){
        if(arr[i]<=pivot){
            int temp=arr[i];
            arr[i]=arr[pi];
            arr[pi]=temp;
            pi++;
        }
    }
    int temp=arr[r];
    arr[r]=arr[pi];
    arr[pi]=temp;
    return pi;
}

void Div(vector<int> &arr,int l,int r){
    if(l>=r)
        return;
    int pivot=partition(arr,l,r);
    Div(arr,l,pivot-1);
    Div(arr,pivot+1,r);
}

void quickSort(vector<int> &arr){
    Div(arr,0,arr.size()-1);
}

int main()
{
    vector<int> arr = {7,1,-5,4,9,-3,2,-11,7,4,-2,6,-8,1,6,8,7};
    quickSort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}