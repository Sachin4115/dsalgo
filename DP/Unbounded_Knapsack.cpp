#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {15,14,10,45,30};
    vector<int> w = {2,5,1,3,4};
    int n = v.size(), W = 7;

    vector<int> dp(W+1,0);
    for(int i=1;i<=W;i++){
        for(int j=0;j<n;j++){
            int m = dp[i];
            if(i-w[j]>=0){
                m=max(m,dp[i-w[j]]+v[j]);
            }
            dp[i]=m;
        }
    }
    cout<<dp[W];
    return 0;
}