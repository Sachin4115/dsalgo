#include <iostream>
using namespace std;

int main()
{
    int n1=5,n2=6;
    int arr1[n1]={9,3,8,9,2};
    int arr2[n2]={9,2,3,4,9,7};


    int n = n1>n2?n1:n2;
    int arr[n];

    int c = 0;
    for(int i=0;i<n;i++){
        int s = c;
        if((n1-i-1)>=0){
            s+=arr1[n1-i-1];
        }
        if((n2-i-1)>=0){
            s+=arr2[n2-i-1];
        }
        if(s>9){
            s%=10;
            c=1;
        }else{
            c=0;
        }
        arr[n-i-1] = s;
    }
    if(c==1)
        cout<<c;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}