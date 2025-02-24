#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int>nodes = {1,2,7,9} ,freq = {3,1,2,1};
    int n=nodes.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    vector<int> sum(n);
    int q=0;
    for(int i=0;i<n;i++){
        q+=freq[i];
        sum[i]=q;
    }
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0) dp[i][j]=freq[i];
            else{
                int s=INT_MAX;
                for(int k=i;k<j;k++){
                    if(k==i){
                        s=min(s,dp[k+1][j]);
                    }else if(k==j){
                        s=min(s,dp[i][k-1]);
                    }else{
                        s=min(s,dp[i][k-1]+dp[k+1][j]);
                    }
                }
                s+=sum[j]-sum[i]+freq[i];
                dp[i][j]=s;
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}