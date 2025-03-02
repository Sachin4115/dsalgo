#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s1,s2;
    int c1,c2;
    cin>>s1>>s2>>c1>>c2;
    int n=s1.length(),m=s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            if(s1[i]==s2[j]) dp[i][j]=dp[i+1][j+1]+1;
            else dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
    cout<<(c1*(s1.length()-dp[0][0]))+(c2*(s2.length()-dp[0][0]));
    return 0;
}