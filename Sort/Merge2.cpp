#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l,int m ,int r){
    int n1=m-l+1;
    int n2=r-m;

    vector<int> a;
    vector<int> b;
    for(int i=0;i<n1;i++){
        a.push_back(arr[l+i]);
    }
    for(int i=0;i<n2;i++){
        b.push_back(arr[m+i+1]);
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k++]=a[i++];
        }else{
            arr[k++]=b[j++];
        }
    }
    while(i<n1){
        arr[k++]=a[i++];
    }
    while(j<n2){
        arr[k++]=b[j++];
    }
}

void div(vector<int> &arr,int s,int r){
    if(s>=r)
        return;
    int m = s + (r-s)/2;
    div(arr,s,m);
    div(arr,m+1,r);
    merge(arr,s,m,r);
}

void mergeSort(vector<int> &arr){
    div(arr,0,arr.size()-1);
}

int main()
{
    vector<int> arr = {7,1,-5,4,9,-3,2,-11,7,4,-2,6,-8,1,6,8,7};
    mergeSort(arr);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}