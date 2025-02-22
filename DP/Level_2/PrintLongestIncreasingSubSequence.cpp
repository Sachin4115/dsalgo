#include <iostream>
#include <queue>
using namespace std;

class step{
    public:
    int i;
    int l;
    string ans;
    step(int a,int b, string s){
        i=a;
        l=b;
        ans=s;
    }
};

int main()
{
    int n=10,ans=1;
    int arr[n] = {10,22,9,33,21,50,41,60,80,79};
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        int m=0;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]) m=max(m,dp[j]);
        }
        dp[i]=m+1;
        ans=max(ans,dp[i]);
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<ans<<endl;
    queue<step*>q;
    for(int i=0;i<n;i++){
        q.push(new step(i,ans-1,to_string(arr[i])));
    }
    while(q.size()>0){
        step* s = q.front();
        q.pop();
        if(s->l==0){
            cout<<s->ans<<endl;
            continue;;
        }
        for(int i=s->i-1;i>=0;i--){
            if(dp[i]==s->l && arr[i]<arr[s->i]){
                q.push(new step(i,s->l-1,to_string(arr[i])+"->"+s->ans));
            }
        }
    }
    return 0;
}