#include <iostream>
using namespace std;

int main()
{
    // n will always be even
    int n;
    cin>>n;
    int newN = n/2;
    int dp[newN+1];
    dp[0]=dp[1]=1;
    for(int i=2;i<=newN;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    cout<<dp[newN];
    return 0;
}