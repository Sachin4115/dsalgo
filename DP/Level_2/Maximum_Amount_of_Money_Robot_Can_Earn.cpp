// You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach
// the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.

// The grid contains a value coins[i][j] in each cell:

// If coins[i][j] >= 0, the robot gains that many coins.
// If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i]
// [j] coins.
// The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them
// from stealing coins in those cells.

// Note: The robot's total coins can be negative.

// Return the maximum profit the robot can gain on the route.


#include<iostream>
#include<vector>
using namespace std;

int maximumAmount(vector<vector<int>>& arr) {
    int n = arr.size(), m=arr[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int> (3,0)));
    dp[0][0][0] = arr[0][0];
    if(arr[0][0]<0) dp[0][0][1] = 0;
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0];
        dp[i][0][0]+=arr[i][0];
        dp[i][0][1]+=arr[i][0];
        dp[i][0][2]+=arr[i][0];
        if(arr[i][0]<0){
            dp[i][0][1]=max(dp[i-1][0][0],dp[i-1][0][1]+arr[i][0]);
            dp[i][0][2]=max(dp[i-1][0][1],dp[i-1][0][2]+arr[i][0]);
        }
    }
    for(int i=1;i<m;i++){
        dp[0][i]=dp[0][i-1];
        dp[0][i][0]+=arr[0][i];
        dp[0][i][1]+=arr[0][i];
        dp[0][i][2]+=arr[0][i];
        if(arr[0][i]<0){
            dp[0][i][1]=max(dp[0][i-1][0],dp[0][i-1][1]+arr[0][i]);
            dp[0][i][2]=max(dp[0][i-1][1],dp[0][i-1][1]+arr[0][i]);
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j][0]=max(dp[i-1][j][0],dp[i][j-1][0])+arr[i][j];
            if(arr[i][j]>=0){
                dp[i][j][1]=max(dp[i-1][j][1],dp[i][j-1][1])+arr[i][j];
                dp[i][j][2]=max(dp[i-1][j][2],dp[i][j-1][2])+arr[i][j];
            }
            else{
                int a=max(dp[i-1][j][1],dp[i][j-1][1]);
                dp[i][j][1] = max(a+arr[i][j],max(dp[i-1][j][0],dp[i][j-1][0]));
                a=max(dp[i-1][j][2],dp[i][j-1][2]);
                dp[i][j][2] = max(a+arr[i][j],max(dp[i-1][j][1],dp[i][j-1][1]));
            }
        }
    }
    return max(dp[n-1][m-1][0],max(dp[n-1][m-1][1],dp[n-1][m-1][2]));
}