#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr={2,3,1,5,6,4};
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                if(i==0&&j==n-1) dp[i][j]=arr[i];
                else if(i==0) dp[i][j]=arr[i]*arr[i+1];
                else if(j==n-1) dp[i][j]=arr[j-1]*arr[j];
                else dp[i][j]=arr[i-1]*arr[i]*arr[i+1];
            }else{
                for(int k=i;k<=j;k++){
                    int l= k==i?0:dp[i][k-1];
                    int r= k==j?0:dp[k+1][j];
                    int v= (i==0?1:arr[i-1])*(arr[k])*(j==n-1?1:arr[j+1]);
                    dp[i][j]=max(dp[i][j],l+v+r);
                }
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}