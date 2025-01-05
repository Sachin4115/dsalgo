#include <iostream>
#include <queue>
using namespace std;

class step{
    public:
    int i;
    int left;
    string ans;
    step(int a, int b, string s){
        i=a;
        left=b;
        ans=s;
    }
};

int main()
{
    int n=12,ans=0;
    int arr[n] = {10,22,9,33,21,50,41,60,80,180,85,95};
    int dp[n];
    for(int i=0;i<n;i++){
        int m=0;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]) m=max(m,dp[j]);
        }
        dp[i]=m+arr[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    queue<step*> q;
    for(int i=0;i<n;i++){
        if(dp[i]==ans) q.push(new step(i,ans-arr[i],to_string(arr[i])));
    }
    while(q.size()>0){
        step* s = q.front();
        q.pop();
        int i=s->i;
        if(s->left==0){
            cout<<s->ans<<endl;
            continue;
        }
        for(int j=i-1;j>=0;j--){
            if(dp[j]==s->left && arr[i]>arr[j]) q.push(new step(j,s->left-arr[j],to_string(arr[j])+"->"+s->ans));
        }
    }
    return 0;
}