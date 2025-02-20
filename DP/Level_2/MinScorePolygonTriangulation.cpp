#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr= {1,3,1,4,1,5};
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0 || g==1) dp[i][j]=0;
            else if(g==2) dp[i][j]=arr[i]*arr[i+1]*arr[j];
            else{
                int a=INT_MAX;
                for(int k=i+1;k<j;k++){
                    a=min(a,arr[i]*arr[j]*arr[k]+dp[i][k]+dp[k][j]);
                }
                dp[i][j]=a;
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}