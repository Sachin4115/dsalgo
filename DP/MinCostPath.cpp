#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp = grid;
    int n=dp.size()-1,m=dp[0].size()-1;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n && j==m)
                    continue;
                else if(i==n){
                    dp[i][j]=dp[i][j+1]+dp[i][j];
                }else if(j==m){
                    dp[i][j]=dp[i+1][j]+dp[i][j];
                }else{
                    dp[i][j]=min(dp[i][j+1],dp[i+1][j])+dp[i][j];
                }
            }
        }
        return dp[0][0];
}

int main()
{
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid);
    return 0;
}