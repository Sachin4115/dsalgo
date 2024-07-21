#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int> &arr,int i,int n){
    if(i==arr.size()-1-n)
        return;
    if(arr[i]>arr[i+1]){
        int t=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=t;
    }
    helper(arr,i+1,n);
}

void bubbleSort(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        helper(arr,0,i);
    }
}

int main()
{
    vector<int> arr = {7,1,-5,4,9,-3,2,-11,7,4,-2,6,-8,1,6,8,7};
    bubbleSort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}