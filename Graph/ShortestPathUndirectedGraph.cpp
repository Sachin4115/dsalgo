#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int src=0;
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    queue<int>q;
    q.push(src);
    vector<int>ans(adj.size(),INT_MAX);
    ans[src]=0;
    while(q.size()){
        int p = q.front();
        q.pop();
        for(int i:adj[p]){
            if(ans[i]>ans[p]+1) {ans[i]=ans[p]+1;q.push(i);}
        }
    }
    for(int i=0;i<adj.size();i++) if(ans[i]==INT_MAX) ans[i]=-1;
    for(int i:ans) cout<<i<<" ";
    return 0;
}