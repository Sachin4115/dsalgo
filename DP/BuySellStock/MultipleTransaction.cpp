#include <iostream>
using namespace std;

int main()
{
    int n = 9;
    int arr[n] = {11,6,7,19,4,1,6,18,4};
    int a = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1])
            a+=(arr[i]-arr[i-1]);
    }
    cout<<a;
    return 0;
}