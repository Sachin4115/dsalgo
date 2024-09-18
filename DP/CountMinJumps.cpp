#include <iostream>
using namespace std;

int count(int a[], int n, int dp[]){

    dp[n]=0;
    for(int i=n-1;i>=0;i--){
            int m = INT_MAX;
            for(int j=1;j<=a[i] && i+j<=n;j++){
                if(dp[i+j]!=-1)
                    m=min(m,dp[i+j]);
            }
            if(m!=INT_MAX)
                dp[i]=m+1;
            else
                dp[i]=-1;
    }
    return dp[0];
}

int main()
{
    int a[] = {1,1,1,4,9,8,1,1,10,1};
    int n = 10;
    cout<<count(a,n,new int[n+1]);
    return 0;
}