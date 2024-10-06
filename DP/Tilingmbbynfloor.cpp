#include <iostream>
using namespace std;

// tile m x 1
// floor n x m

int main()
{
    int n=3,m=3;
    int dp[n+1];
    for(int i=0;i<m && i<=n;i++)
        dp[i]=1;
    for(int i=m;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-m];
    cout<<dp[n];
    return 0;
}