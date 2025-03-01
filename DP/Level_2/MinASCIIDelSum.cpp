#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int n = a.length(), m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) dp[i][0]=dp[i-1][0]+(a[i-1]-'a'+97);
    for(int i=1;i<=m;i++) dp[0][i]=dp[0][i-1]+(b[i-1]-'a'+97);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j] = min((dp[i-1][j-1]+(a[i-1]-'a'+97)+(b[j-1]-'a'+97)),min(dp[i-1][j]+(a[i-1]-'a'+97),dp[i][j-1]+(b[j-1]-'a'+97)));
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n][m];
    return 0;
}