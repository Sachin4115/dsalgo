#include <iostream>
using namespace std;

int main()
{
    int n=6;
    int arr[n] = {5,10,10,100,5,6};
    int a = arr[0];
    int b = max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
        int c = max(a+arr[i],b);
        a=b;
        b=c;
    }
    cout<<b;
    return 0;
}