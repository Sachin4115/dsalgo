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
        for(int i=0;i<n;i++) par[i]=i;
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

int main()
{
    int n=4,m=5;
    int r,c;
    vector<int> ans;
    int c=0;
    int t = 12;
    vector<bool>vis(n*m,0);
    disjointSet ds(n*m);
    while(t--){
        cin>>r>>c;
        int in = (r*m)+c;
        if(vis[in]) {
            ans.push_back(c);
            continue;
        }
        c++;
        vis[in]=1;
        if(r>0 && vis[in-m] && ds.findUPar(in)!=ds.findUPar(in-m)){
            ds.unionByRank(in,in-m);
            c--;
        }
        if(r<n-1 && vis[in+m] && ds.findUPar(in)!=ds.findUPar(in+m)){
            ds.unionByRank(in,in+m);
            c--;
        }
        if(c>0 && vis[in-1] && ds.findUPar(in)!=ds.findUPar(in-1)){
            ds.unionByRank(in,in-1);
            c--;
        }
        if(c<m-1 && vis[in+1] && ds.findUPar(in)!=ds.findUPar(in+1)){
            ds.unionByRank(in,in+1);
            c--;
        }
        ans.push_back(c);
    }
    for(int i:ans) cout<<i<<" ";
    return 0;
}