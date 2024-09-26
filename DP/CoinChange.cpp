#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> coins={2,3,5,6};
    int t=10,n=coins.size();
    vector<int> dp(t+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=t;j++){
            if(j-coins[i]>=0)
                dp[j]+=dp[j-coins[i]];
        }
    }
    cout<<dp[t];
    return 0;
}