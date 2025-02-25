#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> data = {
      {0,8},
      {1,2,4},
      {2,1,3,5},
      {3,2,6},
      {4,1,5,7},
      {5,2,4,6,8},
      {6,3,5,9},
      {7,4,8},
      {8,7,5,9,0},
      {9,8,6},
    };
    vector<vector<int>> dp(n,vector<int>(10,1));
    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            int s=0;
            for(int k:data[j]){
                s+=dp[i-1][k];
            }
            dp[i][j]=s;
        }
    }
    int ans=0;
    for(int i=0;i<10;i++) ans+=dp[n-1][i];
    cout<<ans;
    return 0;
}