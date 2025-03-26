#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class disjointSet{
    public:
    vector<int>par;
    vector<int>rank;
    vector<int>size;
    disjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int findUPar(int n){
        if(n==par[n]) return n;
        return par[n]=findUPar(par[n]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(rank[ulp_u]<rank[ulp_v]) par[ulp_u]=ulp_v;
        else if(rank[ulp_u]>rank[ulp_v]) par[ulp_v]=ulp_u;
        else{
            par[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(size[ulp_u]<size[ulp_v]){
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            par[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int mst(int n, vector<vector<int>> adj[]) {
    int ans=0;
    vector<vector<int>>e;
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            if(i<adj[i][j][0]) e.push_back({adj[i][j][1],i,adj[i][j][0]});
        }
    }
    sort(e.begin(),e.end());
    disjointSet ds(n);
    for(vector<int>a:e){
        int w = a[0];
        int n1=a[1];
        int n2=a[2];
        if(ds.findUPar(n1)==ds.findUPar(n2)) continue;
        ds.unionByRank(n1,n2);
        ans+=w;
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