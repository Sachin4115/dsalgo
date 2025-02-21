#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1,5,8,9,10,17,17,20};
    arr.insert(arr.begin(),0);
    int n=arr.size();
    vector<int>dp(n,0);
    for(int i=1;i<n;i++){
        dp[i]=arr[i];
        for(int j=i-1;j>=1;j--){
            dp[i]=max(dp[i],dp[j]+arr[i-j]);
        }
    }
    cout<<dp[n-1];
    return 0;
}