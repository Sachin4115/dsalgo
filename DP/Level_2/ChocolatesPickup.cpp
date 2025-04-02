#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> arr = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    int n = arr.size(), m = arr[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            dp[n-1][i][j]=arr[n-1][i]+arr[n-1][j];
        }
    }
    for(int r=n-2;r>=0;r--){
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){

                for(int q=-1;q<=1;q++){
                    for(int w=-1;w<=1;w++){
                        int c1 = i+q, c2 = j+w;
                        if(c1>=0&&c2>=0&&c1<m&&c2<m){
                            dp[r][i][j]=max(dp[r][i][j],arr[r][i]+arr[r][j]+dp[r+1][c1][c2]);
                        }
                    }
                }

            }
        }
    }
    cout << dp[0][0][m-1];
    return 0;
}