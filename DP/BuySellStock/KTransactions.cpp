#include <iostream>
using namespace std;

int main()
{
    int n = 12;
    int arr[n] = {10,15,17,20,16,18,22,20,22,20,23,25};
    int k=2;
    int dp[k+1][n];
    for(int i=0;i<n;i++)
        dp[0][i]=0;
    for(int i=0;i<=k;i++)
        dp[i][0]=0;
    // for(int i=1;i<=k;i++){
    //     for(int j=1;j<n;j++){
    //         dp[i][j]=dp[i][j-1];
    //         for(int l=0;l<=j;l++){
    //             dp[i][j]=max(dp[i][j],dp[i-1][l] + (arr[j]-arr[l])) ;
    //         }
    //     }
    // }
    // cout<<dp[k][n-1];

    // Optimization

    for(int i=1;i<=k;i++){
        int m = dp[i-1][0]-arr[0];
        for(int j=1;j<n;j++){
            dp[i][j]=max(dp[i][j-1],m+arr[j]);
            m = max(dp[i-1][j]-arr[j],m);
        }
    }
    cout<<dp[k][n-1];


    return 0;
}