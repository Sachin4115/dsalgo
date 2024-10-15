#include <iostream>
#include<unordered_map>
using namespace std;

int main()
{
    int m = 20, n = 5, k = 3;
    int Billboard[n] = {6,8,12,14,16};
    int Revenue[n] = {5,8,5,3,1};
    int dp[m+1];
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++)
        mp[Billboard[i]]=Revenue[i];
    dp[0]=0;
    for(int i = 1; i <= m; i++){
        if(mp.find(i)==mp.end()){
            dp[i]=dp[i-1];
        }else{
            int a = mp[i];
            if(i>=k+1)
                a+=dp[i-k-1];
            dp[i]=max(dp[i-1],a);
        }
    }
    cout<<dp[m];
    return 0;
}