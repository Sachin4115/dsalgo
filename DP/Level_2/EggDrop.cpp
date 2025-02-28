#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>dp(k+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) dp[1][i]=i;
    for(int i=1;i<=k;i++) dp[i][1]=1;
    for(int i=2;i<=k;i++){
        for(int j=2;j<=n;j++){
            // int ans=INT_MAX;
            // for(int q=1;q<=j;q++){
            //     ans=min(ans,max(dp[i-1][q-1],dp[i][j-q])+1);
            // }
            // dp[i][j]=ans;

            // Optimization from O(k*n*n) to O(k*n*log n)
            int l=1,h=j,ans=INT_MAX;
            while(l<=h){
                int m = l+(h-l)/2;
                int a=dp[i-1][m-1],b=dp[i][j-m];
                ans=min(ans,max(a,b)+1);
                if(a>b) h=m-1;
                else l=m+1;
            }
            dp[i][j]=ans;
        }
    }
    cout<<dp[k][n];
    return 0;
}