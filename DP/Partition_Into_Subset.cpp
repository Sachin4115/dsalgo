#include <iostream>
using namespace std;

// Devide n friends into k groups

int main()
{
    int n=6,k=4;
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=1;i<=k;i++)
        dp[0][i]=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = (dp[i-1][j]*j)+dp[i-1][j-1];
        }
    }
    cout<<dp[n][k];
    return 0;
}