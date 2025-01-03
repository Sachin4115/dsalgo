#include <iostream>
#include <queue>
using namespace std;

class step{
    public:
    int i;
    int j;
    int rem;
    string ans;
    step(int a, int b, int c,string s){
        i=a;
        j=b;
        rem=c;
        ans=s;
    }
};

int main()
{
    int n=5,t=10;
    int arr[5] = {4,2,7,1,3};
    int dp[n+1][t+1];
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=t;i++) dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            if((j-arr[i-1]>=0 && dp[i-1][j-arr[i-1]]) || dp[i-1][j]) dp[i][j]=1;
            else dp[i][j]=0;
        }
    }
    cout<<dp[n][t]<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=t;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    queue <step*> q;
    q.push(new step(n,t,t,""));
    while(q.size()>0){
        step* s = q.front();
        q.pop();
        int r = s->i, c = s->j ;
        if(s->rem==0) {cout<<s->ans<<endl; continue;}
        if(r>0 && dp[r-1][c]) q.push(new step(r-1,c,s->rem,s->ans));
        if(r>0 && c-arr[r-1]>=0 && dp[r-1][c-arr[r-1]]) q.push(new step(r-1,c-arr[r-1],s->rem-arr[r-1],s->ans + to_string(arr[r-1]) + " "));
    }

    return 0;
}