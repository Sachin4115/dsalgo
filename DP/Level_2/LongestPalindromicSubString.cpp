#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    vector<int> ans = {0,0};
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0) dp[i][j]=1;
            else if(g==1) dp[i][j]=(s[i]==s[j]);
            else if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
            if(dp[i][j] && j-i > ans[1]-ans[0]){
                ans[0]=i;
                ans[1]=j;
            }
        }
    }
    cout<<s.substr(ans[0],ans[1]-ans[0]+1);
    return 0;
}