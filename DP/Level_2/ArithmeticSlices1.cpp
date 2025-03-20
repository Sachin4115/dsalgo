#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {2,3,9,12,15,18,22,26,30,34,36,38,40,41};
    int n = arr.size();
    int ans=0;
    vector<int> dp(n,0);
    for(int i=2;i<n;i++){
        if(arr[i]-arr[i-1]==arr[i-1]-arr[i-2]) dp[i]=dp[i-1]+1;
        ans+=dp[i];
    }
    cout<<ans;
    return 0;
}