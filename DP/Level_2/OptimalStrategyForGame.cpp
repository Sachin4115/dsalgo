#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {20,30,2,2,2,10};
    int n=arr.size();
    vector<int>s(n,0);
    s[0]=arr[0];
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=1;i<n;i++) s[i]=s[i-1]+arr[i];
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0) dp[i][j]=arr[i];
            else if(g==1) dp[i][j]=max(arr[i],arr[j]);
            else dp[i][j]=max(arr[i]+s[j]-s[i]-dp[i+1][j],arr[j]+s[j-1]-s[i]+arr[i]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1];
    return 0;
}