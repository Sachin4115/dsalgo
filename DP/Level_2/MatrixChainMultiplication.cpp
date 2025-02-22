#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>arr = {10,20,30,40,50,60};
    int n=arr.size();
    vector<vector<int>>dp(n-1,vector<int>(n-1,0));
    for(int g=0;g<n-1;g++){
        for(int i=0,j=g;j<n-1;i++,j++){
            if(g==0) dp[i][j]=0;
            else if(g==1) dp[i][j]=arr[i]*arr[j]*arr[j+1];
            else{
                int a=INT_MAX;
                for(int k=i;k<j;k++){
                    int l=dp[i][k];
                    int r=dp[k+1][j];
                    int m=arr[i]*arr[k+1]*arr[j+1];
                    a=min(a,l+r+m);
                }
                dp[i][j]=a;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    cout<<dp[0][n-2];
    return 0;
}