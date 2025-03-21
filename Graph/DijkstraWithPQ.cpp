#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector<vector<pair<int, int>>> adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}} ;
    int src = 2;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    vector<int> ans(adj.size(),INT_MAX);
    ans[src]=0;
    while(pq.size()){
        pair<int,int>p=pq.top();
        pq.pop();
        int d = p.first;
        int n = p.second;
        for(auto a : adj[n]){
            if(d+a.second<ans[a.first]){
                ans[a.first]=d+a.second;
                pq.push({ans[a.first],a.first});
            }
        }
    }
    for(int i : ans) cout<<i<<" ";
    return 0;
}