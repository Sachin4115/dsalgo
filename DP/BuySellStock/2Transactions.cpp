#include <iostream>
using namespace std;

int main()
{
    int n = 12;
    int arr[n] = {10,15,17,20,16,18,22,20,22,20,23,25};
    int dp1[n],dp2[n],m=arr[0];
    dp1[0]=0;
    for(int i=1;i<n;i++){
        m=min(m,arr[i]);
        dp1[i]=max(dp1[i-1],arr[i]-m);
    }
    dp2[n-1]=0;
    int M=arr[n-1];
    for(int i=n-2;i>=0;i--){
        M=max(arr[i],M);
        dp2[i]=max(dp2[i+1],M-arr[i]);
    }
    int a=0;
    for(int i=0;i<n;i++){
        a=max(a,dp1[i]+dp2[i]);
    }
    cout<<a;
    return 0;
}