#include <iostream>
#include <vector>
using namespace std;

class disjointSet{
    public:
    vector<int>par;
    vector<int>rank;
    disjointSet(int n){
        par.resize(n);
        rank.resize(n,0);
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
};

int findNoOfPro(vector<vector<int>>& adj) {
    int n = adj.size();
    disjointSet ds(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i!=j && adj[i][j]==1) ds.unionByRank(i,j);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) if(ds.findUPar(i)==i) ans++;
    return ans;
}

int main()
{
    vector<vector<int>> adj = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    cout<<findNoOfPro(adj);
    return 0;
}