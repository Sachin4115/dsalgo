#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s,p;
    cin>>s>>p;
    int n = s.length(),m=p.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=m;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(s[i-1]==p[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout<<dp[n][m];
    return 0;
}