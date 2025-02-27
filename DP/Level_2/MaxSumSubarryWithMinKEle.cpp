#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    long long int a[n];
    long long int ans;
    long long int dp[n];
    long long int sum=0,w=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
        w+=a[i];
        if(sum<0) sum=0;
        dp[i]=sum;
    }
    ans=w;
    for(int i=k;i<n;i++){
        w+=a[i];
        sum+=a[i];
        w-=a[i-k];
        if(sum<0) sum=0;
        dp[i]=sum;
        ans=max(ans,w+dp[i-k]);
    }
    cout<<ans;
    return 0;
}