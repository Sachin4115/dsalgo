#include <iostream>
#include <queue>
using namespace std;

class step{
    public:
    int i;
    int j;
    string ans;
    step(int a, int b, string s){
        i=a;j=b;ans=s;
    }
};

int main()
{
    int n=5;
    int w[n]={2,5,1,3,4}, p[n]={15,14,10,45,30}, W=7;
    int dp[n+1][W+1];
    dp[0][0]=0;
    for(int i=1;i<=n;i++) dp[i][0]=0;
    for(int i=1;i<=W;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            dp[i][j]=0;
            if(j>=w[i-1]) dp[i][j]=p[i-1]+dp[i-1][j-w[i-1]];
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
    }
    cout<<dp[n][W]<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    queue<step*> q;
    q.push(new step(n,W, " "));
    while(q.size()>0){
        step * s = q.front();
        q.pop();
        int r=s->i,c=s->j;
        if(dp[r][c]==0){
            cout<<s->ans<<"."<<endl;
            continue;
        }
        if(dp[r-1][c]==dp[r][c]) q.push(new step(r-1,c,s->ans));
        if(c>=w[r-1] && dp[r-1][c-w[r-1]]+p[r-1]==dp[r][c])
        q.push(new step(r-1,c-w[r-1],s->ans+"->("+to_string(p[r-1])+","+to_string(w[r-1])+")"));
    }
    return 0;
}