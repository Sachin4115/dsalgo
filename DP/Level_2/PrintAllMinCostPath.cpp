#include <iostream>
#include <queue>
using namespace std;

class step{
    public:
    int i;
    int j;
    string pathSoFar;
    step(int i, int j, string s){
        this->i=i;
        this->j=j;
        pathSoFar=s;
    }
};

int main()
{
    int n = 5;
    int arr[n][n] = {
        {2,6,1,1,3},
        {9,1,1,0,5},
        {0,7,5,2,0},
        {4,3,0,4,7},
        {2,0,1,4,1}
    };
    int dp[n][n];
    dp[n-1][n-1]=arr[n-1][n-1];
    for(int i=n-2;i>=0;i--){
        dp[n-1][i]=dp[n-1][i+1]+arr[n-1][i];
        dp[i][n-1]=dp[i+1][n-1]+arr[i][n-1];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            dp[i][j]=min(dp[i+1][j],dp[i][j+1])+arr[i][j];
        }
    }
    cout<<dp[0][0]<<endl;
    queue<step*> q;
    q.push(new step(0,0,"(0,0)"));
    while(q.size()>0){
        step* s = q.front();
        q.pop();
        if(s->i==n-1 && s->j==n-1) cout<<s->pathSoFar<<"."<<endl;
        else if(s->i==n-1) q.push(new step(s->i,s->j+1,s->pathSoFar + "-> (" + to_string(s->i) + "," + to_string(s->j+1) + ")"));
        else if(s->j==n-1) q.push(new step(s->i+1,s->j,s->pathSoFar + "-> (" + to_string(s->i+1) + "," + to_string(s->j) + ")"));
        else{
            int a = dp[s->i][s->j+1];
            int b = dp[s->i+1][s->j];
            int m = min(a,b);
            if(a==m) q.push(new step(s->i,s->j+1,s->pathSoFar + "-> (" + to_string(s->i) + "," + to_string(s->j+1) + ")"));
            if(b==m) q.push(new step(s->i+1,s->j,s->pathSoFar + "-> (" + to_string(s->i+1) + "," + to_string(s->j) + ")"));
        }
    }
    return 0;
}