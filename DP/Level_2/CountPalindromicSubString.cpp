#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length(),ans=0;
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    for(int i=0;i<n;i++) dp[i][i]=1;
    for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) dp[i][i+1]=1;
    for(int i=n-2;i>=0;i--){
        for(int j=i+2;j<n;j++){
            if(s[i]==s[j] && dp[i+1][j-1]) dp[i][j]=1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]) ans++;
        }
    }
    cout<<ans<<endl;
    int count=0;
    vector<vector<bool>>arr(n,vector<bool>(n,false));
    for(int gap=0;gap<n;gap++){
        for(int start=0,end=gap;end<n;start++,end++){
            if(gap==0) arr[start][end]=1;
            else if(gap==1) arr[start][end]=(s[start]==s[end]);
            else if(s[start]==s[end]) arr[start][end]=arr[start+1][end-1];
            if(arr[start][end]) count++;
        }
    }
    cout<<count<<endl;

    return 0;
}