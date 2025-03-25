#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int>d(V,1e8);
    d[src]=0;
    for(int i=1;i<V;i++){
        for(vector<int> v:edges){
            if(d[v[0]]!=1e8 && d[v[1]]>d[v[0]]+v[2]) d[v[1]]=d[v[0]]+v[2];
        }
    }
    for(vector<int> v:edges)
            if(d[v[0]]!=1e8 && d[v[1]]>d[v[0]]+v[2]) return {-1};
    return d;
}

int main()
{
    int V = 3;
    int src = 2;
    vector<vector<int>> edges = {{0,1,5}, {1,0,3}, {1,2,-1}, {2,0,1}};
    vector<int> ans = bellmanFord(V,edges,src);
    for(int i : ans) cout<<i<<" ";
    return 0;
}