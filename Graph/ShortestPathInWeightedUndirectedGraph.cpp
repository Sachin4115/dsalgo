#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n = 5;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};
    vector<vector<pair<int,int>>>adj(n+1);
    for(auto e : edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }
    set<pair<int,int>> s;
    vector<int>parent(n+1);
    for(int i=0;i<=n;i++) parent[i]=i;
    vector<int> dist(n+1,INT_MAX);
    dist[1]=0;
    s.insert({0,1});
    while(s.size()){
        pair<int,int>p=*s.begin();
        s.erase(p);
        int d = p.first;
        int n = p.second;
        for(auto a : adj[n]){
            if(dist[a.first]>d+a.second){
                if(dist[a.first]!=INT_MAX){
                    s.erase({dist[a.first],a.first});
                }
                dist[a.first]=d+a.second;
                s.insert({dist[a.first],a.first});
                parent[a.first]=n;
            }
        }
    }

    if(dist[n]==INT_MAX) return {-1};
    vector<int>ans={n};
    int q=parent[n];
    while(q!=1){
        ans.insert(ans.begin(),q);
        q=parent[q];
    }
    ans.insert(ans.begin(),q);
    ans.insert(ans.begin(),dist[n]);
    for(int i : ans) cout<<i<<" ";
    return 0;
}