#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& vis,vector<int>& st, int c){
    vis[c]=1;
    for(int i:adj[c]){
        if(!vis[i]){
            dfs(adj,vis,st,i);
        }
    }
    st.insert(st.begin(),c);
}

int main()
{
    vector<vector<int>> adj = {{}, {3}, {3}, {}, {0,1}, {0,2}};
    int n = adj.size();
    vector<bool> vis(n,0);
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adj,vis,ans,i);
        }
    }
    for(int i:ans) cout<<i<<" ";
    return 0;
}