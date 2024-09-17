#include <iostream>
using namespace std;

int count(int a[], int n, int dp[]){
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=a[i] && i+j<=n;j++){
            dp[i]+=dp[i+j];
        }
    }
    return dp[0];
}

int main()
{
    int a[] = {3,3,0,2,2,3};
    int n = 6;
    cout<<count(a,n,new int[n+1]{0});
    return 0;
}