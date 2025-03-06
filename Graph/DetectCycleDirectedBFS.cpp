#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclicBFS(vector<vector<int>> &adj) {
    int n = adj.size();
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        vector<bool>vis(n,0);
        q.push({i,-1});
        vis[i]=1;
        while(q.size()){
            pair<int,int> c = q.front();
            q.pop();
            for(int w:adj[c.first]){
                if(w==i) return 1;
                if(vis[w]) continue;
                q.push({w,c.first});
                vis[w]=1;
            }
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> arr= {{1},{2},{3},{3}};
    cout<<isCyclicBFS(arr);
    return 0;
}