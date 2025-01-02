#include <iostream>
#include <queue>
using namespace std;

class steps{
    public:
    int leftValue;
    int i;
    int j;
    string ans;
    steps( int b, int c, int d, string s){
        leftValue=b;
        i=c;
        j=d;
        ans=s;
    }
};
int main()
{
    int n=4;
    int arr[n][n] = {
        {3,2,5,1},
        {2,4,6,0},
        {5,0,1,3},
        {9,1,5,1}
    };
    int dp[n][n];
    for(int i=0;i<n;i++) dp[i][n-1]=arr[i][n-1];
    for(int i=n-2;i>=0;i--){
        dp[0][i]=max(dp[0][i+1],dp[1][i+1])+arr[0][i];
        for(int j=1;j<n-1;j++){
            dp[j][i]=max(dp[j][i+1],max(dp[j-1][i+1],dp[j+1][i+1]))+arr[j][i];
        }
        dp[n-1][i]=max(dp[n-1][i+1],dp[n-2][i+1])+arr[n-1][i];
    }
    int a=INT32_MIN;
    for(int i=0;i<n;i++) a=max(a,dp[i][0]);
    cout<<a<<endl;
    queue <steps*> q;
    for(int i=0;i<n;i++){
        if(dp[i][0]==a){
            q.push(new steps(a-arr[i][0],i,0,"("+to_string(i)+",0)"));
        }
    }
    while(q.size()>0){
        steps * s = q.front();
        q.pop();
        int r = s->i, c = s->j;
        if(c==n-1){
            cout<<s->ans<<"."<<endl;
            continue;
        }
        if(r!=0 && dp[r-1][c+1] == s->leftValue) q.push(new steps(s->leftValue-arr[r-1][c+1],r-1,c+1,s->ans+"->("+to_string(r-1)+","+to_string(c+1)+")"));
        if(dp[r][c+1] == s->leftValue) q.push(new steps(s->leftValue-arr[r][c+1],r,c+1,s->ans+"->("+to_string(r)+","+to_string(c+1)+")"));
        if(r!=n-1 && dp[r+1][c+1] == s->leftValue) q.push(new steps(s->leftValue-arr[r+1][c+1],r+1,c+1,s->ans+"->("+to_string(r+1)+","+to_string(c+1)+")"));
    }

    return 0;
}