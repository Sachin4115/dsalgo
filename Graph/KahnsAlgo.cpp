#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector<vector<int>> adj = {{}, {3}, {3}, {}, {0,1}, {0,2}};
    int n = adj.size();
    vector<int> vis(n,0);
    for(auto a:adj){
        for(int i:a){
            vis[i]++;
        }
    }
    queue<int>q;
    vector<int>ans;
    for(int i=0;i<n;i++) if(vis[i]==0) q.push(i);
    while(q.size()){
        int c = q.front();
        q.pop();
        for(int i:adj[c]){
            vis[i]--;
            if(vis[i]==0) q.push(i);
        }
        ans.push_back(c);
    }
    for(int i:ans) cout<<i<<" ";
    return 0;
}