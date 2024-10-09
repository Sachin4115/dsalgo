#include <iostream>
using namespace std;

int main()
{
    int n = 9;
    int arr[n] = {11,6,7,19,4,1,6,18,4};
    int m=arr[0];
    int a = 0;
    for(int i=1;i<n;i++){
        a=max(a,arr[i]-m);
        m=min(m,arr[i]);
    }
    cout<<a;
    return 0;
}