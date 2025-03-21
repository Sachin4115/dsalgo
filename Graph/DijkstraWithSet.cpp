#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    vector<vector<pair<int, int>>> adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}} ;
    int src = 2;
    set<pair<int,int>> s;
    s.insert({0,src});
    vector<int> ans(adj.size(),INT_MAX);
    ans[src]=0;
    while(s.size()){
        pair<int,int>p=*s.begin();
        s.erase(p);
        int d = p.first;
        int n = p.second;
        for(auto a : adj[n]){
            if(d+a.second<ans[a.first]){
                if(ans[a.first]!=INT_MAX){
                    s.erase({ans[a.first],a.first});
                }
                ans[a.first]=d+a.second;
                s.insert({ans[a.first],a.first});
            }
        }
    }
    for(int i : ans) cout<<i<<" ";
    return 0;
}