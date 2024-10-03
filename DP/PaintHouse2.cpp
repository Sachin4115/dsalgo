#include <iostream>
using namespace std;

int main()
{
    int n=4,c=6;
    int arr[n][c]={
        {1,5,7,2,3,4},
        {5,8,4,3,6,1},
        {3,2,9,7,2,3},
        {1,2,4,9,1,7}
    };
    int dp[n][c];
    int m1=INT_MAX,m2=INT_MAX;
    for(int i=0;i<c;i++){
        dp[0][i]=arr[0][i];
        if(dp[0][i]<=m1){
            m2=m1;
            m1=dp[0][i];
        }else if(dp[0][i]<m2){
            m2=dp[0][i];
        }
    }

    for(int i=1;i<n;i++){
        int a=INT_MAX,b=INT_MAX;
        for(int j=0;j<c;j++){
            if(dp[i-1][j]==m1)
                dp[i][j]=m2+arr[i][j];
            else
                dp[i][j]=m1+arr[i][j];
            if(dp[i][j]<=a){
                b=a;
                a=dp[i][j];
            }else if(dp[i][j]<b){
                b=dp[i][j];
            }
        }
        m1=a;m2=b;
    }
    int ans=dp[n-1][0];
    for(int i=1;i<c;i++){
        ans=min(ans,dp[n-1][i]);
    }
    cout<<ans;

    return 0;
}