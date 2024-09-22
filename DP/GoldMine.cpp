#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> mine = {
        {0,1,4,2,8,2},
        {4,3,6,5,0,4},
        {1,2,4,1,4,6},
        {2,0,7,3,2,2},
        {3,1,5,9,2,4},
        {2,7,0,8,5,1}
    };

    vector<vector<int>> dp = mine;

    for(int i=1;i<mine[0].size();i++){
        for(int j=0;j<mine.size();j++){
            int m=INT_MIN;
            if(j==0){
                m=max(dp[j][i-1],dp[j+1][i-1]);
            }else if(j==mine.size()-1){
                m=max(dp[j][i-1],dp[j-1][i-1]);
            }else{
                m=max(dp[j][i-1],max(dp[j-1][i-1],dp[j+1][i-1]));
            }
            dp[j][i]+=m;
        }
    }
    int a=0;
    for(int i=0;i<mine.size();i++){
        a=max(a,dp[i][mine[0].size()-1]);
    }
    cout<<a;
    return 0;
}