#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n=0;
        cin>>n;
        vector<int> d(n);
        for(int i=0;i<n;i++) cin>>d[i];
        vector<vector<int>> s(n,vector<int>(2,0));
        for(int i=0;i<n;i++) cin>>s[i][0]>>s[i][1];
        vector<pair<int,int>> dp(n+1);
        bool f=0;
        dp[0]={0,0};
        for(int i=1;i<=n;i++){
            pair<int,int> p = dp[i-1];
            int a,b;
            if(d[i-1]==0){
                a=p.first;
                b=p.second;
            }else if(d[i-1]==1){
                a=p.first+1;
                b=p.second+1;
            }else{
                a=p.first;
                b=p.second+1;
            }
            a=max(a,s[i-1][0]);
            b=min(b,s[i-1][1]);
            // cout<<a<<" "<<b<<endl;

            if(a>b){
                f=1;
                break;
            }
            dp[i]={a,b};
            // cout<<a<<" "<<b<<endl;
        }
        if(f){
            cout<<"-1"<<endl;
            continue;
        }
        int ans[n];
        int c = dp[n].first;

        for(int i=n;i>=1;i--){
            pair<int,int> p = dp[i-1];

            if(d[i-1]==0){
                ans[i-1]=0;
            }else if(d[i-1]==1){
                ans[i-1]=1;
                c--;
            }else{
                if(c>=p.first && c<=p.second) ans[i-1]=0;
                else{
                    ans[i-1]=1;
                    c--;
                }
            }
        }
        if(c!=0){
            cout<<-2<<endl;
            continue;
        }
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}