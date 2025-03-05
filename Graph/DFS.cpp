#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>&visited, int i, vector<int> &ans){
    for(int w:adj[i]){
        if(!visited[w]){
            visited[w]=1;
            ans.push_back(w);
            dfs(adj,visited,w,ans);
        }
    }
}

int main()
{
    int v = 5, e = 4;
    vector<vector<int>> adj = {{2,3,1}, {0}, {0,4}, {0}, {2}};
    int n = adj.size();
    queue<int>q;
    vector<bool>visited(n,0);
    vector<int> ans;
    // for(int i=0;i<n;i++){  //To traverse all non connected components
    //     if(!visited[i]){
                int n=adj.size();
                vector<bool>visited(n,0);
                vector<int>ans;
                visited[0]=1;
                ans.push_back(0);
                dfs(adj,visited,0,ans);
        // }
    // }
    for(int i:ans) cout<<i<<" ";
    return 0;
}