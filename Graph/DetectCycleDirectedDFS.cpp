#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool fun(vector<vector<int>> &adj, vector<bool> &v1, vector<bool> &v2,int c){
    v1[c]=1;v2[c]=1;
    for(int i : adj[c]){
        if(!v1[i]){
            if(fun(adj,v1,v2,i)) return true;
        }else if(v2[i]) return true;
    }
    v2[c]=0;
    return false;
}

bool isCyclicDFS(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool>vis1(n,0),vis2(n,0);
    for(int i=0;i<n;i++){
        if(!vis1[i])
            if(fun(adj,vis1,vis2,i)) return 1;
    }
    return 0;
}

int main()
{
    vector<vector<int>> arr= {{1},{2},{3},{3}};
    cout<<isCyclicDFS(arr);
    return 0;
}