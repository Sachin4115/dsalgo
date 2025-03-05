#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>&visited, int i, int s){
    bool b = 0;
    for(int w:adj[i]){
        if(!visited[w]){
            visited[w]=1;
            b=b||dfs(adj,visited,w,i);
            if(b) return b;
        }else if(w!=s) return true;
    }
    return b;
}

bool isCycleDFS(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n,0);
    bool ans=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            ans=ans||dfs(adj,vis,i,-1);
            if(ans) return ans;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> adj = {{1}, {0,2,4}, {1,3}, {2,4}, {1,3}};
    cout<<isCycleDFS(adj);
    return 0;
}