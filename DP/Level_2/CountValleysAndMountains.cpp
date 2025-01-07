#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        int m=0;
        for(int j=0;j<i;j++){
            m+=dp[j]*dp[i-j-1];
        }
        dp[i]=m;
    }
    cout<<dp[n]<<endl;
    return 0;
}