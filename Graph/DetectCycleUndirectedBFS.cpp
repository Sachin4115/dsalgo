#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCycleBFS(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool>vis(n,0);
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            q.push({i,-1});
            vis[i]=1;
            while(q.size()){
                pair<int,int>p=q.front();
                q.pop();
                int a=p.first,b=p.second;
                for(int w:adj[a]){
                    if(!vis[w]) {q.push({w,a});vis[w]=1;}
                    else if(w!=b) return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> adj = {{1}, {0,2,4}, {1,3}, {2,4}, {1,3}};
    cout<<isCycleBFS(adj);
    return 0;
}