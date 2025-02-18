#include <iostream>
using namespace std;

int main()
{
    int n=6;
    n-=2;
    int dp[n+1];
    dp[0]=1;dp[1]=1;
    for(int i=2;i<=n;i++){
    long long a=0;
        for(int j=0;j<i;j++){
            a+=dp[j]*dp[i-j-1];
        }
        dp[i]=a;
    }
    cout<<dp[n];
    return 0;
}