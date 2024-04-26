#include <iostream>
using namespace std;

int main()
{
    int n1=5,n2=6;
    int arr1[n1] = {9,9,9,9,9};
    int arr2[n2] = {1,9,9,9,9,9};

    for(int i=0;i<n1;i++){
        if(arr1[n1-i-1]<=arr2[n2-i-1]){
            arr2[n2-i-1]=arr2[n2-i-1]-arr1[n1-i-1];
        }else{
            arr2[n2-2-i]--;
            arr2[n2-i-1]+=10;
            arr2[n2-i-1]=arr2[n2-i-1]-arr1[n1-i-1];
        }
    }

    int f = 1;
    for(int i=0;i<n2;i++){
        if(f==1 && arr2[i]==0){
            continue;
        }
        cout<<arr2[i];
        f=0;
    }

    return 0;
}