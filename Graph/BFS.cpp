#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
            q.push(0);
            visited[0]=1;
            while(q.size()){
                int c=q.front();
                q.pop();
                ans.push_back(c);
                for(int w:adj[c]) if(!visited[w]){ q.push(w);visited[w]=1;}
            }
        // }
    // }
    for(int i:ans) cout<<i<<" ";
    return 0;
}