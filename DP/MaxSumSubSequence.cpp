#include <iostream>
using namespace std;

int main()
{
    int n=10,ans=0;
    int arr[n] = {10,22,9,33,21,50,41,60,80,3};
    int dp[n];
    for(int i=0;i<n;i++){
        int m=0;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]) m=max(m,dp[j]);
        }
        dp[i]=m+arr[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}