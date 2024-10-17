#include <iostream>
using namespace std;

int main()
{
    int n=5,m=6;
    int arr[n][m] = {
        {0,1,0,1,0,1},
        {1,0,1,0,1,0},
        {0,1,1,1,1,0},
        {0,0,1,1,1,0},
        {1,0,1,1,1,1}
    };

    int dp[n][m],a=0;
    for(int i=0;i<n;i++)
        dp[i][m-1]=arr[i][m-1];
    for(int i=0;i<m;i++)
        dp[n-1][i]=arr[n-1][i];
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(arr[i][j]==0){
                dp[i][j]=0;
            }else{
                dp[i][j]=min(dp[i+1][j+1],min(dp[i+1][j],dp[i][j+1]));
                dp[i][j]++;
                a=max(a,dp[i][j]);
            }
        }
    }
    cout<<a;
    return 0;
}