#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> coins={2,3,5,6};
    int t=10,n=coins.size();
    vector<int> dp(t+1,0);
    dp[0]=1;
    for(int i=0;i<=t;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0)
                dp[i]+=dp[i-coins[j]];
        }
    }
    cout<<dp[t];
    return 0;
}