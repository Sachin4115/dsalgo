#include <iostream>
using namespace std;

int main()
{
    int n=11,m=0;
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        m=i;
        for(int j=1;j*j<=i;j++){
            m=min(m,dp[i-(j*j)]);
        }
        dp[i]=m+1;
    }
    cout<<dp[n]<<endl;
    for(int i=0;i<=n;i++) cout<<dp[i]<<" ";

    return 0;
}