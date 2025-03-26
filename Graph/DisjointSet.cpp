#include <iostream>
#include <vector>
using namespace std;

class disjointSet{
    public:
    vector<int>par;
    vector<int>rank;
    vector<int>size;
    disjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
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

int main()
{
    disjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findUPar(3)==ds.findUPar(7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    ds.unionByRank(3,7);
    if(ds.findUPar(3)==ds.findUPar(7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    disjointSet d(7);
    d.unionBySize(1,2);
    d.unionBySize(2,3);
    d.unionBySize(4,5);
    d.unionBySize(6,7);
    d.unionBySize(5,6);
    if(d.findUPar(3)==d.findUPar(7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    d.unionBySize(3,7);
    if(d.findUPar(3)==d.findUPar(7)) cout<<"Same"<<endl;
    else cout<<"Not Same"<<endl;
    return 0;
}