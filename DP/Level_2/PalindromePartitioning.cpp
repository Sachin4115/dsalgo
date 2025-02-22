#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    vector<vector<bool>> a(n,vector<bool>(n,false));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0) a[i][j]=true;
            else if (g==1) a[i][j]=(s[i]==s[j]);
            else a[i][j]=a[i+1][j-1]&&(s[i]==s[j]);
        }
    }

    // N^3 Complexity

    // vector<vector<int>> dp(n,vector<int>(n,0));
    // for(int g=0;g<n;g++){
    //     for(int i=0,j=g;j<n;i++,j++){
    //         if(g==0) dp[i][j]=0;
    //         else if (g==1) dp[i][j]=s[i]!=s[j];
    //         else{
    //             if(a[i][j]) continue;
    //             dp[i][j]=INT_MAX;
    //             for(int k=i;k<j;k++){
    //                 dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+1);
    //             }
    //         }
    //     }
    // }
    // cout<<dp[0][n-1];

    // N^2 Complexity
    vector<int>dp(n,0);
    for(int i=0;i<n;i++){
        if(a[0][i]) continue;
        int q=INT_MAX;
        for(int j=i;j>=0;j--){
            if(a[j][i]) q=min(q,dp[j-1]+1);
        }
        dp[i]=q;
    }
    cout<<dp[n-1];

    return 0;
}