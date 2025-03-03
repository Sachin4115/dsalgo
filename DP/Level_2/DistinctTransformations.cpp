#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s= "aaabbc", t = "abc";
    int n = s.length(), m = t.length();
    vector<vector<long>> dp(n+1,vector<long>(m+1,0));
    for(int i=0;i<=n;i++) dp[i][m]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(s[i]==t[j]){
                dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
            }else{
                dp[i][j]=dp[i+1][j];
            }
            dp[i][j]%=1000000007;
        }
    }
    cout<<dp[0][0];
    return 0;
}