#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class hold{
    public:
    int curr;
    vector<bool> vis;
    hold(int in, vector<bool> b){
        curr=in;
        vis=b;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<vector<int>> arr(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        }
        vector<bool> b(n,0);
        queue<hold*> q;
        q.push(new hold(k,b));
        int ans=0;
        while(q.size()){
            hold* c = q.front();
            q.pop();
            int curr = c->curr;
            vector<bool> vis = c->vis;
            int ne=-1, ns=-1;
            for(int i=0;i<n;i++){
                if(vis[i]) continue;
                if(curr<=arr[i][1] && curr>=arr[i][0] && curr<arr[i][2]){
                    // vis[i]=1;
                    // q.push(new hold(arr[i][2],vis));
                    if(ns<arr[i][2]){
                        ns=arr[i][2];
                        ne=i;
                    }
                }
            }
            if(ne!=-1)
                {
                    vis[ne]=1;
                q.push(new hold(arr[ne][2],vis));
                }
            ans=max(ans,curr);
        }
        cout<<"           "<<ans<<endl;
    }
    return 0;
}