// LeetCode 3393
// You are given a 2D integer array grid with size m x n. You are also given an integer k.

// Your task is to calculate the number of paths you can take from the top-left cell (0, 0) to the bottom-right cell (m - 1, n - 1) satisfying the following constraints:

// You can either move to the right or down. Formally, from the cell (i, j) you may move to the cell (i, j + 1) or to the cell (i + 1, j) if the target cell exists.
// The XOR of all the numbers on the path must be equal to k.
// Return the total number of such paths.

// Since the answer can be very large, return the result modulo 109 + 7.

// Constraints
// 1 <= m == grid.length <= 300
// 1 <= n == grid[r].length <= 300
// 0 <= grid[r][c] < 16
// 0 <= k < 16

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M = 1000000007;

    int countPathsWithXorValue(vector<vector<int>>& arr, int k) {
        int n = arr.size(), m = arr[0].size();
        vector<vector<vector<int>>> dp (n, vector<vector<int>> (m, vector<int> (16,0)));
        dp[0][0][arr[0][0]]=1;
        for(int i=1;i<n;i++)
            for(int l=0;l<16;l++)
                dp[i][0][l] = dp[i-1][0][arr[i][0]^l];
        for(int i=1;i<m;i++)
            for(int l=0;l<16;l++)
                dp[0][i][l] = dp[0][i-1][arr[0][i]^l];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                for(int l=0;l<16;l++){
                    dp[i][j][l] = (dp[i][j-1][arr[i][j]^l] + dp[i-1][j][arr[i][j]^l])%M;
                }
            }
        }
        return dp[n-1][m-1][k];
    }
};