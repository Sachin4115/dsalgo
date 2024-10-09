#include <iostream>
using namespace std;

int main()
{
    int n = 12;
    int arr[n] = {10,15,17,20,16,18,22,20,22,20,23,25};
    int f=3;
    // dp[i][0] - - - > last bought
    // dp[i][1] - - - > last sold
    // int dp[n][2];

    // dp[0][0] = -1*arr[0];
    // dp[0][1] = 0;

    // for(int i=1;i<n;i++){
    //     dp[i][0] = max(dp[i-1][0],dp[i-1][1]-arr[i]);
    //     dp[i][1] = max(dp[i-1][1],arr[i]+dp[i-1][0]-f);
    // }

    // cout<<dp[n-1][1];

    int lb = -1*arr[0];
    int ls = 0;

    for(int i=1;i<n;i++){
        int nlb = max(lb,ls-arr[i]);
        int nls = max(ls,arr[i]+lb-f);
        lb=nlb;
        ls=nls;
    }
    cout<<ls;
    return 0;
}

// Price       last Bought          last sold
// 10                  -10                 00
// 15                  -10                 02
// 17                  -10                 04
// 20                  -10                 07
// 16                  -09                 07
// 18                  -09                 07
// 22                  -09                 10
// 20                  -09                 10
// 22                  -09                 10
// 20                  -09                 10
// 23                  -09                 11
// 25                  -09                 13