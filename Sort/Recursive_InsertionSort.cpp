#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &arr,int i,int n){
    if(i<0){
        return;
    }
    if(arr[i]>arr[n]){
        int t=arr[i];
        arr[i]=arr[n];
        arr[n]=t;
        helper(arr,i-1,i);
    }else{
        return;
    }
}

void insertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        helper(arr,i-1,i);
    }
}

int main()
{
    vector<int> arr = {7,1,-5,4,9,-3,2,-11,7,4,-2,6,-8,1,6,8,7};
    insertionSort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}