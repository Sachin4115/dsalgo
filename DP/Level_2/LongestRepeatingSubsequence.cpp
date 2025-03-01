#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    vector<vector<int>> dp (n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i!=j  && s[i]==s[j]) dp[i][j]=dp[i+1][j+1]+1;
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    cout<<dp[0][0];
    return 0;
}