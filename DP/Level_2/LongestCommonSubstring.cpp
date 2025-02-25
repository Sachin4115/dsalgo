#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int n=a.length(),m=b.length();
    vector<vector<int>>dp(n,vector<int>(m,0));
    int ans=0,end=0;
    for(int i=0;i<n;i++) {
        dp[i][0]=a[i]==b[0];
        if(dp[i][0]){
            ans=1;
            end=i;
        }
    }
    for(int i=0;i<m;i++) {
        dp[0][i]=a[0]==b[i];
        if(dp[0][i]){
            ans=1;
            end=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
            if(ans<dp[i][j]){
                ans=dp[i][j];
                end=i;
            }
        }
    }
    cout<<a.substr(end-ans+1,ans);
    return 0;
}