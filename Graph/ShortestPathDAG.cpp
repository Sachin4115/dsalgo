#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(int n, int E, vector<vector<int>>& e) {
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<E;i++) adj[e[i][0]].push_back({e[i][1],e[i][2]});
    int vis[n]={0};
    for(auto a:adj){
        for(auto i : a){
            vis[i.first]++;
        }
    }
    queue<int>q;
    vector<int> ts;
    for(int i=0;i<n;i++) if(vis[i]==0) q.push(i);
    while(q.size()){
        int c = q.front();
        q.pop();
        ts.push_back(c);
        for(auto i : adj[c]){
            vis[i.first]--;
            if(vis[i.first]==0) q.push(i.first);
        }
    }
    vector<int> ans(n,INT_MAX);
    ans[0]=0;
    for(int i:ts){
        if(ans[i]==INT_MAX) continue;
        for(auto a : adj[i]){
            int v = a.first;
            int w = a.second;
            if(w+ans[i]<ans[v]) ans[v]=w+ans[i];
        }
    }
    for(int i=0;i<n;i++) if(ans[i]==INT_MAX) ans[i]=-1;
    return ans;
}

int main()
{
    int n = 10, E = 24;
    vector<vector<int>> e ={{0,2,6},{0,3,7},{0,4,9},{0,6,8},{0,7,6},{1,2,6},{1,3,7},{1,5,10},{1,6,1},
                            {1,7,4},{2,3,3},{2,6,10},{2,8,8},{2,9,10},{3,5,3},{3,6,10},{3,7,5},{5,6,9},
                            {5,7,7},{6,7,7},{6,8,8},{6,9,8},{7,9,1},{8,9,6}};
    vector<int> ans = shortestPath(n,E,e);
    for(int i:ans) cout<<i<<" ";
    return 0;
}