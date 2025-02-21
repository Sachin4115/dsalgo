#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length(),M=1000000007;
    vector<int> a(n,-1),b(n,-1);
    unordered_map<char,int> m;
    for(int i=0;i<n;i++){
        if(m.count(s[i])) b[i]=m[s[i]];
        m[s[i]]=i;
    }
    m.clear();
    for(int i=n-1;i>=0;i--){
        if(m.count(s[i])) a[i]=m[s[i]];
        m[s[i]]=i;
    }
    vector<vector<int>> dp (n,vector<int>(n,0));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            long long q=0;
            if(g==0) q=1;
            else if(g==1) q=2;
            else{
                if(s[i]!=s[j]) q=(static_cast<long long>(dp[i+1][j])+dp[i][j-1]-dp[i+1][j-1]+M)%M;
                else if(a[i]==j) q=((2LL*dp[i+1][j-1])%M+2)%M;
                else if(a[i]==b[j]) q=((2LL*dp[i+1][j-1])%M+1)%M;
                else {q=(2LL*dp[i+1][j-1]-dp[a[i]+1][b[j]-1]+M)%M;}
            }
            dp[i][j]=q%M;
        }
    }
    cout<<dp[0][n-1]%M;
    return 0;
}