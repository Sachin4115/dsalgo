#include <iostream>
#include <vector>
using namespace std;

// Google Onsite Question
// Given a positive integer n and 3 operations on n:
// 1. n - 1
// 2. n / 2 (if n is even)
// 3. n / 3 (if n % 3 == 0)
// Find the minimum number of above operations to reduce n to 1.

int main()
{
    int n;
    vector<int>dp(n,INT_MAX);
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<n;i++){
        dp[i]=dp[i-1]+1;
        if((i+1)%2==0) dp[i]=min(dp[i],dp[(i+1)/2]+1);
        if((i+1)%3==0) dp[i]=min(dp[i],dp[(i+1)/3]+1);
    }
    cout<<dp[n-1];
    return 0;
}