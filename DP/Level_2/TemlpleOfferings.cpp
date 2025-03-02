#include <iostream>
using namespace std;

int main()
{
    int arr[]={1, 4, 3, 6, 2, 1};
    int N= 6;
    int dp[2][N];
    dp[0][0]=1;
    dp[1][N-1]=1;
    int ans=0;
    for(int i=1;i<N;i++){
        if(arr[i]>arr[i-1]) dp[0][i]=dp[0][i-1]+1;
        else dp[0][i]=1;
    }
    for(int i=N-2;i>=0;i--){
        if(arr[i]>arr[i+1]) dp[1][i]=dp[1][i+1]+1;
        else dp[1][i]=1;
    }
    for(int i=0;i<N;i++) ans+=max(dp[0][i],dp[1][i]);
    cout<<ans;
    return 0;
}