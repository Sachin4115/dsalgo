#include <iostream>
using namespace std;

int main()
{
    int n=10,ans=0,m,m1,m2;
    int arr[n]={10,22,9,33,21,50,41,60,80,3};
    int dp[n][2];
    // for(int i=0;i<n;i++){
    //     m=0;
    //     for(int j=i-1;j>=0;j--){
    //         if(arr[i]>arr[j]) m=max(m,dp[j][0]);
    //     }
    //     dp[i][0]=m+1;
    // }
    // for(int i=n-1;i>=0;i--){
    //     m=0;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]>arr[j]) m=max(m,dp[j][1]);
    //     }
    //     dp[i][1]=m+1;
    //     ans=max(ans,dp[i][0]+dp[i][1]);
    // }
    for(int i=0;i<n;i++){
        m1=0;m2=0;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]) m1=max(m1,dp[j][0]);
        }
        dp[i][0]=m1+1;
        for(int j=n-i;j<n;j++){
            if(arr[n-i-1]>arr[j]) m2=max(m2,dp[j][1]);
        }
        dp[n-i-1][1]=m2+1;
    }
    for(int i=0;i<n;i++) ans=max(ans,dp[i][0]+dp[i][1]);
    ans--;
    cout<<ans<<endl;
    // for(int i=0;i<n;i++) cout<<dp[i][0]<<" ";
    // cout<<endl;
    // for(int i=0;i<n;i++) cout<<dp[i][1]<<" ";
    // cout<<endl;
    return 0;
}