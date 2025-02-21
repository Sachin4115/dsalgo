#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s,p;
    cin>>s>>p;
    int n = s.length(),m=p.length();
    vector<vector<int>> dp (m+1,vector<int>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<=m;i++) if(p[i-1]=='*') dp[i][0]=dp[i-2][0];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[i-1]=='.' || p[i-1]==s[j-1]) dp[i][j]=dp[i-1][j-1];
            else if(p[i-1]=='*'){
                dp[i][j]=dp[i-2][j];
                if(p[i-2]==s[j-1] || p[i-2]=='.') dp[i][j]=dp[i][j]||dp[i][j-1];
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[m][n];

    return 0;
}