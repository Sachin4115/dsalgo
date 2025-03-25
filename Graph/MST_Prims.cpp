#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int mst(int n, vector<vector<int>> adj[]) {
    vector<bool>v(n,0);
    priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> q;
    q.push({0,0,-1});
    int ans=0;
    while(q.size()){
        vector<int> c=q.top();
        q.pop();
        if(v[c[1]]) continue;
        v[c[1]]=1;
        ans+=c[0];
        for(int i=0;i<adj[c[1]].size();i++){
            int ng = adj[c[1]][i][0];
            int w = adj[c[1]][i][1];
            if(!v[ng]){
                q.push({w,ng,c[1]});
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> adj[] = {
        {{3,9},{4,2},{5,2}},
        {{3,5}},
        {{3,10}},
        {{0,9},{1,5},{2,10}},
        {{0,2}},
        {{0,2}}
    };
    int n = 6;
    cout<<mst(n,adj);
    return 0;
}