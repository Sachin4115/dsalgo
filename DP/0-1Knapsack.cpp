#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {15,14,10,45,30};
    vector<int> w = {2,5,1,3,4};
    int n = v.size(), W = 7;

    vector<vector<int>> dp(n+1,vector<int> (W+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j>=w[i-1]){
                dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    cout<<dp[n][W];

    return 0;
}