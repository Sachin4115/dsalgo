#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int count=0;
    /*

                                    count( prefix + mainString + suffix )
                                        /                       \
                                       /                         \
                                      /                           \
                                     /                             \
                                    /                               \
                                prefix == suffix                prefix != suffix
                                        |                              |
                                        |                              |
count(prefix+mainString)+count(mainString+suffix)+1       count(prefix+mainString)+count(mainString+suffix)-count(mainString)
    */
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int gap=0;gap<n;gap++){
        for(int start=0,end=gap;end<n;start++,end++){
            if(gap==0) dp[start][end]=1;
            else if(gap==1) {
                if(s[start]==s[end]) dp[start][end]=3;
                else dp[start][end]=2;
            }
            else if(s[start]==s[end]) dp[start][end]=1+dp[start][end-1]+dp[start+1][end];
            else dp[start][end]=dp[start][end-1]+dp[start+1][end]-dp[start+1][end-1];
        }
    }
    for(auto a:dp){
        for(auto q:a){
            cout<<q<<" ";
        }
        cout<<endl;
    }
    cout<<dp[0][n-1];
    return 0;
}