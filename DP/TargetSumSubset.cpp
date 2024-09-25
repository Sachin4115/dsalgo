#include <iostream>
using namespace std;

int main()
{
    int arr[]={4,2,7,1,3};
    int n=5;
    int t=10;

    int dp[n+1][t+1];
    for(int i=0;i<=t;i++)
        dp[0][i]=0;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if(dp[i-1][j])
                dp[i][j]=1;
            else if(j-arr[i-1]>=0 && dp[i-1][j-arr[i-1]])
                dp[i][j]=1;
            else
                dp[i][j]=0;
        }
    }
    cout<<dp[n][t];

    return 0;
}